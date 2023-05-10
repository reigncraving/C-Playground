#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUF 256

int has_ch(char ch, const char * line);
int find_and_print_line(const char *filepath, const char findchar);

/*
 * Finds and prints the line containig a char if mathc is found
 * 
 *  @param filepath [const char *] file to read.
 *  @param findchar [const char *] char to look for.
 */
int find_and_print_line(const char *filepath, const char findchar) {    
    FILE *fileptr = NULL;
    fileptr = fopen(filepath, "r");
    
    if(fileptr == NULL) {
        puts("Cannot open file.");
        exit(EXIT_FAILURE);
    }

    char b[BUF];
    char *line = b;
    size_t buffersize = BUF;
    size_t read;

    while((read = getline(&line, &buffersize, fileptr)) != EOF) {

        if ((has_ch(findchar, line))) { 
            fputs(line,stdout);
            fputs("\n", stdout);           
        
        }
    }

    fclose(fileptr);

    return (EXIT_SUCCESS);

}


/*
 * Checks to see if character is in a line and returns 1 if true
 * 
 *  @param ch [char]
 *  @param lin [const char *]
 */
int has_ch(const char ch, const char *line) {
    while(*line)
        if(ch == *line++)
            return 1;

    return 0;
}


int main(const int argc, const char *argv[])  {
    if(argc == 3) {
        const char findchar = argv[1][0];
        const char *filepath = argv[2];

        find_and_print_line(filepath, findchar);
       
        return(EXIT_SUCCESS);
    } else if(argc > 3) {
        puts("Too many arguments!");
        exit(EXIT_FAILURE);
    } else {
        puts("Two argument are require: character to look for (C char), filepath (String).");
        exit(EXIT_FAILURE);
    }
}
