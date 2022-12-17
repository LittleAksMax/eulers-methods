#ifndef _POINTS_H
#define _POINTS_H

typedef struct point {
    double x, y;
} point_t;

typedef double (*function_ptr_t)(double, double); // function_ptr_t(double x, double y) -> double
// for function_ptr_t, y parameter can just be 0 or not used.

#endif