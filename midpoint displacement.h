#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

// Yes, this is from wikipedia.
double lerp
(double v0, double v1, double t);

/*
The size of the array has to be in the form of (2^n)+1 where n is a natural number.
Zero is not a natural number.
*/
void midpoint_displacement
(double* map, uint16_t begin, uint16_t end, double lower_rand_range, double upper_rand_range, double H);