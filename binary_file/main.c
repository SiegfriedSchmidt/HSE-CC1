//
// 01.02.2025

#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define FILE_PATH "/mnt/d/Users/Matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"
#define FILE_PATH "/Users/matvei/Developer/Projects/HSE-CC1/binary_file/data.bin"
#define USE_ARRAY_DATA

const int RECORD_SIZE = sizeof(struct Record);

typedef int (*search_func)(const struct Record *, const struct Record *);

typedef void (*read_func)(struct Record *);

void clear_buffer() {
    while (getchar() != '\n');
}

void print_table_head() {
    printf("%-*s%-*s%-*s%-*s%-*s%-*s\n", 6, "№", 43, "ФИО", 26, "Дата рождения", 26, "Звание", 11, "ВУС", 9, "Рота");
}

void print_record_data(const struct Record record, const int index) {
    char str_index[10];
    sprintf(str_index, "%d.", index);
    printf("%-*s", 4, str_index);

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

void read_name(struct Record *record) {
    printf("ФИО:");
    fgets(record->name, sizeof(record->name), stdin);
    record->name[strlen(record->name) - 1] = '\0';
}

void read_date(struct Record *record) {
    printf("Дата рождения:");
    char str_date[12];
    scanf("%s", &str_date);
    record->date = string_to_date(str_date);
}

void read_rank(struct Record *record) {
    printf("Звание:");
    scanf("%s", &record->rank);
}

void read_specialty(struct Record *record) {
    printf("ВУС:");
    scanf("%s", &record->specialty);
}

void read_company(struct Record *record) {
    printf("Рота:");
    scanf("%hd", &record->company);
}

struct Record create_record() {
    struct Record record = {};
    read_name(&record);
    read_date(&record);
    read_rank(&record);
    read_specialty(&record);
    read_company(&record);
    clear_buffer();

    return record;
}

void write_to_file(const int number_of_records, const struct Record record[]) {
    FILE *fptr = fopen(FILE_PATH, "ab");
    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

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
                print_record_data(record, i++);
            }
        }
    }

    fclose(fptr);
}

int search_record_by_index(const int index) {
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

void search_record_by_field(const struct Record search_record, const search_func *search) {
    FILE *fptr = fopen(FILE_PATH, "r");
    int file_index = 0;
    int search_index = 0;
    struct Record record;
    while (fread(&record, RECORD_SIZE, 1, fptr)) {
        if (!record.deleted) {
            ++file_index;
        }
        if ((*search)(&record, &search_record)) {
            print_record_data(record, file_index);
        }
        ++search_index;
    }
    fclose(fptr);
}

int search_name(const struct Record *cur_record, const struct Record *search_record) {
    return strcmp(cur_record->name, search_record->name) == 0;
}

int search_date(const struct Record *cur_record, const struct Record *search_record) {
    return cur_record->date.day == search_record->date.day && cur_record->date.month == search_record->date.month &&
           cur_record->date.year == search_record->date.year;
}

int search_rank(const struct Record *cur_record, const struct Record *search_record) {
    return strcmp(cur_record->rank, search_record->rank) == 0;
}

int search_specialty(const struct Record *cur_record, const struct Record *search_record) {
    return strcmp(cur_record->specialty, search_record->specialty) == 0;
}

int search_company(const struct Record *cur_record, const struct Record *search_record) {
    return cur_record->company == search_record->company;
}

void modify_record(const int index, const struct Record modified_record) {
    FILE *fptr = fopen(FILE_PATH, "r+b");

    if (fptr == NULL) {
        printf("Error\n");
        return;
    }

    int file_index = search_record_by_index(index);
    fseek(fptr, file_index * RECORD_SIZE, SEEK_SET);
    fwrite(&modified_record, RECORD_SIZE, 1, fptr);
    fclose(fptr);
}

void delete_from_file(const int index) {
    const struct Record record = {"", {0, 0, 0}, "", "", 0, 1};
    modify_record(index, record);
}

int main() {
    const search_func searching[5] = {search_name, search_date, search_rank, search_specialty, search_company};
    const read_func reading[5] = {read_name, read_date, read_rank, read_specialty, read_company};

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
            printf("Добавьте запись\n");
            write_to_file(1, record);
#endif
        } else if (option == 2) {
            printf("Input index: ");
            int index;
            scanf("%d", &index);
            clear_buffer();
            delete_from_file(index);
        } else if (option == 3) {
            printf("Поиск по (1..5):\n1.ФИО\n2.Дата\n3.Звание\n4.ВУС\n5.Номер роты\n");
            int search_option;
            scanf("%d", &search_option);
            clear_buffer();
            --search_option;

            struct Record record = {};
            (*reading[search_option])(&record);
            print_table_head();
            search_record_by_field(record, &searching[search_option]);
        } else if (option == 4) {
            printf("Input index: ");
            int index;
            scanf("%d", &index);
            clear_buffer();
            const struct Record record = create_record();
            modify_record(index, record);
        } else if (option == 5) {
            read_file();
        } else {
            printf("Undefined option");
        }
        printf("\n\n");
    }

    return 0;
}
