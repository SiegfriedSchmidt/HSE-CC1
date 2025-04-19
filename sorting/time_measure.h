// 
// 19.04.2025

#ifndef TIME_MEASURE_H
#define TIME_MEASURE_H

struct Result {
    char name[64];
    long size;
    double time;
};

void time_measure(struct Result results[]);
#endif //TIME_MEASURE_H
