#include <linux/kernel.h> // module functions - (init, exit..)
#include <linux/module.h> // kernel functions - (printk,..)

/* Init Function of our module
   
   The __init parameters tells the kernel to free the space 
      of this function after the initialization
   
   This only works for built-in kernel modules

   Future this use for alloc the memory need and initialization 
      for you module
*/

static int __init hellokernelmod_init(void){
   printk(KERN_INFO "Hello Kernel!\n");
   return 0; // on success
}


/* Exit/cleanup function of our module
   
   Basically everything you did in the init function you need to "undo" here
   Freeing memory space, closing sockets, finishing devices...

   The __exit parameter tells the kernel to omit this function when
       the module is built-in, since in built in modules this functions would never execute.

*/

static void __exit hellokernelmod_exit(void){
   printk(KERN_INFO "See you later, Kernel!\n");
}

/* Modules API has some macros that helps to define your module
   See more information with
   $ modinfo <PATH-TO>/hellokernel.ko.
*/ 

MODULE_AUTHOR("Gabriel Thiago <gth1ago>");
MODULE_DESCRIPTION("Simple Kernel Module to display messages.");
MODULE_LICENSE("GPL");


// Registering our functions to be executed in the beginning and in the exit of the module.
module_init(hellokernelmod_init);
module_exit(hellokernelmod_exit);