//
// 01.02.2025

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "/mnt/d/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"
#define USE_ARRAY_DATA

const int FIELD_SIZE = sizeof(struct Field);

void clear_buffer() {
    while (getchar() != '\n')
        ;
}

void print_table_head() {
    printf("%-*s%-*s%-*s%-*s%-*s%-*s\n", 5, "№", 43, "ФИО", 26, "Дата рождения", 26, "Звание", 11, "ВУС", 9, "Рота");
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
    clear_buffer();

    return field;
}

void write_to_file(const int number_of_fields, const struct Field field[]) {
    FILE *fptr = fopen(FILE_PATH, "ab");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    printf("%ld", ftell(fptr));
    fwrite(field, FIELD_SIZE, number_of_fields, fptr);
    fclose(fptr);
}

void read_file() {
    FILE *fptr = fopen(FILE_PATH, "rb");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    print_table_head();
    rewind(fptr);

    int i = 1;
    while (!feof(fptr)) {
        struct Field field;
        fread(&field, FIELD_SIZE, 1, fptr);
        if (!feof(fptr)) {
            if (!field.deleted) {
                printf("%d. ", i++);
                print_field_data(field);
            }
        }
    }

    fclose(fptr);
}

void delete_from_file(const int index) {
    FILE *fptr = fopen(FILE_PATH, "ab");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }
    fseek(fptr, index * FIELD_SIZE, SEEK_SET);
    printf("%ld", ftell(fptr));

    struct Field field = {"---------------", {13, 6, 1994}, "Serzhant", "912345W", 3, 0};
    fwrite(&field, FIELD_SIZE, 1, fptr);
    fclose(fptr);
}

int main() {
    for (;;) {
        printf("Choose option (1..5):\n0.exit\n1.добавление записи в файл\n2.удаление заданной записи из файла по "
               "порядковому "
               "номеру записи\n3.поиск записей по заданному пользователем (любому) полю структуры\n4.редактирование "
               "(изменение) заданной записи\n5.вывод на экран содержимого файла в табличном виде\nOption:");

        int option;
        scanf("%d", &option);
        clear_buffer();

        if (option == 0) {
            printf("Exit.");
            break;
        }

        if (option == 1) {
#ifdef USE_ARRAY_DATA
            write_to_file(sizeof(Data) / FIELD_SIZE, Data);
#else
            const struct Field field[1] = {create_field()};
            write_to_file(1, field);
#endif
        } else if (option == 2) {
            printf("Input index: ");
            int index;
            scanf("%d", &index);
            clear_buffer();
            delete_from_file(index);
        } else if (option == 3) {

        } else if (option == 4) {

        } else if (option == 5) {
            read_file();
        } else {
            printf("Undefined option");
        }
        printf("\n\n");
    }


    return 0;
}
