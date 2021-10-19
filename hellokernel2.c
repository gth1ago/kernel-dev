#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void){
    printk(KERN_INFO "Hello World2.\n");

    /*
     * A non 0 return means init module failed, module can't be loaded.
     */
    return 0;
}

void cleanup_module(void){
    printk(KERN_INFO "Adeus :).\n");
}
