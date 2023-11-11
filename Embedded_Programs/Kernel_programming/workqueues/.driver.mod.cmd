cmd_/home/engineer/Documents/workqueues/driver.mod := printf '%s\n'   driver.o | awk '!x[$$0]++ { print("/home/engineer/Documents/workqueues/"$$0) }' > /home/engineer/Documents/workqueues/driver.mod
