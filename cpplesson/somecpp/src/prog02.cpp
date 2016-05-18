//
//  Class Template
//  ==============
//  
//  Just like we can create function templates, we can also create class templates, allowing 
//  classes to have member that uses template paramters as types, for an example:
//
//  template <class T>
//  class mypair {
//       T value [2];
//     public:
//       mypair( T first, T second)
//       { 
//           value[0] = first; value[1] = second;
//       }
//   }
//
//   The class that we have just defined serves to store two elements of any valid type.
//   For an example if we wated to declare an object of this class to store two integer
//   values 115 and 36 we would write:
//
//     mypair<int> myobject (115, 36);
//
//   The same class could also be used to create an object to store any other type, such as:
//
//      mypair <double> myfloat(3.2, 2.16);
//
//   The constructor is the only member function in the previous class template and it has
//   been defined inline within the class definition itself. In the case that a member
//   function is defined outside the definition of the class template, is shall be 
//   preceded with the template <...> prfix.
//
#include <iostream>

using namespace std; // this declaration allows explicitly all the std::namespace included as
                     // as unqualified basis can be accessed.
                     
//typedef unsigned int uint;

/*
template <class T>
class mypair {
      T a, b;
    public:
      mypair( T first, T second)
      {
             a=first; b=second;
       }
      
      T getmax();
};

template <class T>
   T mypair<T>::getmax()
   {
     T reval;
     retval = a > b? a : b;
   return retval;
}
*/
///////////////////////////////////////////////////////////////////
bool f(int x)
{
	return !(x & 7);
}

void mytest1()
{
	//uint v[10];
	//uint i = 0;
	
        unsigned int v[10];
        unsigned int i = 0;
	while (i < 10)
		//cout << "Value of V: "<< v[i] = i++;
		cout << "TEST 2: Value of v: " << v[i]; i++;

       cout << endl;
}

//bool fa( uint n )
bool fa(unsigned int n)
{
  return (n & (n-1)) == 0;
}

//uint fb( uint n )
unsigned int fb(unsigned int n)
{
  //return –n & 7;
  return -(n & 7);
}

int fc( int n, int l, int r )
{
  return (n << l) >> r;
}

void fn(long* p1, long* p2)
{
	register int x = *p1;
	register int y = *p2;
	x ^= y;
	y ^= x;
	x ^= y;
	*p1 = x;
	*p2 = y;

        cout << "TEST 6: ";
        cout << "*p1 = " << p1 << endl;
        cout << "*p2 = " << p2 << endl;

}

void send(int count, short *to, short *from)
{
    /* count > 0 assumed */
    //register n = (count + 7) / 8;

    register int n = (count + 7) / 8;

    switch (count % 8)
    {
    case 0:        do {  *to = *from++;
    case 7:              *to = *from++;
    case 6:              *to = *from++;
    case 5:              *to = *from++;
    case 4:              *to = *from++;
    case 3:              *to = *from++;
    case 2:              *to = *from++;
    case 1:              *to = *from++;
          cout << "TEST 7: count: " << count << "To " << to << "from "<< from;
         } while (--n > 0);
    }
    cout << endl;
}


int main() 
{

     int num1 = 1;
     unsigned int num2 = 2;
     int l, r;
     long *p1, *p2;
     int count = 5;
     short *to, *from;

     // test one
     // cout << "TEST 1: bool var returns: " << f(num1) << endl; 

     // Test two
     //mytest1();

     // Test three
     //cout << "TEST 3: bool value uint n: " << fa(num2) << endl;

     // Test four
     //cout << "TEST 4: uint for fa(): " << fb(num3) << endl;

     // Test five
     //num1 = l = r = 5;
     //cout << "TEST 5: int fc(int n, int l int r) yield: " << fc(num1, l, r) << endl;

     // Test six
     //*p1 = 6; *p2 = 8;
     //fn(p1, p2);

     // Test seven
     send (count, to, from);


    return 0;
}

