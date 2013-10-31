#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
map è una struttura dizionario esattamente come gli hash di ruby e dict di python
dunque le find e delete sono O(1) invece la inserte segue un criterio ovvero deve
esserci una relazione tra le chiavi, ovvero deve esistere un operatore di comparazione
< o >. Non sono eterogenei, tutte le chiavi dello stesso tipo e tutti i valori dello
stesso tipo. 
*/

double f( int x ){
  cout << "asd" << endl;
  return 1./x;
}


int main(){
  map<int,double> dict;
  for( int i=0; i<10; i++ ){
    int x = i%3;
    if ( dict.find(x) != dict.end() ){
      cout << dict.find(x)->second << endl;
    }
    else{
      dict[x] = f(x);
    }
  }

  return 0;
}
