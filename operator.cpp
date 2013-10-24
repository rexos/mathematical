#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

struct data{
  int i; // integer part
  double d; // decimal part
};

bool operator<(data self, data other){
  if( self.i < other.i )
    return true;
  else if( self.i == other.i ){
    if( self.d < other.d )
      return true;
    else
      return false;
  }
  else
    return false;
}

ostream &operator<<(ostream &os , vector<data> &x) {
  for (vector<data>::iterator i = x.begin(); i != x.end(); i++) { 
    os << i->i << "." << i->d << endl ;
  }
  return os;
}

int main(){
  srand(time(NULL));
  vector<data> ary(10);
  for( int i = 0; i < 10; i++ ){
    ary[i].i = rand() % 10;
    ary[i].d = rand() % 100;
  }
  cout << ary << endl;
  sort( ary.begin(), ary.end() );
  cout << ary << endl;
  return 0;
}
