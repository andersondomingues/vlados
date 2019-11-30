all:
	mkdir -p isodir/boot/grub
	cp ../build/$(IMAGE_NAME) isodir/boot/$(IMAGE_NAME)
	cp ../boot/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(IMAGE_NAME).iso isodir --verbose
	cp $(IMAGE_NAME).iso ../build/
	
clean:
	rm -rf isodir $(IMAGE_NAME).iso