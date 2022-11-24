#!/bin/bash

if [ -e $1 ]
then
    if [ -f $1 ]
    then
        echo "${1} is a regular file"
    elif [ -d $1 ]
    then
        echo "${1} is a directory"
    else
        echo "${1} is a different file type"
    fi
    ls -l $1
else
    echo "${1} does not exist"
fi
