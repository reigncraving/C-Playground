#include <stdio.h>

/* Global variable accessed only in this file: */
static double gd = 3.42;
float uniFloat = 1.32;
static int func (void) {
    printf("Static function defined");
    return 0;
}

int main() {
    /* int with block scope and temporary storage */
    int temp = 0;
    register int newTemp = temp + 1;
    static float lastTemp = 3.2;

    printf("Integer with temp scope %i, %p\n", temp, &temp);
    printf("Global double with file scope %.3f\n", gd);

    return 0;
}
