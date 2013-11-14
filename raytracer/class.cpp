#include <cblas.h>
#include "class.h"
#include <cstdlib>
#include <cmath>

void tracer::read_rays(){
  ifstream rays_read("16rays.txt");
  while( !rays_read.eof() ){
    pair<double,double> tmp;
    rays_read >> tmp.first >> tmp.second;
    rays.push_back(tmp);
    }
  rays_read.close();
}

void tracer::read_actual_times(){
  ifstream times_read("16raytime.txt");
  for( int i=0; i<g.rows*g.cols; i++ ){
    times_read >> actual_times[i];
  }
  times_read.close();
}

void tracer::read_velocities(){
  for( int i=0; i<g.rows; i++ ){
    for( int j=0; j<g.cols; j++ ){
      double asd  = (double)rand()/RAND_MAX;
      vel[i][j] = asd;
    }
  }
}

double tracer::get_likelihood( double * t ){
  double res ;
  double value = 0.0;
  for( int i=0; i<g.rows*g.cols; i++ ){
    double tmp = (t[i] - actual_times[i]);
    value += tmp;
  }
  value = ( value / (2*variance) ) * (-1);
  res = exp( value );
  return res;
}

/*
void tracer::read_velocities(){
  ifstream velocity_read("velocity.txt");
  for( int i=0; i<g.rows; i++ ){
    for( int j=0; j<g.cols; j++ ){
      velocity_read >> vel[i*g.rows + j];
      vel[i*g.rows + j] = 1/vel[i*g.rows + j];
    }
  }
  velocity_read.close();
  }
*/
void tracer::init_grid(){
  g.grid_start.x = g.grid_start.y = 0;
  g.grid_end.x = g.grid_end.y = 100;
  g.grid_width = g.grid_end.x - g.grid_start.x;
  g.grid_heigth = g.grid_end.y - g.grid_start.y;
  g.rows = g.cols = 4;
  g.box_width = g.grid_width / g.cols;
  g.box_heigth = g.grid_heigth / g.rows;
  g.source.x = g.grid_start.x;
  g.reciever.x = g.grid_end.x;
}

tracer::tracer(){
  // init grid
  init_grid();
  // init velocities array
  vel = new double*[g.rows];
  for( int i=0; i<g.rows; i++ ){
    vel[i] = new double[g.cols];
  }
  // init and read actual_times array
  actual_times = new double[g.rows*g.cols];
  read_actual_times();
  // read rays
  read_rays();
}

void tracer::run(){
  // read velocities
  read_velocities();
  ofstream out("raytime.txt");
  double *t = new double[rays.size()];
  for( int i = 0; i < rays.size(); ++i ){
    g.source.y = rays[i].first;
    g.reciever.y = rays[i].second;
    g.angle = get_angle(g.source,g.reciever); 
    t[i] = compute_total_time(vel,raytracer(g));
  }
  if( get_likelihood(t) > ((double)rand()/RAND_MAX) ){
    cout << "got" << endl;
  }
  
}
