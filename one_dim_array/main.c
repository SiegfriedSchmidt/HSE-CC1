#include <stdio.h>


void print_array(long arr[], long n) {
    for (int i = 0; i < n; i++) {
        printf("%ld ", arr[i]);
    }
}

long find_minimum(long arr[], long n, long x) {
    long min = (1ll << 32) - 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > x && arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

double find_average(long arr[], long n) {
    long l = 0, r = 0;

    // find left index
    for (long i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            l = i;
            break;
        }
    }

    // find right index
    for (long i = n - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            r = i;
            break;
        }
    }

    if (r - l - 1 <= 0) {
        return 0;
    }

    // find average
    long sum = 0;
    for (long i = l + 1; i < r; i++) {
        sum += arr[i];
    }

    return ((double) sum / (double) (r - l - 1));
}

int main(void) {
    long n, x;

    printf("Введите размер массива: ");
    scanf("%ld", &n);

    printf("Введите элементы массива: ");
    long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%ld", arr + i);
    }

    printf("Введите X: ");
    scanf("%ld", &x);

    printf("Минимум: %ld\n", find_minimum(arr, n, x));
    printf("Среднее: %lf\n", find_average(arr, n));

    return 0;
}
