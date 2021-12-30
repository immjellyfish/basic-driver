# obj-m determines what kernel modules to make
# obj-y (if any) determines what built-in kernel driver to make
obj-m += hello.o

# -C changes the working directory for the call of make
# M determines the directory of source codes
modules clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(shell pwd) $@

.PHONY: modules clean
