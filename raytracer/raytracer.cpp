#include "raytracer.h"
#include <iostream>
#include <cmath>

double compute_total_time(double **vel, double **len){
  double total = 0;
  for( int i = 0; i<20; i++ ){
    for( int j=0; j<20; j++ ){
      total += ( len[i][j]/vel[j][i] );
    }
  }
  return total;
}

double get_angle( point a, point b ){
  return atan2((b.y-a.y),(b.x-a.x));
}

double ** raytracer( grid &g ){
  int i=1;
  while( g.box_heigth*i <= g.source.y ){
    i++;
  }
  i -= 1;
  
  double ** result;
  result = new double * [g.rows];
  for(int i=0; i<g.rows; i++){
    result[i] = new double[g.cols];
    for(int j=0; j<g.cols; j++){
      result[i][j] = 0;
    }
  }
  
  box b;
  b.ix = 0;
  b.iy = i;
  b.start.x = 0;
  b.start.y = 0;
  b.end.x = g.box_width;
  b.end.y = g.box_heigth;
  b.ray_source.y = g.source.y - i*g.box_heigth;
  b.ray_source.x = 0;
  b.angle = g.angle;
  while(b.ix < g.cols and b.iy < g.rows){
    int prevx,prevy;
    prevx = b.ix;
    prevy = b.iy;
    point p = tracebox(b);
    b.ray_source = p;
    if( p.y == g.box_heigth and p.x == g.box_width ){
      b.ray_source.y = 0;
      b.ray_source.x = 0;
    }
    else if( p.y == g.box_heigth ){
      b.ray_source.y = 0;
    }
    else if( p.x == g.box_width ){
      b.ray_source.x = 0;
    }
    else if( p.y == 0 ){
      b.ray_source.y = g.box_heigth;
    }
    result[prevx][prevy] = b.ray_length;
  }
  return result;
}
