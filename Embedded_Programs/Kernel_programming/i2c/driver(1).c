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
struct cdev check_cdev;
static struct class *dev_class;

/*file operations of the driver*/
static int __init initialization(void);
static void __exit char_exit(void);
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
	/* Dynamically allocate a device number */
	alloc_chrdev_region(&device_number,0,7,"pranav");

	/*Initialize the cdev structure with fops*/
	cdev_init(&check_cdev,&fops);

	/*Register the cdev structure in kernels*/
	check_cdev.owner=THIS_MODULE;
	cdev_add(&check_cdev,device_number,1);

	device_create(dev_class,NULL,device_number,NULL,"device");






	
	return 0;

}
static void __exit char_exit(void)
{
	device_destroy(dev_class,device_number);
        class_destroy(dev_class);
        cdev_del(&check_cdev);
        unregister_chrdev_region(device_number, 1);
        pr_info("Device Driver Remove is Done.....!!!\n");

}
module_init(initialization);
module_exit(char_exit);

MODULE_LICENSE("GPL_V2");
MODULE_AUTHOR("M B R PRANAV");
MODULE_DESCRIPTION("Character driver");





