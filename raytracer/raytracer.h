#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "ray_in_a_box/tracebox.h"

using namespace std;

struct grid{
  point grid_start;
  point grid_end;
  point source;
  point reciever;
  int rows;
  int cols;
  double angle;
  double grid_width;
  double grid_heigth;
  double box_width;
  double box_heigth;
};


double ** raytracer( grid &g );
double get_angle( point a, point b );

#endif
