#include <stdio.h>
#include <stdlib.h>

int counter;
void display();

int main() {
    while(counter < 5) {
        display();
    }

    return 0;
}