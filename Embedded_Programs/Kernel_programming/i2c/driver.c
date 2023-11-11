#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#define DEVICE_MEMORY_SIZE 512
char device_buffer[DEVICE_MEMORY_SIZE];
dev_t device_number;
static int __init initialization(void)
{
	/* Dynamically allocate a device number */
	alloc_chrdev_region(&device_number,0,7,"pranav");



	
	return 0;

}
static void __exit char_exit(void)
{

}
module_init(initialization);
module_exit(char_exit);

MODULE_LICENSE("GPL_V2");
MODULE_AUTHOR("M B R PRANAV");
MODULE_DESCRIPTION("Character driver");





