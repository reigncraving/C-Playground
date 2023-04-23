#include <stdio.h>

struct packed_data {
    /* unnamed field for padding */
    unsigned int : 3;
    /* specify number of bits after the : */
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
    /* cannot get address of a bitfield */
};

int main(void) {
    struct packed_data package;

    unsigned int bit = package.type;
    
    unsigned int i = package.index / 6 + 1;

    

    return 0;
}