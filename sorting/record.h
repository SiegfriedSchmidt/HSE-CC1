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

int cmp(const struct Record *lhs, const struct Record *rhs);

#endif //RECORD_H
