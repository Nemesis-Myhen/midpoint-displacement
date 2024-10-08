#include "midpoint displacement.h"

// Yes, this is from wikipedia.
double lerp(double v0, double v1, double t){
	return (1 - t) * v0 + t * v1;
}

/*
The size of the array has to be in the form of (2^n)+1 where n is a natural number.
Zero is not a natural number.
*/
void midpoint_displacement
(double* map, uint16_t begin, uint16_t end, double lower_rand_range, double upper_rand_range, double H) {
	uint16_t midpoint;
	double random_add;

	midpoint = (begin + end) / 2;
	random_add = (double)rand() / RAND_MAX;
	random_add = lerp(lower_rand_range, upper_rand_range, random_add);
	map[midpoint] = ((map[begin] + map[end]) / 2) + random_add;
	if (end - begin == 2) {
		return;
	}
	midpoint_displacement(map, midpoint, end, lower_rand_range * powl(2, -H), upper_rand_range * powl(2, -H), H);
	midpoint_displacement(map, begin, midpoint, lower_rand_range * powl(2, -H), upper_rand_range * powl(2, -H), H);
	return;
}