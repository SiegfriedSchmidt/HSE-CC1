//
// 01.02.2025

#include "main.h"
#include <fcntl.h>
#include <io.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define FILE_PATH "D:/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"

const int FIELD_SIZE = sizeof(struct Field);

void print_table_head() {
    wprintf(L"%-*ls%-*ls%-*ls%-*ls%-*ls\n", 40, L"ФИО", 14, L"Дата рождения", 20, L"Звание", 8, L"ВУС", 5, L"Рота");
}

void print_field_data(const struct Field field) {
    wprintf(L"%-*ls", 40, field.name);

    char str_date[12];
    sprintf(str_date, "%d.%d.%d", field.date.day, field.date.month, field.date.year);
    printf("%-*s", 14, str_date);

    wprintf(L"%-*ls", 20, field.rank);
    wprintf(L"%-*ls", 8, field.specialty);
    wprintf(L"%-*d\n", 5, field.company);
}

void print_field(const struct Field field) {
    print_table_head();
    print_field_data(field);
}

struct Date string_to_date(const char *str_date) {
    struct Date date = {};
    int idx_str = 0;
    int index_date_part = 0;
    char date_part[5];
    while (*str_date != '\0') {
        if (*str_date == '.') {
            if (index_date_part == 0) {
                char *endptr;
                date.day = strtol(date_part, &endptr, 10);
            } else if (index_date_part == 1) {
                date.month = date_part;
            } else {
                date.year = date_part;
            }

            idx_str = 0;
            ++index_date_part;
        } else {
            date_part[idx_str] = *str_date;
            ++idx_str;
        }

        ++str_date;
    }

    return date;
}

struct Field create_field() {
    struct Field field = {};
    wprintf(L"Добавьте запись\n");

    wprintf(L"ФИО:");
    fgetws(field.name, sizeof(field.name) / 2, stdin);
    fflush(stdin);

    wprintf(L"Дата рождения:");
    char str_date[12];
    fgetws(str_date, sizeof(str_date), stdin);
    fflush(stdin);
    field.date = string_to_date(str_date);

    wprintf(L"Звание:");
    fgetws(field.rank, sizeof(field.rank) / 2, stdin);
    fflush(stdin);
    wprintf(L"ВУС:");
    fgetws(field.specialty, sizeof(field.specialty) / 2, stdin);
    fflush(stdin);
    wprintf(L"Рота:");

    char str_company[10];
    char *endptr;
    fgetws(str_company, sizeof(str_company), stdin);
    fflush(stdin);
    field.company = strtol(str_company, &endptr, 10);

    return field;
}

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
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    setlocale(LC_ALL, "");

    // struct Field field = {L"Иванов Иван Иваночик", {1, 1, 2030}, L"general", L"999000A", 9};
    struct Field field = create_field();
    print_field(field);
    write_to_binary_file(field);
    read_binary_file(field);

    return 0;
}
