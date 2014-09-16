Clonie is a powerfull program that clones drives both in good condition and bad.

only use this program if you know what you are doing, this has the power to wipe drives
	if not used correctly.

there are three arguments that can be run in clonie.
	-d dirty clone (see below)
	-c clean clone (see below)
	-z zerowrite (dd against /dev/zero to zerowrite drive)

if you need the dependencies (dd, ddrescue, pv, and lsblk) you can run the c program for your
	package manager:
		clonieDebDependencies.c for debian based/Aptitude
		clonieFedoraDependencies.c for a RedHat/Yum based system.

There are two modes to this: clean and dirty
	clean is based off of ddrescue and tries to work around bad sectors/disk errors
	dirty is based on dd and is known to freeze up around bad sectors.

BS-Value: do some research before diving in, for most disks this value wont matter too much,
	but it still deals with the block size, for regular acuracy and speed we found that 
	512 is a good starting point, so it is good for a default value.

If you choose the dirty clone, the clone will output a logfile by default names cloneLog.txt, this 
	will output all locations of bad sectors, and manual recovery will need to be done.
