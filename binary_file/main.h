//
// 01.02.2025
#ifndef MAIN_H
#define MAIN_H

struct Date {
    short int day;
    short int month;
    short int year;
};

struct Field {
    char name[128];
    struct Date date;
    char rank[32];
    char specialty[10];
    short int company;
};



#endif // MAIN_H
