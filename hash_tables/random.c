// 
// 24.04.2025

#include "random.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long random_range(long min, long max) {
    return min + (double) rand() / RAND_MAX * (max - min + 1);
}
