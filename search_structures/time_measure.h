// 
// 24.04.2025

#ifndef TIME_MEASURE_H
#define TIME_MEASURE_H

typedef struct Result {
    char name[64];
    long size;
    double time;
} Result;

void time_measure(Result results[]);
#endif //TIME_MEASURE_H
