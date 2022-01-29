#include <linux/types.h>
#include <linux/vmalloc.h>
#include <linux/string.h>
#include <linux/errno.h>

#include "ram_device.h"
#include "partition.h"

#define RB_DEVICE_SIZE 1024 /* sectors */
/* So, total device size = 1024 * 512 bytes = 512 KiB */

/* Array where the disk stores its data */
static u8 *dev_data;

int ramdevice_init(void)
{
	// TODO 1: Allocate the memory with vmalloc
	dev_data = vmalloc(RB_DEVICE_SIZE * RB_SECTOR_SIZE);
	if (dev_data == NULL)
		return -ENOMEM;
	/* Setup its partition table */
	// TODO 2: Copy the mbr and br
	copy_mbr_n_br(dev_data);
	return RB_DEVICE_SIZE;
}

void ramdevice_cleanup(void)
{
	//TODO 5: Free up the memory
	vfree(dev_data);
}

void ramdevice_write(sector_t sector_off, u8 *buffer, unsigned int sectors)
{
	//TODO 3: Copy the buffer data into the disk
	memcpy(dev_data + sector_off * RB_SECTOR_SIZE, buffer, sectors * RB_SECTOR_SIZE);
}
void ramdevice_read(sector_t sector_off, u8 *buffer, unsigned int sectors)
{
	//TODO 4: Copy the data from the specified sectors into the buffer
	memcpy(buffer, dev_data + sector_off * RB_SECTOR_SIZE, sectors * RB_SECTOR_SIZE);
}
