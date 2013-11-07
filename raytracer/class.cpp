#include <cblas.h>
#include "class.h"

void tracer::read_rays(){
  ifstream rays_read("rays.txt");
  while( !rays_read.eof() ){
    pair<double,double> tmp;
    rays_read >> tmp.first >> tmp.second;
    rays.push_back(tmp);
    }
  rays_read.close();
}

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

void tracer::init_grid(){
  g.grid_start.x = g.grid_start.y = 0;
  g.grid_end.x = g.grid_end.y = 100;
  g.grid_width = g.grid_end.x - g.grid_start.x;
  g.grid_heigth = g.grid_end.y - g.grid_start.y;
  g.rows = g.cols = 20;
  g.box_width = g.grid_width / g.cols;
  g.box_heigth = g.grid_heigth / g.rows;
  g.source.x = g.grid_start.x;
  g.reciever.x = g.grid_end.x;
}

tracer::tracer(){
  init_grid();
  // init velocities array
  vel = new double[g.rows*g.cols];
  // read rays
  read_rays();
  // read velocities
  read_velocities();
  //init grid
}

void tracer::run(){
  ofstream out("raytime.txt");
  int k = 0;
  //3D matrix initialization
  double ***data;
  data = new double ** [rays.size()];
  for( vector< pair<double,double> >::iterator i = rays.begin(); i != rays.end(); ++i ){
    g.source.y = i->first;
    g.reciever.y = i->second;
    g.angle = get_angle(g.source,g.reciever); 
    data[k] = raytracer(g);
    k++;
  }
  
  double *l = new double[g.rows*g.cols*rays.size()];
  for( int x=0; x<rays.size(); x++ ){
    for(int i=0; i<g.rows; i++){
      for( int j = 0; j<g.cols; j++ ){
	l[x*g.rows*g.cols + i*g.rows + j] = data[x][i][j];
      }
    }
  }
  double *t = new double[rays.size()];
  cblas_dgemv(CblasRowMajor, CblasNoTrans, rays.size(), g.rows*g.cols, 1.0, l, g.rows*g.cols, vel, 1, 0.0, t, 1);
  for(int i = 0; i < rays.size(); i++){
    out << t[i] << endl;
  }

  //WORKING
  /*
    for( vector< pair<double,double> >::iterator i = rays.begin(); i != rays.end(); ++i ){
    g.source.y = i->first;
    g.reciever.y = i->second;
    g.angle = get_angle(g.source,g.reciever); 
    out << compute_total_time(vel,raytracer(g)) << endl;
    }
  */
}
