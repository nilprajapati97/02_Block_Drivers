cmd_/home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.o := arm-linux-gnueabihf-gcc -Wp,-MD,/home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/.partition.o.d  -nostdinc -isystem /opt/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/bin/../lib/gcc/arm-linux-gnueabihf/6.5.0/include -I./arch/arm/include -I./arch/arm/include/generated  -I./include -I./arch/arm/include/uapi -I./arch/arm/include/generated/uapi -I./include/uapi -I./include/generated/uapi -include ./include/linux/kconfig.h -include ./include/linux/compiler_types.h -D__KERNEL__ -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -Werror-implicit-function-declaration -Wno-format-security -std=gnu89 -fno-PIE -fno-dwarf2-cfi-asm -fno-ipa-sra -mabi=aapcs-linux -mfpu=vfp -funwind-tables -mthumb -Wa,-mimplicit-it=always -Wa,-mno-warn-deprecated -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -fno-delete-null-pointer-checks -Wno-frame-address -O2 --param=allow-store-data-races=0 -Wframe-larger-than=1024 -fstack-protector-strong -Wno-unused-but-set-variable -Wno-unused-const-variable -fno-var-tracking-assignments -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fno-merge-all-constants -fmerge-constants -fno-stack-check -fconserve-stack -Werror=implicit-int -Werror=strict-prototypes -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init  -DMODULE  -DKBUILD_BASENAME='"partition"' -DKBUILD_MODNAME='"dor"' -c -o /home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/.tmp_partition.o /home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.c

source_/home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.o := /home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.c

deps_/home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.o := \
  include/linux/kconfig.h \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/retpoline.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
    $(wildcard include/config/fortify/source.h) \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
    $(wildcard include/config/kasan.h) \
  include/linux/compiler_types.h \
  include/uapi/linux/types.h \
  arch/arm/include/uapi/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  arch/arm/include/generated/uapi/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
    $(wildcard include/config/64bit.h) \
  include/uapi/asm-generic/bitsperlong.h \
  include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  arch/arm/include/uapi/asm/posix_types.h \
  include/uapi/asm-generic/posix_types.h \
  arch/arm/include/asm/barrier.h \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/thumb2/kernel.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/fa526.h) \
    $(wildcard include/config/arm/heavy/mb.h) \
    $(wildcard include/config/arm/dma/mem/bufferable.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/cpu/spectre.h) \
  include/asm-generic/barrier.h \
  include/linux/kasan-checks.h \
  include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
  /opt/gcc-linaro-6.5.0-2018.12-x86_64_arm-linux-gnueabihf/lib/gcc/arm-linux-gnueabihf/6.5.0/include/stdarg.h \
  include/uapi/linux/string.h \
  arch/arm/include/asm/string.h \
  /home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.h \

/home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.o: $(deps_/home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.o)

$(deps_/home/pradeep/Trainings/Altran/Exercises/BlockFSDriver/Stage2Ramdisk/partition.o):
