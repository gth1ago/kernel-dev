# kernel-dev
Kernel development training

Use: 
``` bash
   $ make all
``` 

For compile

This create a bunch of files, but the *.ko generate is our kernel module

To install-it, use insmod tool
``` bash
   $ sudo insmod <path-to>/hellokernel.ko
```
To see if was load successfully use lsmod tool
``` bash
   $ lsmod
``` 
This will list all kernl modules loaded in your system

Now, to see wee message "Hello Kernel!", use the dmesg tool
``` bash
   $ dmesg
```
To unload the kernel module, use the rmmod tool
``` bash
   $ sudo rmmod hellokernel
```
Again, use the dmesg tool to see message of exit.

