#!/bin/bash  

BLUE='\033[0;34m'
WHITE='\033[0;37m' 
RED='\033[0;31m'
GREEN='\033[0;32m'
PURPLE='\033[0;35m'

echo -e "${BLUE}[Compiling...]" 
echo -e "${GREEN}> ${PURPLE}Helloworld program."
gcc -g -Wall helloworld/helloworld.c -o helloworld/helloworld
echo -e "${BLUE}[run]\n${GREEN}"
./helloworld/helloworld