# basic-driver
This kernel module driver demonstrates a basic architecture that a kernel module would have. This driver also demonstrates how a driver prints messages and accepts module parameters.

# Usage
1. Run `make` to build the kernel module
  ```
  $ ls
  hello.c  LICENSE  Makefile  README.md
  $ make
  make -C /lib/modules/5.11.0-43-generic/build/ M=/home/immjellyfish/dev/lkm/basic-driver modules
  make[1]: Entering directory '/usr/src/linux-headers-5.11.0-43-generic'
    CC [M]  /home/immjellyfish/dev/lkm/basic-driver/hello.o
    MODPOST /home/immjellyfish/dev/lkm/basic-driver/Module.symvers
    CC [M]  /home/immjellyfish/dev/lkm/basic-driver/hello.mod.o
    LD [M]  /home/immjellyfish/dev/lkm/basic-driver/hello.ko
    BTF [M] /home/immjellyfish/dev/lkm/basic-driver/hello.ko
  Skipping BTF generation for /home/immjellyfish/dev/lkm/basic-driver/hello.ko due to unavailability of vmlinux
  make[1]: Leaving directory '/usr/src/linux-headers-5.11.0-43-generic'
  ```
  ```
  $ ls
  hello.c  hello.ko  hello.mod  hello.mod.c  hello.mod.o  hello.o  LICENSE  Makefile  modules.order  Module.symvers  README.md
  ```
2. Run `modinfo hello.ko` to check the kernel module information.
  ```
  $ modinfo hello.ko
  filename:       /home/immjellyfish/dev/lkm/tmp/basic-driver/hello.ko
  version:        0.1
  description:    A basic Linux Kernel Module demonstration. User can enter an user name argument.
  author:         Immortal Jellyfish
  license:        Dual MIT/GPL
  srcversion:     05918294070E1DF434E6BF7
  depends:
  retpoline:      Y
  name:           hello
  vermagic:       5.11.0-43-generic SMP mod_unload modversions
  parm:           name:The user name used in this module, or world by default (charp)
  ```
3. Run `sudo insmod hello.ko` to insert the kernel module. You can see a message in the kernel log.
  ```
  $ sudo insmod hello.ko
  $ dmesg
  [ 9147.762138] hello_init 38:Hello world!
  ```
4. Run `sudo rmmod hello.ko` to remove the kernel module. You can see another message in the kernel log.
  ```
  $ sudo rmmod hello.ko
  $ dmesg
  [ 9147.762138] hello_init 38:Hello world!
  [ 9299.188464] hello_exit 47:Goodbye world!
  ```
5. Try to run again, but with the kernel parameter `name` this time.
  ```
  $ sudo insmod hello.ko name=immjellyfish
  $ sudo rmmod hello.ko
  $ dmesg
  [ 9547.789652] hello_init 38:Hello immjellyfish!
  [ 9550.550900] hello_exit 47:Goodbye immjellyfish!
  ```
6. In the end, you can run `make clean` to clean up the creating files from building procedure.
  ```
  $ make clean
  make -C /lib/modules/5.11.0-43-generic/build/ M=/home/immjellyfish/dev/lkm/tmp/basic-driver clean
  make[1]: Entering directory '/usr/src/linux-headers-5.11.0-43-generic'
    CLEAN   /home/immjellyfish/dev/lkm/tmp/basic-driver/Module.symvers
  make[1]: Leaving directory '/usr/src/linux-headers-5.11.0-43-generic'
  ```
  ```
  $ ls
  hello.c  LICENSE  Makefile  README.md
  ```
