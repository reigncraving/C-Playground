#!/bin/bash  

source ./build/colors.sh

echo -e "${BLUE}[Compiling...]" 
echo -e "${GREEN}> ${PURPLE}Project1"

# adding aditional source files to be compiled: gcc one.c two.c -0 run
# or gcc *.c -0 run
gcc -g -Wall -std=c89 project1/sources/project1.c \
project1/sources/favorite_number.c -o project1/project1

echo -e "${BLUE}[run]\n${GREEN}"
./project1/project1