//
// 01.02.2025
#ifndef MAIN_H
#define MAIN_H

struct Date {
    short int day;
    short int month;
    short int year;
};

struct Record {
    char name[128];
    struct Date date;
    char rank[32];
    char specialty[10];
    short int company;
    int deleted;
};

struct Record Data[48] = {
    {"Ivanov Aleksandr Andreevich", {12, 3, 1991}, "Ryadovoy", "154327F", 2},
    {"Petrov Dmitriy Sergeevich", {5, 7, 1988}, "Efreytor", "289143G", 4},
    {"Sidorov Mikhail Vladimirovich", {19, 11, 1995}, "Serzhant", "376512H", 1},
    {"Kozlova Anna Nikolaevna", {28, 2, 1993}, "Leytenant", "498765J", 3},
    {"Smirnov Pavel Olegovich", {14, 9, 1985}, "Kapitan", "512398K", 2},
    {"Volkova Ekaterina Dmitrievna", {3, 4, 1998}, "Mayor", "634871L", 4},
    {"Fedorov Artem Igorevich", {22, 6, 1990}, "Polkovnik", "712459M", 1},
    {"Morozova Olga Viktorovna", {7, 1, 1987}, "Leytenant", "845236N", 3},
    {"Pavlov Denis Konstantinovich", {17, 8, 1996}, "Serzhant", "923687P", 2},
    {"Gusev Igor Petrovich", {9, 5, 1992}, "Ryadovoy", "134529Q", 4},
    {"Kuznetsova Maria Alekseevna", {25, 12, 1989}, "Efreytor", "267453R", 1},
    {"Nikolaev Vladimir Andreevich", {11, 10, 1994}, "Kapitan", "389164S", 3},
    {"Orlova Tatiana Sergeevna", {6, 3, 1986}, "Mayor", "456237T", 2},
    {"Borisov Stanislav Dmitrievich", {30, 7, 1997}, "Polkovnik", "578912U", 4},
    {"Egorova Irina Olegovna", {13, 4, 1999}, "Leytenant", "691823V", 1},
    {"Klimenko Andrei Nikolaevich", {21, 2, 1991}, "Serzhant", "715438W", 3},
    {"Zaitsev Grigoriy Vladimirovich", {8, 6, 1988}, "Ryadovoy", "832769X", 2},
    {"Vinogradova Elena Pavlovna", {16, 11, 1995}, "Efreytor", "954317Y", 4},
    {"Sokolov Vitaliy Igorevich", {4, 9, 1993}, "Kapitan", "163842Z", 1},
    {"Belova Yulia Mikhailovna", {27, 1, 1987}, "Mayor", "247591A", 3},
    {"Karpov Anton Vadimovich", {18, 5, 1990}, "Polkovnik", "359176B", 2},
    {"Golubeva Darya Andreevna", {10, 8, 1996}, "Leytenant", "468235C", 4},
    {"Tarasov Nikita Sergeevich", {23, 3, 1989}, "Serzhant", "579324D", 1},
    {"Kovaleva Veronika Dmitrievna", {1, 12, 1994}, "Ryadovoy", "685412E", 3},
    {"Melnikov Vadim Olegovich", {14, 7, 1997}, "Efreytor", "796853F", 2},
    {"Savchenko Alina Nikolaevna", {6, 4, 1986}, "Kapitan", "813467G", 4},
    {"Frolov Roman Vladimirovich", {19, 10, 1992}, "Mayor", "924578H", 1},
    {"Gavrilova Kristina Igorevna", {29, 2, 1995}, "Polkovnik", "135689J", 3},
    {"Kazakov Artyom Pavlovich", {12, 6, 1988}, "Leytenant", "246791K", 2},
    {"Polyakova Marina Viktorovna", {7, 1, 1999}, "Serzhant", "357812L", 4},
    {"Yakovleva Elizaveta Andreevna", {15, 9, 1993}, "Ryadovoy", "982143M", 1},
    {"Gorshkov Denis Sergeevich", {24, 5, 1987}, "Efreytor", "129456N", 3},
    {"Bogdanova Anastasiya Dmitrievna", {3, 11, 1996}, "Serzhant", "234567P", 2},
    {"Korneev Pavel Olegovich", {17, 4, 1990}, "Leytenant", "345678Q", 4},
    {"Romanova Viktoriya Nikolaevna", {9, 8, 1995}, "Kapitan", "456789R", 1},
    {"Semyonov Igor Vladimirovich", {22, 3, 1989}, "Mayor", "567891S", 3},
    {"Kulikova Yana Igorevna", {11, 12, 1997}, "Polkovnik", "678912T", 2},
    {"Grachev Maksim Petrovich", {5, 7, 1992}, "Ryadovoy", "789123U", 4},
    {"Potapova Darya Alekseevna", {28, 2, 1998}, "Efreytor", "891234V", 1},
    {"Krylov Anton Dmitrievich", {13, 6, 1994}, "Serzhant", "912345W", 3},
    {"Filippova Ekaterina Sergeevna", {20, 10, 1988}, "Leytenant", "123456X", 2},
    {"Belyaev Andrei Nikolaevich", {4, 1, 1997}, "Kapitan", "234567Y", 4},
    {"Davydova Olga Vladimirovna", {17, 3, 1991}, "Mayor", "345678Z", 1},
    {"Kuzmin Mikhail Igorevich", {9, 5, 1989}, "Polkovnik", "456789A", 3},
    {"Sorokina Anna Pavlovna", {26, 8, 1996}, "Ryadovoy", "567891B", 2},
    {"Tkachev Denis Olegovich", {14, 12, 1993}, "Efreytor", "678912C", 4},
    {"Kiseleva Irina Andreevna", {7, 4, 1987}, "Serzhant", "789123D", 1},
    {"Mironov Pavel Viktorovich", {21, 7, 1998}, "Leytenant", "891234E", 3}
};


#endif // MAIN_H
