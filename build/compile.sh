#!/bin/bash

source ./build/colors.sh
source ./build/c_standard.sh


# Compile C source file or files
echo -e "${BLUE}[Compiling...]" 

if (( $# > 1 )); then
    echo -e "${BLUE}Multiple source => ${WHITE}$# files."
    echo -e "${BLUE}Note: ${PURPLE}main.c${WHITE} must be first argument."
    # Pass as parameter main file.
    echo -e "${GREEN}> $1 ${PURPLE}"

    # Get main source file:
    FILE_NAME=$(echo "$1" | cut -f 1 -d '.')
    SOURCES=()

    for arg in "$@"
    do
        if ! [ "$arg" = "$1" ]; then
            SOURCES+=" $arg"
        fi
    done
    echo -e "#<$SOURCES>"
    
    # compile all files:
    gcc "$FILE_NAME".c $SOURCES -Wall -g -std=$C_STANDARD -o "$FILE_NAME".o -lm
    echo -e "${BLUE}[run]\n${GREEN}"
    ./$FILE_NAME.o

else
    # Pass as parameter main file.
    echo -e "${GREEN}> ${PURPLE}$1"

    FILE_NAME=$(echo "$1" | cut -f 1 -d '.')
    gcc "$FILE_NAME".c -Wall -g -std=$C_STANDARD -o "$FILE_NAME".o -lm
    echo -e "${BLUE}[run]\n${GREEN}"
    ./$FILE_NAME.o
fi
