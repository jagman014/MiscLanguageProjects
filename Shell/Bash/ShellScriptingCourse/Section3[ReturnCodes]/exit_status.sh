#!/bin/bash

# error code 0 - 255
# 0 = success
# non-zero = error

# $? contains the return code of the previous command
ls /not/here
echo "$?"

HOST="google.com"
ping -c 1 $HOST

# can assign $? of previous command to a variable
RETURN_CODE=$?

# control exit status with "exit ##"
# excluding will return the exit status of last run command in script

if [ "$RETURN_CODE" -eq "0" ]
then
    echo "$HOST reachable"
    exit 0
else
    echo "$HOST unreachable"
    exit 1
fi

# && and, if previous command succeeds then the next command can happen
# || or, if previous command fails then the next command can happen
# ; to separate commands onto the same line
