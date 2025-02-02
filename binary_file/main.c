//
// 01.02.2025

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "/mnt/d/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"

const int FIELD_SIZE = sizeof(struct Field);

void print_table_head() {
    printf("%-*s%-*s%-*s%-*s%-*s\n", 43, "ФИО", 26, "Дата рождения", 26, "Звание", 11, "ВУС", 9, "Рота");
}

void print_field_data(const struct Field field) {
    printf("%-*s", 40, field.name);

    char str_date[12];
    sprintf(str_date, "%d.%d.%d", field.date.day, field.date.month, field.date.year);
    printf("%-*s", 14, str_date);

    printf("%-*s", 20, field.rank);
    printf("%-*s", 8, field.specialty);
    printf("%-*d\n", 5, field.company);
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
    for (;;) {
        if (*str_date == '.' || *str_date == '\0') {
            char *endptr;
            if (index_date_part == 0) {
                date.day = strtol(date_part, &endptr, 10);
            } else if (index_date_part == 1) {
                date.month = strtol(date_part, &endptr, 10);
            } else {
                date.year = strtol(date_part, &endptr, 10);
            }

            idx_str = 0;
            ++index_date_part;
        } else {
            date_part[idx_str] = *str_date;
            ++idx_str;
        }

        if (*str_date == '\0') {
            break;
        }
        ++str_date;
    }

    return date;
}

struct Field create_field() {
    struct Field field = {};
    printf("Добавьте запись\n");

    printf("ФИО:");
    fgets(field.name, sizeof(field.name), stdin);
    field.name[strlen(field.name) - 1] = '\0';

    printf("Дата рождения:");
    char str_date[12];
    scanf("%s", &str_date);
    field.date = string_to_date(str_date);

    printf("Звание:");
    scanf("%s", &field.rank);
    printf("ВУС:");
    scanf("%s", &field.specialty);
    printf("Рота:");
    scanf("%hd", &field.company);

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
    // struct Field field = {"Иванов Иван Иваночик", {1, 1, 2030}, "genera", "999000A", 9};
    struct Field field = create_field();

    print_field(field);
    write_to_binary_file(field);
    read_binary_file(field);

    return 0;
}
