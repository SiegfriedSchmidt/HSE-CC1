// 
// 10.04.2025

#ifndef RECORD_H
#define RECORD_H

struct Date {
    short int day;
    short int month;
    short int year;
};

struct Record {
    char name[192];
    struct Date date;
    char rank[32];
    char specialty[10];
    short int company;
};

extern const char *first_names[48];
extern const char *middle_names[48];
extern const char *last_names[48];
extern const char *specialties[7];

typedef int (*cmp_type)(const struct Record *, const struct Record *);

int cmp_ascending(const struct Record *lhs, const struct Record *rhs);

int cmp_descending(const struct Record *lhs, const struct Record *rhs);

void swap(struct Record *a, struct Record *b);

#endif //RECORD_H
