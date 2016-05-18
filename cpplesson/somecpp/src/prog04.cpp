// Overloading constructor
// Like any other functino a constructor can also be overloaded with different version taking
// different parameters; with different number of parameters and or different types, will 
// automatically call the one whose parameters matches the arguments.

#include <iostream>
using namespace std;

class Rectangle {
      int height; 
      int width;

   public:
      Rectangle ();
      Rectangle (int, int);
      int area (void) { return (width * height); }
};
Rectangle::Rectangle () {
    width = 5;
    height= 5;
}

Rectangle::Rectangle(int a, int b) {
      width = a;
      height = b;
}

int main()
{
    Rectangle rect (4, 5);

    Rectangle rectb;

    cout << "Rectangle rect area: " << rect.area() << endl;
    cout << "Rectangle rect area: " << rectb.area() << endl;

   return 0;
}

