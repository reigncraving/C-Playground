#!/bin/bash

source "./build/colors.sh"

# Pass as parameter main file.
echo -e "${BLUE}[Compiling...]" 
echo -e "${GREEN}> ${PURPLE}$1"

FILE_NAME=$(echo "$1" | cut -f 1 -d '.')
gcc "$FILE_NAME".c -Wall -g -std=c89 -o "$FILE_NAME".o
echo -e "${BLUE}[run]\n${GREEN}"
./$FILE_NAME.o
