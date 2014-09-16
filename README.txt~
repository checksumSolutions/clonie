clonie v. 1.1

CHANGES
-------
1.0 -- first release
1.1 -- added support for OSX

DEPENDENCIES
------------
*lsblk (this is not needed on OSX, diskutil list is used instead)
*ddrescue
*dd
*pv
*** If you are using OSX, please make sure you have command line tools installed

Without these programs, clonie will not function properly.

INSTALLING CLONIE
-----------------
make
sudo make install

INSTALLING CLONIE ON OSX
------------------------
make osx
sudo make install

USING CLONIE
------------
Clonie is a very powerful tool when used properly. Clonie has the power to wipe drives. Please be careful when using clonie. It isn't our fault if you lose your data.

Clonie can copy data from both good drives and bad drives.

Clonie has 3 modes, dirty clone, clean clone, and zerowrite. Dirty and clean can be used either at the prompt when the program is executed, or with 
-d
-c
respectively. Zerowrite can only be used by throwing the flag
-z
upon running clonie, as this will copy the contents of /dev/zero onto the target drive and create nearly-unrecoverable data loss.

Dirty clone is based off of dd, and will work perfectly for known good drives. However, dd is known to freeze up around bad sectors and shouldn't be used on known bad drives.

Clean clone is based off of ddrescure, and will work around bad sectors. Clonie will then create a logfile (named cloneLog.txt by default) which contains the locations of bad sectors which will need to have manual recovery performed.

You may also specify a value for block sizes, (BS-Value), when prompted. Do some research before diving in, as for most drives you will not need to change this. Through testing we have found that 512 produces good accuracy and speed and has therefore been chosen as the default.

THANK YOU FOR USING CLONIE
--checksumSolutions
