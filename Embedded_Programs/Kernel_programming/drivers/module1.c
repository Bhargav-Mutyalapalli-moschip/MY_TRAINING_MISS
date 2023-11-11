#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
static int init_load(void)
{
	printk(KERN_INFO "driver is named as driver");
	printk(KERN_INFO "Successfully loaded");
	return 0;
}
static void closer(void)
{
	printk(KERN_INFO "driver is named as driver");
	printk(KERN_INFO "Successfully unloaded");
}
module_init(init_load);
module_exit(closer);

MODULE_AUTHOR("M B R PRANAV");
MODULE_LICENSE("GPL_V2");
MODULE_DESCRIPTION("DRIVER MODULE");






