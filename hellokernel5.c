#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gabriel <GThiago>");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintArray[2] = { -1, -1 };
static int arr_argc = 0;

/*
 * module_param(foo, int, 000)
 * The first param is the param name
 * The second, is its data type
 * The final, is the permissions bits
 * for exposing parameters in sysfs (if non-zero) at a later stage
 */

module_param(myshort, short , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short Integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

/*
 * module_param_array(name, type, num, perm);
 * first  = is parameter's (arrays) name
 * second = data type of the elements of the array
 * third  = a pointer to the variable tha will store the number 
 * of elements of the array initized by the user at module loading time
 * fourth = permission bits
 */

module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integer");

static int __init hello_5_init(void){
   int i;
   printk(KERN_INFO "Hello, World 5\n=====================\n");
   printk(KERN_INFO "myshort if a short integer: %hd\n", myshort);
   printk(KERN_INFO "myint is a an integer: %d\n", myint);
   printk(KERN_INFO "mylong is a long integer: %ld\n", mylong);
   printk(KERN_INFO "mystring is a string: %s\n", mystring);

   for (i=0; i < (sizeof myintArray / sizeof(int)); i++){
      printk(KERN_INFO "myIntArray[%d] = %d\n", i, myintArray[i]);
   }
   
   printk(KERN_INFO "got %d arguments for myIntArray.\n", arr_argc);
   return 0;
}

static void __exit hello_5_exit(void){
   printk(KERN_INFO "Adeeuss World 5 :)\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);