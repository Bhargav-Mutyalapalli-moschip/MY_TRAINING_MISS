#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/err.h>
#define DEVICE_MEMORY_SIZE 512
char device_buffer[DEVICE_MEMORY_SIZE];
dev_t device_number;
/*cdev variable*/
/*file operations of the driver*/
static int      etx_open(struct inode *inode, struct file *file);
static int      etx_release(struct inode *inode, struct file *file);
static ssize_t  etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = etx_read,
    .write      = etx_write,
    .open       = etx_open,
    .release    = etx_release,
};
struct d_context
{
	char buf[1024];
	int no_chars;
	int base_address;
	int IRQ_lineno;
	struct cdev cdev;
}mycontext;
static int etx_open(struct inode *inode, struct file *file)
{
        pr_info("Driver Open Function Called...!!!\n");
        return 0;
}

static int etx_release(struct inode *inode, struct file *file)
{
        pr_info("Driver Release Function Called...!!!\n");
        return 0;
}

static ssize_t etx_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Read Function Called...!!!\n");
        return 0;
}

static ssize_t etx_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Write Function Called...!!!\n");
        return len;
}

static int __init initialization(void)
{
	int res=0;
	device_number=MKDEV(42,0);
	res=register_chrdev_region(device_number,1,"pranav_driver");
	if(res < 0)
	{
		printk("<1>" "Pranav driver is not loaded successfully\n");
		return res;
	}
	else
	{
		printk("<1>" "Pranav driver is loaded successfully\n");
	}

	/*Initialize the cdev structure with fops*/
	cdev_init(&mycontext.cdev,&fops);

	/*Register the cdev structure in kernels*/
	mycontext.cdev.owner=THIS_MODULE;
	res=cdev_add(&mycontext.cdev,device_number,1);
	if(res < 0)
	{
		printk("<1>" "object is not loaded successfully\n");
		unregister_chrdev_region(device_number,1);
	}
	printk("<1>" "cdev object is loaded successfully\n");
	return res;

	
}
static void __exit char_exit(void)
{
        cdev_del(&mycontext.cdev);
        unregister_chrdev_region(device_number, 1);
        pr_info("Device Driver Remove is Done.....!!!\n");

}
module_init(initialization);
module_exit(char_exit);

MODULE_LICENSE("GPL_V2");
MODULE_AUTHOR("M B R PRANAV");
MODULE_DESCRIPTION("Character driver");





