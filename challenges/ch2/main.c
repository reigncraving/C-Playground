#include <stdio.h> 

int sum(int number) {
    static int sum;
    sum = number + sum;

    return sum;
}

int main(void) {
    printf("%d\n", sum(25));
    printf("%d\n", sum(15));
    printf("%d\n", sum(30));

    return 0;
}