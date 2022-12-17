#include "eulers.h"

point_t* simple_eulers(function_ptr_t derivative, point_t point, double h, unsigned int steps)
{
    point_t* points = malloc(sizeof(point_t) * (steps + 1));
    points[0] = point;

    for (int i = 1; i <= steps; i++)
    {
        // find derivative at that point
        double derivative_value = (*derivative)(point.x, point.y);
        
        // create point with new x, and estimate new y using derivative
        point.x = point.x + h;
        point.y = point.y + h * derivative_value;
        points[i] = point;
    }

    return points;
}

point_t* improved_eulers(function_ptr_t derivative, point_t point, double h, unsigned int steps)
{
    point_t* points = malloc(sizeof(point_t) * (steps + 1));
    points[0] = point;
    points[1] = simple_eulers(derivative, point, h, 1)[1];

    for (int i = 2; i <= steps; i++)
    {
        // get points before current one
        point_t p_1 = points[i - 1];
        point_t p_2 = points[i - 2];

        // find derivative at that point
        double derivative_value = (*derivative)(p_1.x, p_1.y);
        
        // create point with new x, and estimate new y using derivative
        p_1.x = p_1.x + h;
        p_1.y = p_2.y + 2 * h * derivative_value;
        points[i] = p_1;
    }

    return points;
}

point_t* improved_improved_eulers(function_ptr_t derivative, point_t point, double h, unsigned int steps)
{
    point_t* points = malloc(sizeof(point_t) * (steps + 1));
    points[0] = point;
    points[1] = simple_eulers(derivative, point, h, 1)[1];

    for (int i = 2; i <= steps; i++)
    {
        // get points before current one
        point_t p_1 = points[i - 1];
        point_t p_2 = points[i - 2];

        // find derivative average between last two points
        double k_1 = (*derivative)(p_1.x, p_1.y);
        double k_2 = (*derivative)(p_2.x, p_2.y);
        double avg = (k_1 + k_2) / 2;

        // use y_r+1 = y_r + h (k_1 + k_2)/2
        p_1.x = p_1.x + h;
        p_1.y = p_1.y + h * avg;
        points[i] = p_1;
    }

    return points;
}