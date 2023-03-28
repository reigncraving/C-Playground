#!/bin/bash  

source ./build/colors.sh

echo -e "${BLUE}[Compiling...]" 
echo -e "${GREEN}> ${PURPLE}Project1"

# adding aditional source files to be compiled: gcc one.c two.c -0 run
# or gcc *.c -0 run
gcc -g -Wall -std=c89 challenges/ch3/main.c \
challenges/ch3/display.c -o challenges/ch3/main.o

echo -e "${BLUE}[run]\n${GREEN}"
./challenges/ch3/main.o
