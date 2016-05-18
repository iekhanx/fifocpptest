// Pointer to class
// ================
//
// Object can also be pointed to by pointer: Once declared, a class become a valid type, so it can
// be used as the type pointed to by pointer. For an Example.
//
//     Rectangle  * prect;
//
// Is a pointer to an object of class Rectangle.
//
// Similarly as with plain data structures, the member of an object can be accessed directly from
// a poiinter by using the arrow operator ->. Here is an example with some possible combinations:
//
// Pointer to class example.

#include <iostream>
using namespace std;

class Rectangle {

	int width, height;
    
   public:
	Rectangle(int x, int y) : width(x), height(y) {}

	int area () { return width * height; }
};

int  main()
{
	Rectangle obj (3, 4);

	Rectangle *foo, *bar, *baz;

	foo = &obj;

	bar = new Rectangle (5,6);

	baz = new Rectangle[2] { { 2, 5 }, {3, 6} };

	cout << "obj's area: " << obj.area() << endl;

	cout << "*foo's area: " << foo->area() << endl;

	cout << "*bar's area: " << bar->area() << endl;

	cout << "baz[0]'s area: " << baz[0].area() << endl;

	cout << "baz[1]'s area: " << baz[1].area() << endl;

	delete bar;
	delete [] baz;

    return 0;
}

// This example makes use of several operators to operate on the object and pointers
// (operators * & , -> []) They can be interepretes ..
//
