#!/bin/bash
# shebang points to the shell to run the script

# can execute any shell command
# need to use chmod to make script executable
echo "Scripting is fun!"

# variables use = with no spaces
VARIABLE_NAME="Value"

# use varaible with $
# use ${} to add to end of varaible
# varaible names can only contain [a-zA-Z0-9_]
echo "some ${VARIABLE_NAME}!"

# $() to use command
SERVER_NAME=$(hostname)

echo "running script on ${SERVER_NAME}"
