#include "raytracer.h"
#include <iostream>
#include <cmath>

double get_angle( point a, point b ){
  return atan2((b.y-a.y),(b.x-a.x));
}

void raytracer( point grid_start, point grid_end, point source, point reciever, double angle, double box_width, double box_heigth, int cols, int rows ){
  int i=1;
  while( box_heigth*i <= source.y ){
    i++;
  }
  i -= 1;
  
  double result[rows][cols];
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      result[i][j] = 0;
    }
  }
  
  box b;
  b.ix = 0;
  b.iy = i;
  b.start.x = 0;
  b.start.y = 0;
  b.end.x = box_width;
  b.end.y = box_heigth;
  b.ray_source.y = source.y - i*box_heigth;
  b.ray_source.x = 0;
  b.angle = angle;
  while(b.ix < cols and b.iy < rows){
    int prevx,prevy;
    prevx = b.ix;
    prevy = b.iy;
    point p = tracebox(b);
    b.ray_source = p;
    if( p.y == box_heigth and p.x == box_width ){
      b.ray_source.y = 0;
      b.ray_source.x = 0;
    }
    else if( p.y == box_heigth ){
      b.ray_source.y = 0;
    }
    else if( p.x == box_width ){
      b.ray_source.x = 0;
    }
    else if( p.y == 0 ){
      b.ray_source.y = box_heigth;
    }
    result[prevx][prevy] = b.ray_length;
  }

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      cout << result[i][j] << "\t";
    }
    cout << endl;
  }
}
