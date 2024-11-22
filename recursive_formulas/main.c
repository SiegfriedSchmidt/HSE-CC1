#include <stdio.h>
#include <stdlib.h>


// functions prototypes
double calculate_sequence_by_precision(double x, double precision);

double calculate_sequence_by_count(double x, long count);


int main(void) {
    // buffer for string
    char str[100];

    // pointer to last incorrect char (for string conversion)
    char *endptr;

    double x;
    char way;

    // input x
    for (;;) {
        printf("Input X: ");
        // get first 100 bytes (chars) from stdin
        fgets(str, sizeof(str), stdin);
        // string to double
        x = strtod(str, &endptr);

        // string is not empty and ends with line break
        if (str[0] != '\n' && *endptr == '\n') {
            break;
        }

        printf("Incorrect value!\n");
    }


    // input way
    for (;;) {
        printf("Select calculation method (1, 2): ");
        fgets(str, sizeof(str), stdin);

        if ((str[0] == '1' || str[0] == '2') && str[1] == '\n') {
            way = str[0];
            break;
        }

        printf("Incorrect value!\n");
    }

    double result;
    if (way == '1') {
        long chars_after_comma;

        // input precision
        for (;;) {
            printf("Input number of decimal places: ");
            fgets(str, sizeof(str), stdin);
            chars_after_comma = strtol(str, &endptr, 10);

            if (str[0] != '\n' && *endptr == '\n' && chars_after_comma >= 0) {
                break;
            }

            printf("Incorrect value!\n");
        }

        double precision = 1;
        for (int i = 0; i <= chars_after_comma; i++) {
            precision /= 10;
        }

        result = calculate_sequence_by_precision(x, precision);
    } else {
        // number of members
        long count;

        // input count
        for (;;) {
            printf("Input number of members: ");
            fgets(str, sizeof(str), stdin);
            count = strtol(str, &endptr, 10);

            if (str[0] != '\n' && *endptr == '\n' && count > 0) {
                break;
            }

            printf("Incorrect value!\n");
        }

        result = calculate_sequence_by_count(x, count);
    }

    printf("Result: %0.32lf\n", result);
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
    double seq_sum = last_member;

    int factorial_number = 1; // number of factorial of current member of sequence
    while (absd(last_member) > precision) {
        last_member = calculate_next_member(last_member, x, &factorial_number);
        seq_sum += last_member;
    }

    return seq_sum;
}

double calculate_sequence_by_count(double x, long count) {
    double last_member = x;
    double seq_sum = last_member;

    int factorial_number = 1; // number of factorial of current member of sequence
    for (int i = 0; i < count - 1; i++) {
        last_member = calculate_next_member(last_member, x, &factorial_number);
        seq_sum += last_member;
    }

    return seq_sum;
}
