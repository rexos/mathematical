#include <iostream>
#include "ray_in_a_box/tracebox.h"
#include "raytracer.h"

using namespace std;

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
  
  raytracer(grid_start, grid_end, source, reciever, angle, box_width, box_heigth, cols, rows);

  return 0;
}
