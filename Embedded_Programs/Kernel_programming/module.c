#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

static int hello_module(void)
//int init_module(void)
{
	pr_info("My basic module is ");
	pr_info("loaded successfully \n");
	//printk(KERN_INFO "My basic module loaded successfully\n");
	//printk("<6>" "My basic module loaded successfully\n");
	return 0;
}

static void hello_exit_module(void)
//void cleanup_module(void)
{
	printk(KERN_INFO "My basic module\n");
	printk(KERN_INFO "loaded successfully\n");
}

module_init(hello_module);
module_exit(hello_exit_module);

MODULE_AUTHOR("BHARGAVI REDDY");
MODULE_LICENSE("GPL_V2");
MODULE_DESCRIPTION("Basic Module");
	

