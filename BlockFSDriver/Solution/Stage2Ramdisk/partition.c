#include <linux/string.h>

#include "partition.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

#define SECTOR_SIZE 512
#define MBR_SIZE SECTOR_SIZE
#define MBR_DISK_SIGNATURE_OFFSET 440
#define MBR_DISK_SIGNATURE_SIZE 4
#define PARTITION_TABLE_OFFSET 446
#define PARTITION_ENTRY_SIZE 16 // sizeof(PartEntry)
#define PARTITION_TABLE_SIZE 64 // sizeof(PartTable)
#define MBR_SIGNATURE_OFFSET 510
#define MBR_SIGNATURE_SIZE 2
#define MBR_SIGNATURE 0xAA55
#define BR_SIZE SECTOR_SIZE
#define BR_SIGNATURE_OFFSET 510
#define BR_SIGNATURE_SIZE 2
#define BR_SIGNATURE 0xAA55
#define DISK_SIGNATURE 0x36E5756D

typedef struct
{
	unsigned char boot_type; // 0x00 - Inactive; 0x80 - Active (Bootable)
	unsigned char start_head;
	unsigned char start_sec:6;
	unsigned char start_cyl_hi:2;
	unsigned char start_cyl;
	unsigned char part_type;
	unsigned char end_head;
	unsigned char end_sec:6;
	unsigned char end_cyl_hi:2;
	unsigned char end_cyl;
	unsigned int abs_start_sec;
	unsigned int sec_in_part;
} PartEntry;

typedef PartEntry PartTable[4];

/*
Device Boot StartCHS    EndCHS        StartLBA     EndLBA    Sectors  Size Id Type
/dev/rb1    0,0,2       9,0,32               1        319        319  159K 83 Linux
/dev/rb2    10,0,1      19,0,32            320        639        320  160K  5 Extended
/dev/rb3    20,0,1      31,0,32            640       1023        384  192K 83 Linux
*/

// TODO 1: Create a Partitition table as per above table
// Use appropriate values for start_head, end_head, start_cyl, end_cyl
// start_sec, end_sec, abs_start_sec and sec_in_part
static PartTable def_part_table =
{
	{
		boot_type: 0x00,
		start_head: 0x0,
		start_cyl: 0x0,
		start_sec: 0x2,
		part_type: 0x83,
		end_head: 0x0,
		end_cyl: 0x9,
		end_sec: 0x20,
		abs_start_sec: 0x00000001,
		sec_in_part: 0x0000013F
	},
	{
		boot_type: 0x00,
		start_head: 0x0,
		start_cyl: 0xA,
		start_sec: 0x1,
		part_type: 0x05,
		end_head: 0x0,
		end_cyl: 0x13,
		end_sec: 0x20,
		abs_start_sec: 0x00000140,
		sec_in_part: 0x00000140
	},
	{
		boot_type: 0x00,
		start_head: 0x0,
		start_cyl: 0x14,
		start_sec: 0x1,
		part_type: 0x83,
		end_head: 0x0,
		end_cyl: 0x1F,
		end_sec: 0x20,
		abs_start_sec: 0x00000280,
		sec_in_part: 0x00000180,
	},
	{
	}
};
/*
/dev/rb5    10,0,2      13,0,32            321        447        127 65024 83 Linux
/dev/rb6    14,0,2      17,0,32            449        575        127 65024 83 Linux
/dev/rb7    18,0,2      19,0,32            577        639         63 32256 83 Linux
*/
//TODO 2: Create the Extended partition table as per the above table
static unsigned int def_log_part_br_cyl[] = {0x0A, 0x0E, 0x12};
static const PartTable def_log_part_table[] =
{
	{
		{
			boot_type: 0x00,
			start_head: 0x0,
			start_cyl: 0xA,
			start_sec: 0x2,
			part_type: 0x83,
			end_head: 0x0,
			end_cyl: 0xD,
			end_sec: 0x20,
			abs_start_sec: 0x00000001,
			sec_in_part: 0x0000007F,
		},
		{
			boot_type: 0x00,
			start_head: 0x0,
			start_cyl: 0xE,
			start_sec: 0x1,
			part_type: 0x05,
			end_head: 0x0,
			end_cyl: 0x11,
			end_sec: 0x20,
			abs_start_sec: 0x00000080,
			sec_in_part: 0x00000080,
		},
	},
	{
		{
			boot_type: 0x00,
			start_head: 0x0,
			start_cyl: 0xE,
			start_sec: 0x2,
			part_type: 0x83,
			end_head: 0x0,
			end_cyl: 0x11,
			end_sec: 0x20,
			abs_start_sec: 0x00000080,
			sec_in_part: 0x0000007F,
		},
//dev/rb7    18,0,2      19,0,32            577        639         63 32256 83 Linux
		{
			boot_type: 0x00,
			start_head: 0x0,
			start_cyl: 0x12,
			start_sec: 0x1,
			part_type: 0x05,
			end_head: 0x0,
			end_cyl: 0x13,
			end_sec: 0x20,
			abs_start_sec: 0x00000100,
			sec_in_part: 0x00000040,
		},
	},
	{
		{
			boot_type: 0x00,
			start_head: 0x0,
			start_cyl: 0x12,
			start_sec: 0x2,
			part_type: 0x83,
			end_head: 0x0,
			end_cyl: 0x13,
			end_sec: 0x20,
			abs_start_sec: 0x00000100,
			sec_in_part: 0x0000003F,
		},
	}
};

static void copy_mbr(u8 *disk)
{
	memset(disk, 0x0, MBR_SIZE);
	// TODO 3: Copy the disk signature
	*(unsigned long *)(disk + MBR_DISK_SIGNATURE_OFFSET) = DISK_SIGNATURE;
	// TODO 4: Copy the Partition table
	memcpy(disk + PARTITION_TABLE_OFFSET, &def_part_table, PARTITION_TABLE_SIZE);
	// TODO 5: Copy the MBR signature
	*(unsigned short *)(disk + MBR_SIGNATURE_OFFSET) = MBR_SIGNATURE;
}
static void copy_br(u8 *disk, int start_cylinder, const PartTable *part_table)
{
	disk += (start_cylinder * 32 /* sectors / cyl */ * SECTOR_SIZE);
	memset(disk, 0x0, BR_SIZE);
	// TODO 6: Copy the partition table
	memcpy(disk + PARTITION_TABLE_OFFSET, part_table, PARTITION_TABLE_SIZE);
	// TODO 7: Copy the BR Signature
	*(unsigned short *)(disk + BR_SIGNATURE_OFFSET) = BR_SIGNATURE;
}
void copy_mbr_n_br(u8 *disk)
{
	int i;

	copy_mbr(disk);
	for (i = 0; i < ARRAY_SIZE(def_log_part_table); i++)
	{
		copy_br(disk, def_log_part_br_cyl[i], &def_log_part_table[i]);
	}
}
