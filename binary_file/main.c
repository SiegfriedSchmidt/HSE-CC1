//
// 01.02.2025

#include "main.h"
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#define FILE_PATH "D:/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"

const int FIELD_SIZE = sizeof(struct Field);

void print_table_head() {
    wprintf(L"%-*ls%-*ls%-*ls%-*ls%-*ls\n", 40, L"ФИО", 14, L"Дата рождения", 20, L"Звание", 8, L"ВУС", 5, L"Рота");
}

// void print_with_indent(const wchar_t string[256], const int length) { wprintf(L"%*s", length, string); }

void print_field_data(const struct Field field) {
    wprintf(L"%-*ls", 40, field.name);

    char str_date[11];
    sprintf(str_date, "%d.%d.%d", field.date.day, field.date.month, field.date.year);
    printf("%-*s", 14, str_date);

    wprintf(L"%-*ls", 20, field.rank);
    wprintf(L"%-*ls", 8, field.specialty);
    wprintf(L"%-*d", 5, field.company);
}

void print_field(const struct Field field) {
    print_table_head();
    print_field_data(field);
}

struct Field create_field() {}

void write_to_binary_file(const struct Field field) {
    FILE *fptr = fopen(FILE_PATH, "wb");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    fwrite(&field, FIELD_SIZE, 1, fptr);
    fclose(fptr);
}

void read_binary_file() {
    FILE *fptr = fopen(FILE_PATH, "rb");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    printf("File content:\n");
    rewind(fptr);
    while (!feof(fptr)) {
        struct Field field;
        fread(&field, FIELD_SIZE, 1, fptr);
        if (!feof(fptr))
            print_field(field);
    }

    fclose(fptr);
}

int main() {
    setlocale(LC_ALL, "");

    struct Field field = {L"Иванов Иван Иваночик", {1, 1, 2030}, L"general", L"999000A", 9};
    write_to_binary_file(field);
    read_binary_file(field);

    return 0;
}
