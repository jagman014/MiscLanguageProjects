#!/bin/bash

function file_count() {
    local FILES=$(ls $(pwd))

    local COUNT=0

    for FILE in $FILES
    do
        if [ -f "$FILE" ]
        then
            COUNT=$(($COUNT + 1))
        fi
    done

    echo "Number of files in current directory $(pwd):"
    echo "$COUNT"
}

file_count

function file_count_alt() {
    echo "Number of files in current directory $(pwd):"
    wc -w <<< "$(ls --file-type $(pwd) | grep -v [\/@])"
}

file_count_alt
