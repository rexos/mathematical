#include <iostream>
#include <boost/timer.hpp>
#include <utility>
#include <vector>

using namespace std;

struct node{
  bool found;
  int val;
  node() : found(false){}
};

vector<node> to_process;
vector<node> primes;

void perform_eratosthenes( int n ){
  for( int i = 2; i < n; i++ ){
    node tmp;
    tmp.val = i;
    to_process.push_back(tmp);
  }

  for(int i = 0; i<to_process.size(); i++){
    if(!to_process[i].found){
      int step = to_process[i].val;
      for(int j = i+step; j< to_process.size(); j += step){
	to_process[j].found = true;
      }
    }
  }

  for( int i=0; i<to_process.size(); i++ ){
    if ( !to_process[i].found )
      primes.push_back( to_process[i] );
  }
}


int main(){
  boost::timer::auto_cpu_timer t;
  int num = 0;
  do{
     cout << "type in a number :  ";
     cin >> num;
  }
  while( num < 2  );
  
  perform_eratosthenes( num );

  for( int i=0; i<primes.size(); i++ ){
    cout << primes[i].val << endl;
  }

  return 0;
}
