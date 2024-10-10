// https://docs.google.com/document/d/1TJW5jGTlKzkXdzWOiDLqjLShHOv8LqUA/edit

#include <stdio.h>
#include <stdlib.h>

double calculate_sequence_by_precision(double x, double precision);

double calculate_sequence_by_count(double x, long count);


int main(void) {
    // Буфер для ввода строки и указатель на последний неправильный символ
    char str[100];
    char *endptr;

    // Объявление x и way
    double x;
    char way;

    // Ввод x
    for (;;) {
        printf("Введите X: ");
        fgets(str, sizeof(str), stdin);
        x = strtod(str, &endptr);

        if (str[0] != '\n' && *endptr == '\n') {
            break;
        }

        printf("Неправильное значение!\n");
    }


    // Ввод way
    for (;;) {
        printf("Выберите способ расчета (1 или 2): ");
        fgets(str, sizeof(str), stdin);

        if ((str[0] == '1' || str[0] == '2') && str[1] == '\n') {
            way = str[0];
            break;
        }

        printf("Неправильное значение!\n");
    }

    double result;
    if (way == '1') {
        // точность
        long chars_after_comma;

        // Ввод precision
        for (;;) {
            printf("Введите количество знаков после запятой: ");
            fgets(str, sizeof(str), stdin);
            chars_after_comma = strtol(str, &endptr, 10);

            if (str[0] != '\n' && *endptr == '\n' && chars_after_comma >= 0) {
                break;
            }

            printf("Неправильное значение!\n");
        }

        double precision = 1;
        for (int i = 0; i <= chars_after_comma; i++) {
            precision /= 10;
        }

        result = calculate_sequence_by_precision(x, precision);
    } else {
        // количество членов ряда
        long count;

        // Ввод count
        for (;;) {
            printf("Введите количество членов ряда: ");
            fgets(str, sizeof(str), stdin);
            count = strtol(str, &endptr, 10);

            if (str[0] != '\n' && *endptr == '\n' && count > 0) {
                break;
            }

            printf("Неправильное значение!\n");
        }

        result = calculate_sequence_by_count(x, count);
    }

    printf("Результат: %0.32lf\n", result);
    return 0;
}

double absd(double x) {
    return (x < 0) ? -x : x;
}

double calculate_next_member(double last_member, double x, int *factorial_number) {
    return -last_member * (x * x) / ++(*factorial_number) / ++(*factorial_number);
}

double calculate_sequence_by_precision(double x, double precision) {
    double last_member = x;
    double seq = last_member;

    int factorial_number = 1; // Число факториала текущего члена последовательности
    while (absd(last_member) > precision) {
        last_member = calculate_next_member(last_member, x, &factorial_number);
        seq += last_member;
    }

    return seq;
}

double calculate_sequence_by_count(double x, long count) {
    double last_member = x;
    double seq = last_member;

    int factorial_number = 1; // Число факториала текущего члена последовательности
    for (int i = 0; i < count - 1; i++) {
        last_member = calculate_next_member(last_member, x, &factorial_number);
        seq += last_member;
    }

    return seq;
}
