cmd_/home/engineer/Documents/sysfs/driver.mod := printf '%s\n'   driver.o | awk '!x[$$0]++ { print("/home/engineer/Documents/sysfs/"$$0) }' > /home/engineer/Documents/sysfs/driver.mod
