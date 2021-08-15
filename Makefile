bootloader_asm_source_files := $(shell find src/bootloader -name *.asm)
bootloader_asm_object_files := $(patsubst src/bootloader/%.asm, build/bootloader/%.o, $(bootloader_asm_source_files))

kernel_cpp_source_files := $(shell find src/kernel -name *.cpp)
kernel_cpp_object_files := $(patsubst src/kernel/%.cpp, build/kernel/%.o, $(kernel_cpp_source_files))

$(kernel_cpp_object_files): build/kernel/%.o : src/kernel/%.cpp
	mkdir -p $(dir $@) && \
	i686-elf-g++ -c $(patsubst build/kernel/%.o, src/kernel/%.cpp, $@) -o $@ -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
	

$(bootloader_asm_object_files): build/bootloader/%.o : src/bootloader/%.asm
	mkdir -p $(dir $@) && \
	nasm $(patsubst build/bootloader/%.o, src/bootloader/%.asm, $@) -o $@ -felf32


all:
	build-i686

build-i686: $(kernel_cpp_object_files) $(bootloader_asm_object_files)
	mkdir -p dist/i686 && \
	i686-elf-gcc -T src/linker/linker.ld -o dist/i686/kernel.bin -ffreestanding -O2 -nostdlib $(kernel_cpp_object_files) $(bootloader_asm_object_files)  -lgcc && \
	cp dist/i686/kernel.bin targets/i686/iso/boot/kernel.bin && \
	grub-mkrescue -o dist/i686/kernel.iso targets/i686/iso