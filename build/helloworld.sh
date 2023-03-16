#!/bin/bash  

source ./build/colors.sh

echo -e "${BLUE}[Compiling...]" 
echo -e "${GREEN}> ${PURPLE}Helloworld program."
gcc -g -Wall helloworld/helloworld.c -o helloworld/helloworld
echo -e "${BLUE}[run]\n${GREEN}"
./helloworld/helloworld