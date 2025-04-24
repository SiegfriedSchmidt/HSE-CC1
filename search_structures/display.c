// 
// 24.04.2025

#include "display.h"
#include <stdio.h>
#include "record.h"

void print_table_head() {
    printf("%-*s%-*s%-*s%-*s%-*s%-*s\n", 12, "№", 43, "ФИО", 26, "Дата рождения", 26, "Звание", 11, "ВУС", 9, "Рота");
}

void print_record_data(const Record *record, const int index) {
    char str_index[10];
    sprintf(str_index, "%d.", index);
    printf("%-*s", 10, str_index);

    printf("%-*s", 40, record->name);

    char str_date[12];
    sprintf(str_date, "%d.%d.%d", record->date.day, record->date.month, record->date.year);
    printf("%-*s", 14, str_date);

    printf("%-*s", 20, record->rank);
    printf("%-*s", 8, record->specialty);
    printf("%-*d\n", 5, record->company);
}
