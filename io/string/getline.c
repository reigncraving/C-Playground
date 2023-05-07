#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char *buffer = NULL;
    size_t buffer_size = 32;
    size_t string; 

    buffer = (char *)malloc(buffer_size * sizeof(char));

    if(buffer == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("Enter your input: ");
    string = getline(&buffer, &buffer_size, stdin);

    printf("Read: %zu\n", string);
    printf("You've typed: %s\n", buffer);

    free(buffer);

    /* Another approach */
    char b[32];
    char *ptrb = b;
    size_t bsize = 32;
    size_t chars;

    printf("Enter your input: ");
    chars = getline(&ptrb, &bsize, stdin);

    printf("Read: %zu\n", chars);
    printf("You've typed: %s\n", ptrb);

    return EXIT_SUCCESS;
}
