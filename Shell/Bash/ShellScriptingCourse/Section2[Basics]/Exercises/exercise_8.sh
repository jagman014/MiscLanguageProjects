#!/bin/bash

for FILE in $@
do
    if [ -e $FILE ]
    then
        if [ -f $FILE ]
        then
            echo "${FILE} is a regular file"
        elif [ -d $FILE ]
        then
            echo "${FILE} is a directory"
        else
            echo "${FILE} is a different file type"
        fi
        ls -l $FILE
    else
        echo "${FILE} does not exist"
    fi
done
