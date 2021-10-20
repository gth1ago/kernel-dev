#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR   "Gabriel <GThiago>"
#define DRIVER_DESC     "A sample driver"

static int __init init_hello_4(void){
   printk(KERN_INFO "Hello, World 3!\n");
   return 0;
}

static void __exit cleanup_hello_4(void){
   printk(KERN_INFO "Goodbye, World 3\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

/* This module uses /dev/testdevice, The MODULE_SUPPORTED_DEVICE macro night
 * be used in the future to help automatic configuration of modules, but is
 * currently unused other than for documentation purpose 
 */

MODULE_SUPPORTED_DEVICE("testdevice");