#include <iostream>
#include "ray_in_a_box/tracebox.h"
#include "raytracer.h"
#include <fstream>
#include <utility>
#include <vector>
#include "class.h" 

using namespace std;

int main(){
  tracer t = tracer();
  t.run();
  return 0;
}
