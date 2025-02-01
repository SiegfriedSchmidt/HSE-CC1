//
// 01.02.2025

#include "main.h"
#include <locale.h>
#include <stdio.h>
#include <wchar.h>

#define FILE_PATH "/mnt/d/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"

void write_to_binary_file(struct Field field) {
    FILE *fptr = fopen(FILE_PATH, "wb");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    fwrite(&field, sizeof(double), 1, fptr);
    fclose(fptr);
}

int main() {
    setlocale(LC_ALL, "");
    wchar_t c = L'А';
    wprintf(L"%lc\n", c);

    struct Field field = {L"Иванов Иван Иваночик", {10, 10, 1715}, L"general", L"999000A", 9};
    printf("%lld\n", sizeof field);

    printf("%d\n", field.company);
    wprintf(L"%ls", field.name);

    return 0;
}
