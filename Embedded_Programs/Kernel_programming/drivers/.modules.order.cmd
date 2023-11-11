cmd_/home/pranavix/Documents/drivers/modules.order := {   echo /home/pranavix/Documents/drivers/module1.ko; :; } | awk '!x[$$0]++' - > /home/pranavix/Documents/drivers/modules.order
