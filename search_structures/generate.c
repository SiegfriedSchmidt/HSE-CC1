// 
// 24.04.2025

#include "generate.h"
#include "record.h"
#include "random.h"
#include <stdio.h>
#include <string.h>


Record generate_record() {
    Record record = {};
    record.date.day = random_range(1, 30);
    record.date.month = random_range(1, 12);
    record.date.year = random_range(1970, 2025);

    sprintf(record.specialty, "%ld", random_range(100000, 999999));
    record.specialty[6] = 'A' + random_range(0, 10);
    record.specialty[7] = '\0';

    record.company = random_range(1, 30);

    char *first_name = first_names[random_range(0, sizeof(first_names) / sizeof(first_names[0]) - 1)];
    char *middle_name = middle_names[random_range(0, sizeof(middle_names) / sizeof(middle_names[0]) - 1)];
    char *last_name = last_names[random_range(0, sizeof(last_names) / sizeof(last_names[0]) - 1)];
    sprintf(record.name, "%s %s %s", first_name, middle_name, last_name);

    sprintf(record.rank, "%s", specialties[random_range(0, sizeof(specialties) / sizeof(specialties[0]) - 1)]);

    return record;
}
