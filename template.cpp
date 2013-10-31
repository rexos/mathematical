#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "/opt/local/include/boost/timer/timer.hpp"
using namespace std;

template <class U, class X>
X summ(X init, U first, U last ){
  while( first != last ){
    init = init + *first;
    first++;
  }
  return init;
}

int main(){
  vector<string> v(10,"asd");
  list<double> l;
  for( int i=0; i<10; i++ ){
    l.push_back(i+0.5);
  }
  string init = "";
  double res = 0;
  cout << summ(init,v.begin(),v.end()) << endl;
  cout << summ(res,l.begin(),l.end());
  return 0;
}
