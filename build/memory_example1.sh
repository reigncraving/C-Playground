#!/bin/bash  

source ./build/colors.sh

echo -e "${BLUE}[Compiling...]" 
echo -e "${GREEN}> ${PURPLE}Memory Twice program."
gcc -g -Wall -std=c89 memory_example1/main.c -o memory_example1/memory_example1.o
echo -e "${BLUE}[run]\n${GREEN}"
./memory_example1/memory_example1.o
