cmd_/home/engineer/Documents/sysfs/Module.symvers := sed 's/ko$$/o/' /home/engineer/Documents/sysfs/modules.order | scripts/mod/modpost -m -a  -o /home/engineer/Documents/sysfs/Module.symvers -e -i Module.symvers   -T -
