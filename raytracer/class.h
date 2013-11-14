#include <iostream>
#include "ray_in_a_box/tracebox.h"
#include "raytracer.h"
#include <fstream>
#include <utility>
#include <vector>


class tracer{
  grid g;
  double **vel;
  double * actual_times;
  static const int variance = 100.0;
  vector< pair<double,double> > rays;
  void read_rays();
  void read_velocities();
  void init_grid();
  double get_likelihood( double * t );
  void read_actual_times();
  
public:
  tracer();
  void run();
};
