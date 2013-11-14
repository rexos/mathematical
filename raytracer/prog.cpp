#include <iostream>
#include "ray_in_a_box/tracebox.h"
#include "raytracer.h"
#include <fstream>
#include <utility>
#include <vector>
#include "class.h"
#include <cstdlib> 
#include <ctime>

using namespace std;

int main(){
  srand (time(NULL));
  tracer t = tracer();
  for( int i=0; i<100000; i++ ){
    t.run();
  }

  for( int i=0; i<t.g.rows; i++ ){
    for( int j=0; j<t.g.cols; j++ ){
      t.mean_vel[i][j] = t.mean_vel[i][j] / t.counter;
      cout << t.mean_vel[i][j] << "  ";
    }
    cout << endl;
  }
  


  return 0;
}
