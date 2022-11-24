#!/bin/bash


# conditions use [ <condition> ]
# help test / man test to get example of tests

# if statement
MY_SHELL="bash"

if [ "$MY_SHELL" = "bash" ]
then
    echo "using bash shell"
elif [ "$MY_SHELL" = "csh" ]
then
    echo "using csh shell"
else
    echo "not using bash ir csh shell"
fi

# for loop
COLOURS="red green blue"

for COLOUR in $COLOURS
do
    echo "COLOUR: $COLOUR"
done

# command line parameters stored in $0 - $9
echo "script: $0"
echo "param 1: $1"

# access all using $@
for PARAM in $@
do
    echo "printing param $PARAM"
done

# accept user input using read
read -p "PROMPT: " VAR

echo $VAR
