// 
// Template classs demonstration
//
#include <iostream>
using namespace std;

template <class T> 
   T sum (T a, T b) {
   
      T result;
      result  = a + b;

      return result;
}

int main() {
	int i=6, j=6, k;
	double f=2.0, g=6.9, h;

	k = sum<int>(i,j);

	h = sum<double>(f, g);

	cout << "Value of k: " << k << endl;
	cout << "value of h: " << h << endl;
   return 0;
}

