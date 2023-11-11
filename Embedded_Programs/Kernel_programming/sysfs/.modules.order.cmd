cmd_/home/engineer/Documents/sysfs/modules.order := {   echo /home/engineer/Documents/sysfs/driver.ko; :; } | awk '!x[$$0]++' - > /home/engineer/Documents/sysfs/modules.order
