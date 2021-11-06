# obj-m += hellokernel1.o
# obj-m += hellokernel2.o
# obj-m += hellokernel3.o
# obj-m += hellokernel5.o
obj-m += startstop.o					 # object name for our combined module
startstop-objs := start.o stop.o  # what object files are part of that module

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
