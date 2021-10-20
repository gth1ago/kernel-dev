obj-m += hellokernel1.o
obj-m += hellokernel2.o
obj-m += hellokernel3.o
obj-m += hellokernel5.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
