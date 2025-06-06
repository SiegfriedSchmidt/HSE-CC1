// 
// 24.04.2025

#include "record.h"

#include <string.h>

const char *first_names[] = {
    "Ivanov", "Petrov", "Sidorov", "Kozlova", "Smirnov", "Volkova", "Fedorov", "Morozova", "Pavlov", "Gusev",
    "Kuznetsova", "Nikolaev", "Orlova", "Borisov", "Egorova", "Klimenko", "Zaitsev", "Vinogradova", "Sokolov", "Belova",
    "Karpov", "Golubeva", "Tarasov", "Kovaleva", "Melnikov", "Savchenko", "Frolov", "Gavrilova", "Kazakov", "Polyakova",
    "Yakovleva", "Gorshkov", "Bogdanova", "Korneev", "Romanova", "Semyonov", "Kulikova", "Grachev", "Potapova", "Krylov",
    "Filippova", "Belyaev", "Davydova", "Kuzmin", "Sorokina", "Tkachev", "Kiseleva", "Mironov",
    "Lebedev", "Vasilieva", "Medvedev", "Kravchenko", "Isaev", "Novikova", "Zhukov", "Titova", "Komarov", "Belyakova",
    "Kotov", "Stepanova", "Yashin", "Lapina", "Guryev", "Markova", "Voronin", "Soboleva", "Timofeev", "Osipova",
    "Kryukov", "Vlasova", "Solovyov", "Filatova", "Makarov", "Rodionova", "Afanasiev", "Zakharova", "Ignatov", "Fomina",
    "Danilov", "Maslova", "Simonov", "Kalinina", "Fadeev", "Gerasimova", "Maksimov", "Sviridova", "Nikitin", "Vorontsova",
    "Vasiliev", "Gorbacheva", "Prokhorov", "Shcherbakova", "Sergeev", "Maltseva", "Mikhailov", "Ustinova", "Tsvetkov", "Gromova",
    "Efimov", "Lobanova", "Kolesnikov", "Komissarova", "Ponomarev", "Vasnetsova", "Voronkov", "Gavrilova", "Korolev", "Korneeva",
    "Goncharov", "Voronova", "Kulakov", "Kuznetsov", "Sorokin", "Tkacheva", "Kiselev", "Mironova", "Lebedeva", "Vasiliev",
    "Medvedeva", "Kravchuk", "Isaeva", "Novikov", "Zhukova", "Titov", "Komarova", "Belyakov", "Kotova", "Stepanov",
    "Yashina", "Lapin", "Guryeva", "Markov", "Voronina", "Sobolev", "Timofeeva", "Osipov", "Kryukova", "Vlasov",
    "Solovyova", "Filatov", "Makarova", "Rodionov", "Afanasieva", "Zakharov", "Ignatova", "Fomin", "Danilova", "Maslov",
    "Simonova", "Kalinin", "Fadeeva", "Gerasimov", "Maksimova", "Sviridov", "Nikitina", "Vorontsov", "Vasilieva", "Gorbachev"
};

const char *middle_names[] = {
    "Aleksandr", "Dmitriy", "Mikhail", "Anna", "Pavel", "Ekaterina", "Artem", "Olga", "Denis", "Igor",
    "Maria", "Vladimir", "Tatiana", "Stanislav", "Irina", "Andrei", "Grigoriy", "Elena", "Vitaliy", "Yulia",
    "Anton", "Darya", "Nikita", "Veronika", "Vadim", "Alina", "Roman", "Kristina", "Artyom", "Marina",
    "Elizaveta", "Denis", "Anastasiya", "Pavel", "Viktoriya", "Igor", "Yana", "Maksim", "Darya", "Anton",
    "Ekaterina", "Andrei", "Olga", "Mikhail", "Anna", "Denis", "Irina", "Pavel",
    "Lev", "Svetlana", "Timur", "Margarita", "Matvey", "Valeriya", "Fyodor", "Larisa", "Kirill", "Polina",
    "Semen", "Galina", "Yevgeniy", "Lyudmila", "Arkadiy", "Nadezhda", "Boris", "Raisa", "Vsevolod", "Tamara",
    "Georgiy", "Zoya", "Anatoliy", "Kseniya", "Valentin", "Lyubov", "Oleg", "Snezhana", "Vasiliy", "Yelena",
    "Leonid", "Inna", "Stepan", "Valentina", "Yaroslav", "Oksana", "Ruslan", "Albina", "Vladislav", "Eleonora",
    "Gennadiy", "Karina", "Konstantin", "Liliya", "Nikolay", "Regina", "Platon", "Sofiya", "Rodion", "Alla",
    "Svyatoslav", "Yaroslava", "German", "Bogdana", "David", "Varvara", "Ilya", "Diana", "Mark", "Camilla",
    "Eduard", "Elvira", "Innokentiy", "Ilona", "Klim", "Lilia", "Miroslav", "Mirra", "Nazar", "Nina",
    "Ostap", "Rosa", "Panteleimon", "Susanna", "Rostislav", "Ulyana", "Savva", "Faina", "Spartak", "Flora",
    "Trofim", "Elmira", "Yefim", "Agniya", "Yuliy", "Alevtina", "Zakhar", "Vasilisa", "Luka", "Lydia",
    "Mstislav", "Natalya", "Prokhor", "Rimma", "Samson", "Stefaniya", "Tikhon", "Ada", "Frol", "Agnia"
};

const char *last_names[] = {
    "Andreevich", "Sergeevich", "Vladimirovich", "Nikolaevna", "Olegovich", "Dmitrievna", "Igorevich", "Viktorovna", "Konstantinovich", "Petrovich",
    "Alekseevna", "Andreevich", "Sergeevna", "Dmitrievich", "Olegovna", "Nikolaevich", "Vladimirovich", "Pavlovna", "Igorevich", "Mikhailovna",
    "Vadimovich", "Andreevna", "Sergeevich", "Dmitrievna", "Olegovich", "Nikolaevna", "Vladimirovich", "Igorevna", "Pavlovich", "Viktorovna",
    "Andreevna", "Sergeevich", "Dmitrievna", "Olegovich", "Nikolaevna", "Vladimirovich", "Igorevna", "Petrovich", "Alekseevna", "Dmitrievich",
    "Sergeevna", "Nikolaevich", "Vladimirovna", "Igorevich", "Pavlovna", "Olegovich", "Andreevna", "Viktorovich",
    "Anatolievich", "Valerievna", "Bogdanovich", "Gennadievna", "Vasilievich", "Denisovna", "Georgievich", "Yevgenievna", "Danilovich", "Ilinichna",
    "Efimovich", "Kirillovna", "Zakharovich", "Leonidovna", "Ippolitovich", "Maksimovna", "Leontievich", "Olegovna", "Makarovich", "Platonovna",
    "Naumovich", "Romanovna", "Ostapovich", "Stanislavovna", "Pavlovich", "Timurovna", "Rodionovich", "Fedorovna", "Savelievich", "Kharitonovna",
    "Tarasovich", "Yaroslavovna", "Filippovich", "Vadimovna", "Kharitonovich", "Vasilievna", "Yakovlevich", "Glebovna", "Yanovich", "Davydovna",
    "Artemovich", "Zakharovna", "Borisovich", "Ignatievna", "Vitalievich", "Lvovna", "Glebovich", "Matveevna", "Davidovich", "Nikolaevna",
    "Yegorovich", "Pavlovna", "Zinovievich", "Rostislavovna", "Iosifovich", "Svyatoslavovna", "Lvovich", "Tikhonovna", "Mironovich", "Filippovna",
    "Nikitich", "Yurievna", "Osipovich", "Eduardovna", "Prokhorovich", "Yefimovna", "Ruslanovich", "Vitalievna", "Semenovich", "Vsevolodovna",
    "Timofeevich", "Georgievna", "Fomich", "Innokentievna", "Kuzmich", "Klimovna", "Larionovich", "Mironovna", "Maksimovich", "Naumovna",
    "Nazarovich", "Ostapovna", "Panteleimonovich", "Prokhorovna", "Savvich", "Rodionovna", "Samsonovich", "Savelievna", "Spartakovich", "Tarasovna",
    "Trofimovich", "Timofeevna", "Frolovich", "Fominichna", "Kharitonovich", "Kharitonovna", "Yefimovich", "Yakovlevna"
};

const char *specialties[] = {
    "Ryadovoy", "Efreytor", "Serzhant", "Leytenant", "Kapitan", "Mayor", "Polkovnik"
};

int cmp_ascending(const void *lhs_void, const void *rhs_void) {
    const Record *lhs = (Record *) lhs_void;
    const Record *rhs = (Record *) rhs_void;

    int string_comp = strcmp(lhs->name, rhs->name);
    if (string_comp > 0) return 1;
    if (string_comp < 0) return -1;

    if (lhs->date.year > rhs->date.year) return 1;
    if (lhs->date.year < rhs->date.year) return -1;

    if (lhs->date.month > rhs->date.month) return 1;
    if (lhs->date.month < rhs->date.month) return -1;

    if (lhs->date.day > rhs->date.day) return 1;
    if (lhs->date.day < rhs->date.day) return -1;

    string_comp = strcmp(lhs->rank, rhs->rank);
    if (string_comp > 0) return 1;
    if (string_comp < 0) return -1;

    string_comp = strcmp(lhs->specialty, rhs->specialty);
    if (string_comp > 0) return 1;
    if (string_comp < 0) return -1;

    if (lhs->company > rhs->company) return 1;
    if (lhs->company < rhs->company) return -1;
    return 0;
}

int cmp_descending(const void *lhs_void, const void *rhs_void) {
    const Record *lhs = (Record *) lhs_void;
    const Record *rhs = (Record *) rhs_void;

    return -cmp_ascending(lhs, rhs);
}

void swap(Record *a, Record *b) {
    const Record tmp = *a;
    *a = *b;
    *b = tmp;
}
