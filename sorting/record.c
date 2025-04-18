// 
// 11.04.2025

#include "record.h"

#include <string.h>

const char *first_names[] = {
    "Ivanov", "Petrov", "Sidorov", "Kozlova", "Smirnov",
    "Volkova", "Fedorov", "Morozova", "Pavlov", "Gusev",
    "Kuznetsova", "Nikolaev", "Orlova", "Borisov", "Egorova",
    "Klimenko", "Zaitsev", "Vinogradova", "Sokolov", "Belova",
    "Karpov", "Golubeva", "Tarasov", "Kovaleva", "Melnikov",
    "Savchenko", "Frolov", "Gavrilova", "Kazakov", "Polyakova",
    "Yakovleva", "Gorshkov", "Bogdanova", "Korneev", "Romanova",
    "Semyonov", "Kulikova", "Grachev", "Potapova", "Krylov",
    "Filippova", "Belyaev", "Davydova", "Kuzmin", "Sorokina",
    "Tkachev", "Kiseleva", "Mironov"
};

const char *middle_names[] = {
    "Aleksandr", "Dmitriy", "Mikhail", "Anna", "Pavel",
    "Ekaterina", "Artem", "Olga", "Denis", "Igor",
    "Maria", "Vladimir", "Tatiana", "Stanislav", "Irina",
    "Andrei", "Grigoriy", "Elena", "Vitaliy", "Yulia",
    "Anton", "Darya", "Nikita", "Veronika", "Vadim",
    "Alina", "Roman", "Kristina", "Artyom", "Marina",
    "Elizaveta", "Denis", "Anastasiya", "Pavel", "Viktoriya",
    "Igor", "Yana", "Maksim", "Darya", "Anton",
    "Ekaterina", "Andrei", "Olga", "Mikhail", "Anna",
    "Denis", "Irina", "Pavel"
};

const char *last_names[] = {
    "Andreevich", "Sergeevich", "Vladimirovich", "Nikolaevna", "Olegovich",
    "Dmitrievna", "Igorevich", "Viktorovna", "Konstantinovich", "Petrovich",
    "Alekseevna", "Andreevich", "Sergeevna", "Dmitrievich", "Olegovna",
    "Nikolaevich", "Vladimirovich", "Pavlovna", "Igorevich", "Mikhailovna",
    "Vadimovich", "Andreevna", "Sergeevich", "Dmitrievna", "Olegovich",
    "Nikolaevna", "Vladimirovich", "Igorevna", "Pavlovich", "Viktorovna",
    "Andreevna", "Sergeevich", "Dmitrievna", "Olegovich", "Nikolaevna",
    "Vladimirovich", "Igorevna", "Petrovich", "Alekseevna", "Dmitrievich",
    "Sergeevna", "Nikolaevich", "Vladimirovna", "Igorevich", "Pavlovna",
    "Olegovich", "Andreevna", "Viktorovich"
};

const char *specialties[] = {
    "Ryadovoy", "Efreytor", "Serzhant", "Leytenant", "Kapitan", "Mayor", "Polkovnik"
};

int cmp_ascending(const struct Record *lhs, const struct Record *rhs) {
    int string_comp = strcmp(lhs->name, rhs->name);
    if (string_comp > 0) return 1;
    if (string_comp < 0) return 0;

    if (lhs->date.year > rhs->date.year) return 1;
    if (lhs->date.year < rhs->date.year) return 0;

    if (lhs->date.month > rhs->date.month) return 1;
    if (lhs->date.month < rhs->date.month) return 0;

    if (lhs->date.day > rhs->date.day) return 1;
    if (lhs->date.day < rhs->date.day) return 0;

    string_comp = strcmp(lhs->rank, rhs->rank);
    if (string_comp > 0) return 1;
    if (string_comp < 0) return 0;

    string_comp = strcmp(lhs->specialty, rhs->specialty);
    if (string_comp > 0) return 1;
    if (string_comp < 0) return 0;

    if (lhs->company > rhs->company) return 1;
    return 0;
}

int cmp_descending(const struct Record *lhs, const struct Record *rhs) {
    if (cmp_ascending(lhs, rhs) == 1) return 0;
    return 1;
}
