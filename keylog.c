/*
**  Dany Bouca Nova
**      Simple Keylogger to learn how to create a kernel module.
*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dany Bouca Nova <dany.boucanova@gmail.com");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("Just a simple keylogger");
MODULE_SUPPORTED_DEVICE("Not machine dependent");

static int  __init keylog_init(void)
{
    printk(KERN_INFO "hello !\n");
    return (0);
}

static void __exit keylog_end(void)
{
    printk(KERN_INFO "I am going !\n");

}

module_init(keylog_init);
module_end(keylog_end);
