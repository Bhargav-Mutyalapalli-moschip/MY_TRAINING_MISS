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
int32_t value = 0;
#define WR_VALUE _IOW('a','a',int32_t*)
#define RD_VALUE _IOR('a','b',int32_t*)

/*cdev variable*/
/*file operations of the driver*/
static int      etx_open(struct inode *inode, struct file *file);
static int      etx_release(struct inode *inode, struct file *file);
static ssize_t  etx_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  etx_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static long     etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = etx_read,
    .write      = etx_write,
    .open       = etx_open,
     .unlocked_ioctl = etx_ioctl,
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
	try_module_get(THIS_MODULE); /*--------It will increase the module count of no of devices communicating to driver---*/
	file->private_data=&mycontext; /*----Storing the base address of device context info in file object private data--*/
	if(file->f_mode & FMODE_READ) /*------FMODE_READ is a predefined macro it has unique identifier for read mode ----*/
	{
		printk("<1>" "the file is opened under the read\n");

	}
	if(file->f_mode & FMODE_WRITE) /*------FMODE_WRITE is a predefined macro it has unique identifier for write mode ----*/
	{
		printk("<1>" "the file is opened under the write\n");

	}

        return 0;
}

static int etx_release(struct inode *inode, struct file *file)
{
	module_put(THIS_MODULE); /*------It will decreas the module count of no of devices communicating to driver---*/
	printk("<1>" "Device file is closed");
        return 0;
}

static ssize_t etx_read(struct file *file, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Read Function Called...!!!\n");
	/*struct d_context *tdev;
	tdev=file->private_data;
	if(len > tdev->no_chars)
	len=tdev->no_chars;
	copy_to_user(buf,tdev->buf,len);
	tdev->no_chars=0;*/
	printk("<1>" "open s invoked\n");
	return len;
}

static ssize_t etx_write(struct file *file, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Write Function Called...!!!\n");
	/*struct d_context *tdev;
	tdev=file->private_data;
	if(len > 1024)
	len=1024;
	copy_from_user(tdev->buf,buf,len);
	tdev->no_chars=len;*/
	printk("<1>" "Write s invoked\n");
	//pr_info("data received from app:%s---%d no of chars\n",tdev->buf,tdev->no_chars);
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
static long etx_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
         switch(cmd) {
                case WR_VALUE:
                        if( copy_from_user(&value ,(int32_t*) arg, sizeof(value)) )
                        {
                                pr_err("Data Write : Err!\n");
                        }
                        pr_info("Value = %d\n", value);
                        break;
                case RD_VALUE:
                        if( copy_to_user((int32_t*) arg, &value, sizeof(value)) )
                        {
                                pr_err("Data Read : Err!\n");
                        }
                        break;
                default:
                        pr_info("Default\n");
                        break;
        }
        return 0;
}

module_init(initialization);
module_exit(char_exit);

MODULE_LICENSE("GPL_V2");
MODULE_AUTHOR("M B R PRANAV");
MODULE_DESCRIPTION("Character driver");





