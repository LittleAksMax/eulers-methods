#ifndef _EULERS_H
#define _EULERS_H

#include <stdlib.h>
#include "points.h"

point_t* simple_eulers(function_ptr_t, point_t, double, unsigned int);
point_t* improved_eulers(function_ptr_t, point_t, double, unsigned int);
point_t* improved_improved_eulers(function_ptr_t, point_t, double, unsigned int);

#endif