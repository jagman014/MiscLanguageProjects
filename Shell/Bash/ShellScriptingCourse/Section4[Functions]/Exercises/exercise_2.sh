#!/bin/bash

CURRENT_DIR=$(pwd)

function file_count() {
    local FILES=$(ls $1)
    local COUNT=0
    
    cd $1

    for FILE in $FILES
    do
        if [ -f $FILE ]
        then
            COUNT=$(($COUNT + 1))
        fi
    done

    echo "Number of files in $1:"
    echo "$COUNT"

    cd $CURRENT_DIR
}

file_count /etc
file_count /var
file_count /usr/bin

function file_count_alt() {
    echo "Number of files in $1:"
    wc -w <<< "$(ls --file-type $1 | grep -v /)"
}

file_count_alt /etc
file_count_alt /var
file_count_alt /usr/bin
