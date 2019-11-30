TCPATH = /home/adomingues/gaph/vlados/tools/i686-elf/gcc-7.1.0/bin

IMAGE_NAME = vlados.bin
export IMAGE_NAME

CC  = $(TCPATH)/i686-elf-cc
CPP = $(TCPATH)/i686-elf-c++
AS  = $(TCPATH)/i686-elf-as

BUILD_DIR = build

export AS
export CC
export CPP

BOOT_FLAGS = 

LINKING_FLAGS = -ffreestanding -O2 -nostdlib 
LINKING_FLAGS := $(LINKING_FLAGS) -fdata-sections -ffunction-sections -Wl,--gc-sections
#-lgcc
KERNEL_FLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti

export KERNEL_FLAGS

.PHONY: all

all: $(BUILD_DIR)/$(IMAGE_NAME)
	@echo `grub-file --is-x86-multiboot $(BUILD_DIR)/$(IMAGE_NAME)`
	make -C iso

$(BUILD_DIR)/$(IMAGE_NAME): $(BUILD_DIR)/boot.o $(BUILD_DIR)/Kernel.o
	$(CPP) -T linker.ld -o $(BUILD_DIR)/$(IMAGE_NAME) $(BUILD_DIR)/boot.o $(BUILD_DIR)/Kernel.o $(LINKING_FLAGS) 
	
$(BUILD_DIR)/boot.o:
	make -C boot
	
$(BUILD_DIR)/Kernel.o:
	make -C kernel
	
clean:
	make -C kernel clean
	make -C boot clean
	make -C iso clean
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.bin $(BUILD_DIR)/*.iso