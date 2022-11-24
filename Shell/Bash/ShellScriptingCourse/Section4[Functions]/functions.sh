#!/bin/bash

# function definintion, function keyword is optional
# function function-name() {
#     # code
# }

function hello() {
    # function params with the same as script, excet $0 still being the script
    echo "Hello $1!"
    # function calls a separate function
    now
}

function now() {
    echo "It's $(date +%r)"
}

# call function without ()
hello Jag

# all varaibles by default are global
# variables defined in a function are not global until the function is called
my_func() {
    GLOBAL_VAR=1
}

# GLOBAL_VAR not available yet
echo $GLOBAL_VAR

my_func

# GLOBAL_VAR now available
echo $GLOBAL_VAR

# need to use local keyword to define local variables
# can only be used within a function
