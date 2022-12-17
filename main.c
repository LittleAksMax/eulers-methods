#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eulers.h"
#include "points.h"

double function(double x, double y)
{
    return sin(x + y);
}

int main()
{
    // the function f'(x, y) = x - y goes through the point (1, 0)
    point_t initial = { .x = 1, .y = 0 };
    point_t* points1 = simple_eulers(&function, initial, 0.1, 3);
    point_t* points2 = improved_eulers(&function, initial, 0.1, 3);
    point_t* points3 = improved_improved_eulers(&function, initial, 0.1, 3);

    for (int i = 0; i < 4; i++)
    {
        point_t p1 = points1[i];
        point_t p2 = points2[i];
        point_t p3 = points3[i];
        printf("P1_%d(%lf, %lf); P2_%d(%lf, %lf); P3_%d(%lf, %lf)\n", i + 1, p1.x, p1.y, i + 1, p2.x, p2.y, i + 1, p3.x, p3.y);
    }

    return EXIT_SUCCESS;
}