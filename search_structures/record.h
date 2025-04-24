// 
// 24.04.2025

#ifndef RECORD_H
#define RECORD_H

typedef struct Date {
    short int day;
    short int month;
    short int year;
} Date;

typedef struct Record {
    char name[192];
    Date date;
    char rank[32];
    char specialty[10];
    short int company;
} Record;

extern const char *first_names[48];
extern const char *middle_names[48];
extern const char *last_names[48];
extern const char *specialties[7];

typedef int (*cmp_type)(const Record *, const Record *);

int cmp_ascending(const Record *lhs, const Record *rhs);

int cmp_descending(const Record *lhs, const Record *rhs);

void swap(Record *a, Record *b);

#endif //RECORD_H
