//
// 01.02.2025

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "/mnt/d/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"
#define USE_ARRAY_DATA

const int RECORD_SIZE = sizeof(struct Record);

void clear_buffer() {
    while (getchar() != '\n')
        ;
}

void print_table_head() {
    printf("%-*s%-*s%-*s%-*s%-*s%-*s\n", 5, "№", 43, "ФИО", 26, "Дата рождения", 26, "Звание", 11, "ВУС", 9, "Рота");
}

void print_record_data(const struct Record record) {
    printf("%-*s", 40, record.name);

    char str_date[12];
    sprintf(str_date, "%d.%d.%d", record.date.day, record.date.month, record.date.year);
    printf("%-*s", 14, str_date);

    printf("%-*s", 20, record.rank);
    printf("%-*s", 8, record.specialty);
    printf("%-*d\n", 5, record.company);
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

struct Record create_record() {
    struct Record record = {};

    printf("Добавьте запись\n");

    printf("ФИО:");
    fgets(record.name, sizeof(record.name), stdin);
    record.name[strlen(record.name) - 1] = '\0';

    printf("Дата рождения:");
    char str_date[12];
    scanf("%s", &str_date);
    record.date = string_to_date(str_date);

    printf("Звание:");
    scanf("%s", &record.rank);
    printf("ВУС:");
    scanf("%s", &record.specialty);
    printf("Рота:");
    scanf("%hd", &record.company);
    clear_buffer();

    return record;
}

void write_to_file(const int number_of_records, const struct Record record[]) {
    FILE *fptr = fopen(FILE_PATH, "ab");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    printf("%ld", ftell(fptr));
    fwrite(record, RECORD_SIZE, number_of_records, fptr);
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
        struct Record record;
        fread(&record, RECORD_SIZE, 1, fptr);
        if (!feof(fptr)) {
            if (!record.deleted) {
                printf("%d. ", i++);
                print_record_data(record);
            }
        }
    }

    fclose(fptr);
}

int search_record(const int index) {
    FILE *fptr = fopen(FILE_PATH, "r");
    struct Record record;
    int file_index = 0;
    int search_index = 0;
    while (fread(&record, RECORD_SIZE, 1, fptr)) {
        if (!record.deleted) {
            ++file_index;
        }
        if (file_index == index) {
            break;
        }
        ++search_index;
    }
    fclose(fptr);
    return search_index;
}

void modify_record(const int index, const struct Record modified_record) {
    FILE *fptr = fopen(FILE_PATH, "r+b");

    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    int file_index = search_record(index);
    fseek(fptr, file_index * RECORD_SIZE, SEEK_SET);
    printf("%ld", ftell(fptr));
    fwrite(&modified_record, RECORD_SIZE, 1, fptr);
    fclose(fptr);
}

void delete_from_file(const int index) {
    const struct Record record = {"", {0, 0, 0}, "", "", 0, 1};
    modify_record(index, record);
}

int main() {
    for (;;) {
        printf("Choose option (1..5):\n0.exit\n1.добавление записи в "
               "файл\n2.удаление заданной записи из файла по "
               "порядковому "
               "номеру записи\n3.поиск записей по заданному пользователем (любому) "
               "полю структуры\n4.редактирование "
               "(изменение) заданной записи\n5.вывод на экран содержимого файла в "
               "табличном виде\nOption:");

        int option;
        scanf("%d", &option);
        clear_buffer();

        if (option == 0) {
            printf("Exit.");
            break;
        }

        if (option == 1) {
#ifdef USE_ARRAY_DATA
            write_to_file(sizeof(Data) / RECORD_SIZE, Data);
#else
            const struct Record record[1] = {create_record()};
            write_to_file(1, record);
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
