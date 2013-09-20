#include <iostream>
#include <cmath>
#include <exception>
#include "tracebox.h"

using namespace std;

box create_box(){
  box b;
  cout << "Create the box" << endl;
  cout << "Bottom-Left corner: " << endl;
  cin >> b.start.x >> b.start.y;
  cout << "Top-Right corner: " << endl;
  cin >> b.end.x >> b.end.y;
  /*  try{
    cout << "Ray source:" << endl;
    cin >> b.ray_source.x >> b.ray_source.y;
    if( b.ray_source.x > b.end.x or b.ray_source.x < b.start.x or b.ray_source.y > b.end.y or b.ray_source.y < b.start.y ) {
      throw OutOfBoxException();
    }
  }
  catch( OutOfBoxException e ){
    manage_exception( e );
  }
  try{
    cout << "Angle: " << endl;
    cin >> b.angle;
  }
  catch( WrongAngleException e ) {
    cout << e.what() << endl;
    exit(0);
  }
  cout << "Box indexes: " << endl;
  cin >> b.ix >> b.iy;*/
  return b;
}

point tracebox( box &b ){
  point tmp, reciever;
  line top_edge, bottom_edge;
  top_edge.q = b.end.y;
  top_edge.m = 0;
  bottom_edge.q = b.start.y;
  bottom_edge.m = 0;
  double x = b.end.x;
  double base = x - b.ray_source.x;
  double heigth = base * tan( b.angle );
  tmp.x = b.end.x;
  tmp.y = b.ray_source.y + heigth;

  if( tmp.y > b.end.y ) {
    line l = generate_line( b.ray_source, tmp );
    reciever = calculate_intersection( top_edge, l );
    b.iy += 1;
  }
  else if( tmp.y < b.start.y ) {
    line l = generate_line( b.ray_source, tmp );
    reciever = calculate_intersection( bottom_edge, l );
    b.iy -= 1;
  }
  else {
    reciever = tmp;
    b.ix += 1;
  }
  b.ray_length = compute_length( b.ray_source, reciever );
  return reciever;
}

line generate_line( point a, point b ){
  line l;
  l.m = (b.y - a.y) / ( b.x - a.x );
  l.q = a.y - (l.m * a.x);
  return l;
}

point calculate_intersection( line a, line b ) {
  point intersection;
  intersection.y = a.q;
  intersection.x = (intersection.y - b.q) / b.m;
  return intersection;
}

double compute_length( point a, point b ) {
  double length;
  length = sqrt( pow((b.x - a.x),2) + pow( (b.y - a.y), 2 ) );
  return length;
}

