#!/bin/bash  

source ./build/colors.sh

echo -e "${BLUE}[Compiling...]" 
echo -e "${GREEN}> ${PURPLE}Helloworld program."
gcc -g -Wall -std=c89 helloworld/helloworld.c -o helloworld/helloworld.o
echo -e "${BLUE}[run]\n${GREEN}"
./helloworld/helloworld.o
