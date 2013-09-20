#ifndef RAYTRACER_H
#define RAYTRACER_H
#include "ray_in_a_box/tracebox.h"
#include <vector>
using namespace std;

struct grid{
  int width;
  int heigth;
  vector< vector<box> > map;
};

#endif
