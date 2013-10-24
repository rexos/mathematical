#include <iostream>
#include "ray_in_a_box/tracebox.h"
#include "raytracer.h"
#include <fstream>
#include <utility>
#include <vector>

using namespace std;

double compute_total_time(double **vel, double **len){
  double total = 0;
  for( int i = 0; i<20; i++ ){
    for( int j=0; j<20; j++ ){
      total += ( len[i][j]/vel[j][i] );
    }
  }
  return total;
}

int main(){
  
  vector< pair<double,double> > rays;
  
  double **vel;
  vel = new double * [20];
  for( int i=0; i<20; i++ ){
    vel[i] = new double[20];
  }
  // read rays
  ifstream rays_read("rays.txt");
  while( !rays_read.eof() ){
    pair<double,double> tmp;
    rays_read >> tmp.first >> tmp.second;
    rays.push_back(tmp);
  }
  rays_read.close();
  
  // read velocities
  ifstream velocity_read("velocity.txt");
  for( int i=0; i<20; i++ ){
    for( int j=0; j<20; j++ ){
      velocity_read >> vel[i][j];
    }
  }
  velocity_read.close();

  grid g;

  g.grid_start.x = g.grid_start.y = 0;
  g.grid_end.x = g.grid_end.y = 100;
  g.grid_width = g.grid_end.x - g.grid_start.x;
  g.grid_heigth = g.grid_end.y - g.grid_start.y;
  g.rows = g.cols = 20;
  g.box_width = g.grid_width / g.cols;
  g.box_heigth = g.grid_heigth / g.rows;
  g.source.x = g.grid_start.x;
  g.reciever.x = g.grid_end.x;
  ofstream out("raytime.txt");
  for( vector< pair<double,double> >::iterator i = rays.begin(); i != rays.end(); ++i ){
    g.source.y = i->first;
    g.reciever.y = i->second;
    g.angle = get_angle(g.source,g.reciever); 
    out << compute_total_time(vel,raytracer(g)) << endl;
  }
  
  return 0;
}
