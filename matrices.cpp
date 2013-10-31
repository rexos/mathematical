#include <iostream>
#include <vector>

using namespace std;

class Matrix{
  int rows,cols;
  vector<double> data;
public:
  Matrix(int c, int r): rows(r), cols(c), data(rows*cols,0) {}
  void set_value( int x, int y, double value ){
    data[x*rows + y] = value;
  }
  double get_value( int x, int y ){
    return (x+1)*y < rows*cols? data[x*rows + y] : 0;
  }
  void print(){
    for( vector<double>::iterator i = data.begin(); i != data.end(); i++ ){
      cout << *i << " ";
    }
    cout << endl;
  }
  Matrix operator + (Matrix);
};

Matrix Matrix::operator+( Matrix other ){
  Matrix res = Matrix(rows,cols);
  if ( other.data.size() == data.size() ){
    for( int i=0; i< data.size(); i++ ){
      res.data[i] = data[i] + other.data[i];
    }
  }
  return res;
}

int main(){
  Matrix m = Matrix(3,4);
  Matrix s = Matrix(4,4);
  m.set_value(0,3,5.2);
  m.set_value(2,1,9.9);
  s.set_value(0,3,3.8);
  s.set_value(2,1,5.7);
  Matrix res = m+s;
  res.print();
  return 0;
}
