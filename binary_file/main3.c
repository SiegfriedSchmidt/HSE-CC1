//
// 01.02.2025

#include <stdio.h>
#include <stdlib.h>

const char FILE_PATH[100] = "/mnt/d/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/text.txt";

FILE *open_file(char *mode) {
    FILE *fptr = fopen(FILE_PATH, mode);

    if (fptr == NULL) {
        printf("Error");
        exit(0);
    }
    return fptr;
}

int main() {
    FILE *fptr = open_file("r+");

    char mystring[99];
    fgets(mystring, 99, fptr);
    printf("%s", mystring);

    fprintf(fptr, mystring);

    fclose(fptr);

    return 0;
}
