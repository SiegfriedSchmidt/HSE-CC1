//
// 01.02.2025
#ifndef MAIN_H
#define MAIN_H
#include <wchar.h>

struct Date {
    short int day;
    short int month;
    short int year;
};

struct Field {
    wchar_t name[128];
    struct Date date;
    wchar_t rank[32];
    wchar_t specialty[8];
    short int company;
};



#endif // MAIN_H
