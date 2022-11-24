#!/bin/bash

# return only accepts a number from 0-255
# like the return code of any other command, $?

function backup_file() {
    if [ -f $1 ]
    then
        # basename gets the basename of the file
        # +%F dormats the date in YYYY-MM-DD
        # $$ is the PID of the script
        local BACK="/tmp/$(basename ${1}).$(date +%F).$$"
        echo "Backing up $1 to ${BACK}"

        # exit status of the function will be the exit status of the cp command
        cp $1 $BACK
    else
        # file does not exist
        return 1
    fi
}

backup_file /etc/hosts

# make decision bases on the exit status
if [ $? -eq 0 ]
then
    echo "Backup succeeded"
else
    echo "Backup failed"
    # abort script and return non-zero exit code
    exit 1
fi
