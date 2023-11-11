#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/sysfs.h>
#include<linux/cdev.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/fs.h>
dev_t device_no;
int glob=0;
struct class *dev_class;
struct kobject *my_kobj;
static ssize_t sysfs_show(struct kobject *kobj,struct kobj_attribute *attr, char *buf);
static ssize_t sysfs_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf, size_t count);
struct kobj_attribute attr = __ATTR(glob, 0660, sysfs_show, sysfs_store);
static ssize_t sysfs_show(struct kobject *kobj,struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%d", glob);
}
static ssize_t sysfs_store(struct kobject *kobj,struct kobj_attribute *attr,const char *buf, size_t count)
{
        sscanf(buf,"%d",&glob);
        return count;
}
static int __init my_init(void)
{
	int ret;
	pr_info("Driver is loaded\n");
	ret=alloc_chrdev_region(&device_no,0,1,"MYDRIVER");
	if(ret < 0)
	{
		pr_info("Failed to register and create the device number dynamically\n");
	}
	pr_info("The Major:%d-------Minor:%d\n",MAJOR(device_no),MINOR(device_no));
	dev_class=class_create(THIS_MODULE,"my_class");
	if(IS_ERR(dev_class))
	{
		pr_err("Cannot create the struct class for device\n");
	}
	ret=device_create(dev_class,NULL,device_no,NULL,"my_device");
	if(ret < 0)
	{
		pr_info("Failed to create the device file\n");
	}
	my_kobj=kobject_create_and_add ( "pranav",NULL);
	sysfs_create_file(my_kobj,&attr.attr);
	return 0;

}
static void __exit my_exit(void)
{
	pr_info("Driver is unloaded\n");
	device_destroy(dev_class,device_no);
        class_destroy (dev_class);
	unregister_chrdev_region(device_no, 1);
	kobject_put(my_kobj);
	sysfs_remove_file(my_kobj, &attr.attr);
	pr_info("driver is removed successfully\n");
}
module_init(my_init);
module_exit(my_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("NORMAL BASIC DRIVER");
MODULE_AUTHOR("RAM");




