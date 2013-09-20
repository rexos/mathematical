#include <iostream>
#include <cstdio>
#include <cmath>
#include "ray_in_a_box/tracebox.h"
#include "raytracer.h"

using namespace std;


double get_angle( point a, point b );
// MAIN

int main(){
  point grid_start, grid_end;
  int rows, cols;
  point source,reciever;
  double angle, grid_width, grid_heigth, box_width, box_heigth;
  cin >> grid_start.x;
  cin >> grid_start.y;
  cin >> grid_end.x; 
  cin >> grid_end.y;
  grid_width = grid_end.x - grid_start.x;
  grid_heigth = grid_end.y - grid_start.y;
  cout << "rows and columns  ";
  cin >> rows >> cols;
  cout << "ray_source y  ";
  cin >> source.y;
  source.x = grid_start.x;
  cout << "reciever y  ";
  cin >> reciever.y;
  reciever.x = grid_end.x;
  angle = get_angle(source,reciever);
  box_width = grid_width / cols;
  box_heigth = grid_heigth / rows;

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
    cout << "BLOCK : " << b.ix << " " << b.iy << endl;
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
    cout << "length : " << b.ray_length << endl;
    result[prevx][prevy] = b.ray_length;
  }

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      cout << result[i][j] << "\t";
    }
    cout << endl;
  }

  return 0;
}

// END 

double get_angle( point a, point b ){
  return atan2((b.y-a.y),(b.x-a.x));
}

