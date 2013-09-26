#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "ray_in_a_box/tracebox.h"

using namespace std;

void raytracer( point grid_start, point grid_end, point source, point reciever, double angle, double box_width, double box_heigth, int cols, int rows );
double get_angle( point a, point b );

#endif
