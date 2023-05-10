#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "./io/formating/out.txt"
#define APPEND_PATH "./io/formating/a.txt"
#define READ "r"
/* a as append and + for reading the whole file. */
#define APPEND "a+"
#define WRITE_OR_CREATE "wd"
#define MAX 41

int main(void) {
    /* sprintf */
    char string[100];


    sprintf(string, "Returnig a number %d", 55);
    puts(string);

    /* fsprintf */
    FILE *fileptr = NULL;
    char b[100];

    /* mode wb creates the the if not available. */
    if ((fileptr = fopen(FILE_PATH, WRITE_OR_CREATE)) == NULL) {
        printf("File does not exist");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < 10; i++) {
        fprintf(fileptr, "Count: %d\n",  i + 1);
    }

    fclose(fileptr);

    /* Read back from the file: */

    printf("=================READING FILE==================\n");

    if ((fileptr = fopen(FILE_PATH, READ)) == NULL) {
        printf("File does not exist");
        exit(EXIT_FAILURE);
    }

    while ((!feof(fileptr))) {
        fgets(b, 100, fileptr);
        printf("%s", b);
    }

    /* fscanf */
    printf("=================READING FILE FSCANF==================\n");


    FILE *fp = NULL;
    char buff[255];

    fp =fopen(FILE_PATH, READ);

    while (fscanf(fp, "%s", buff) != EOF) {
        printf("%s", buff);
    }

    fclose(fp); 

    /* Program to write words */
    printf("Writing words to file\n");

    char words[MAX];

    if ((fp = fopen(APPEND_PATH, APPEND)) == NULL) {
            fprintf(stderr, "File does not exist");
            exit(EXIT_FAILURE);
        }

    printf("\nEnter Word; press '#' ");
    printf("to terminate\n");
   while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
        fprintf(fp, "%s\n", words);
    }

    puts("File contains:");
    rewind(fp);

    while ((fscanf(fp, "%40s", words) == 1)) {
        puts(words);
    }

    puts("Done.");

    if (fclose(fp) != 0) {
        fprintf(stderr, "Error closing file");
    }

    /* sscanf */
/*     char *str = "John Doe 33";
    int age = 10;
    char firstname[20];
    char lastname[20];
    int ret = 0;

    ret = sscanf(str, "%s%s%d",firstname, lastname, age);

    printf("Firstname: %s\n", firstname);
    printf("Lastname: %s\n", lastname);
    printf("Age: %d\n", age);
    puts(ret); */

    return(EXIT_SUCCESS);
}
