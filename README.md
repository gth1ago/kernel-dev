# kernel-dev
Kernel development training

Use: 
``` bash
   $ make all
``` 

For compile

This create a bunch of files, but the *.ko generate is our kernel module

To install-it, can use modprobe (complete if you need dependency) or insmod tool
``` bash
   $ sudo insmod <path-to>/hellokernel.ko
```
To see if was load successfully use lsmod tool
``` bash
   $ lsmod
``` 

Or see in /proc/modules

```bash
   $ cat /proc/modules
```

This will list all kernel modules loaded in your system

Now, to see we message "Hello Kernel!", use the dmesg tool
``` bash
   $ dmesg
```
To unload the kernel module, can use modprobe (remove dependency), or the rmmod tool
``` bash
   $ sudo rmmod hellokernel
```
Again, use the dmesg tool to see message of exit.

