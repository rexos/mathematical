#include <iostream>
#include "ray_in_a_box/tracebox.h"
#include "raytracer.h"
#include <fstream>
#include <utility>
#include <vector>


class tracer{
  grid g;
  double *vel;
  vector< pair<double,double> > rays;
  void read_rays();
  void read_velocities();
  void init_grid();

public:
  tracer();
  void run();
};
