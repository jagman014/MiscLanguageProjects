#!/bin/bash

if [ -f "$1" ]
then
    echo "This is a regular file"
    exit 0
elif [ -d "$1" ]
then
    echo "This is a directory"
    exit 1
else
    echo "This is some other type of file"
    exit 2
fi
