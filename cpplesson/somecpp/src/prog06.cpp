// Member initialisation in constructors.
// ======================================
//
// When a constructor is used to initilised  other members, these other members can be initlised 
// directly, without resorting to statement in its body. This is done by inserting, before the
// constructor's body a colon (:) and list of initilisations for the class members.
// For an example, consider a class with following declaration
//
//    class Rectagnle {
//        int width, height;
//
//        public:
//          Rectangle( int, int);
//          int area()  { return (width * height);  }
//    };
//
// The constructor for this class could be defined as usual as:
//
//    Rectangle::Rectangle( int x, int y) {width = x; height =y; }
//
// But it could also be defined using member initilisation as :
//
//    Rectangle::Rectangle(int x, int y) : width(x) { height = y; }
//
// OR Even:
//
//    Rectangle::Rectangle( int x, int y) : width(x), height(y) {}
//
// Note how this is last case, the constructor does notthing else than initilise its members,
// hence it has an empty function body.
//
// For member of fundamental types, it makes no difference which of the way above the constructor
// is defined, because they are not initilised by default, but for member objects (those whose type
// is a class), if they are not initilised after the colon, they are default constructed.
//
// Default constructing all members of a class mey or may always not be convenient in some cases
// this is a waste (when the member is then initiliased otherwise in the constructor) but in some
// other cases, default construction is not even possible (When it class does not have a default
// constructor). in these cases, members shall be initilised in the member initilisation list.
//
// Member initilisation list

#include <iostream>
using namespace std;

class Circle {
	
	double radius;

    public:
	Circle (double r) : radius(r) {}

	double area () { return radius * radius * 3.15159265; }
};


class Cylinder {

	Circle base;

 	double height;

	public:
	  Cylinder (double r, double h) : base(r), height(h) {}

	  double volume() { return base.area() * height; }
};

int main()
{
	Cylinder foo (10, 20);

	cout << "Foo's volume : " << foo.volume() << endl;

     return 0;
}

// In this example class Cylinder has a member object whose type is another class (base's type is
// Circle). Becuase object of the class Circle can only constructed with a parameter, Cylinder's
// constructor needs to call bases constructor and the only way to do this is in the 
// member initilzer list
// These initilsations can also use uniform initiliser syntax using braces {} instead of 
// parenthesis
//
//  Cynlinder::Cylinder (double r, double h) : base (r) height(h) {}
//
