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
  for( int i=0; i<10000; i++ ){
    t.run();
  }

  return 0;
}
