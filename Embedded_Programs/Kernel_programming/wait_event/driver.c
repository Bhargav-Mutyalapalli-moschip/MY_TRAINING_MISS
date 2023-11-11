#include<linux/kernel.h>
#include<linux/wait.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/uaccess.h>
#include <linux/kdev_t.h>
#include <linux/err.h>
#define DEVICE_MEMORY_SIZE 512
#define SIZE 1024
char device_buffer[DEVICE_MEMORY_SIZE];
dev_t device_number;
int ret,uc,a;
DECLARE_WAIT_QUEUE_HEAD(readwait_q);
DECLARE_WAIT_QUEUE_HEAD(writewait_q);

/*cdev variable*/
/*file operations of the driver*/
static int      etx_open(struct inode *inode, struct file *file);
static int      etx_release(struct inode *inode, struct file *file);
static ssize_t  etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
struct d_context
{
	char buf[SIZE];
	int no_chars;
	int base_address;
	int IRQ_lineno;
	struct cdev cdev;
}mycontext;
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
	try_module_get(THIS_MODULE); //increments the module count by one
	file->private_data=&mycontext; //stored the context area data in the private for the secure and selection of particular device
	if(file->f_mode & FMODE_READ)
	pr_info("This file is opened under read mode\n");
	if(file->f_mode & FMODE_WRITE)
	pr_info("This file is opened under write mode\n");
        return 0;
}

static int etx_release(struct inode *inode, struct file *file)
{
        pr_info("Driver Release Function Called...!!!\n");
	module_put(THIS_MODULE); //decrement the module count by one
	pr_info("Closed is invoked and device file is closed suucessfully\n");
        return 0;
}

static ssize_t etx_read(struct file *file, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Read Function Called...!!!\n");
	struct d_context *tdev;
	tdev=file->private_data;
	wait_event_interruptible(readwait_q,tdev->no_chars > 0);
	if(tdev->no_chars < len)
		uc=tdev->no_chars;
	else
		uc=len;
	//storing the address of device context info of particular device file into a device
	//if(len > tdev->no_chars)
	//len=tdev->no_chars;
	ret=copy_to_user(buf,tdev->buf,uc); /* 1.Destination base address 2.Source base address 3.length of string */
	if(ret < 0)
	{
		pr_info("failed to perform the copy to user\n");
	}
	tdev->no_chars=tdev->no_chars-uc;
	wake_up_interruptible(&writewait_q);
	printk("<1>" "Read is called\n");
	return uc;
}

static ssize_t etx_write(struct file *file, const char __user *buf, size_t len, loff_t *off)
{
	pr_info("Driver Write Function Called...!!!\n");
	struct d_context *tdev;
	tdev=file->private_data;
	//storing the address of device context info of particular device file into a device
	wait_event_interruptible(writewait_q,tdev->no_chars < SIZE);
	a=SIZE-tdev->no_chars;
	if(len > a)
		len=a;
	ret=copy_from_user(tdev->buf,buf,len); /* 1.Destination base address 2.Source base address 3.length of string */
	if(ret < 0)
	{
		pr_info("failed to perform the copy from user\n");
	}
	tdev->no_chars=len+tdev->no_chars;
	wake_up_interruptible(&readwait_q);
	printk("<1>" "Write is called\n");
	pr_info("Data is received from application which is called----(%s)-----(%d)(no of characters in the string)\n",tdev->buf,tdev->no_chars);
	return (ssize_t)len;
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





