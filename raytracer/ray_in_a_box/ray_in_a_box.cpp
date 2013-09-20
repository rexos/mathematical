#include <iostream>
#include <cmath>
#include "tracebox.h"

using namespace std;

int main(){
  box b = create_box();
  point reciever = tracebox( b );
  cout << reciever.x << "   " << reciever.y << endl;
  cout << "Ray length: " << b.ray_length << endl;
  cout << "Next box: " << b.ix << " " << b.iy << endl;
  return 0;
}

