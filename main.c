#include <stdlib.h>

int func() {

    static int count = 0;

    count++
    return count;
}

int main() {


    return 0;
}