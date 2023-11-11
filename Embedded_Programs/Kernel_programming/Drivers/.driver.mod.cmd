cmd_/home/engineer/Documents/testing/driver.mod := printf '%s\n'   driver.o | awk '!x[$$0]++ { print("/home/engineer/Documents/testing/"$$0) }' > /home/engineer/Documents/testing/driver.mod
