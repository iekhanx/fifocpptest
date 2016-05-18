// Uniform Initialisation
// The way calling constructor by enclosing their arguments in parenthesis, as shown in previous 
// example is known functional form.
// But constructor can also be called with single parameter using a variable initiliser syntax
// (an equal sign followed by the argument.)
//
//  class name object_name = initialiser _value
//
//  More recently C++ introduced a possibility of constructors to be called using uniform
//  initialisation with eessentially is the same as the functional form but using braces{} 
//  instead of parenthesis().
//
//    class_name   object_name {value, value,  value ...}
//
// Optionally this last syntax can include an equal sign before the braces.
//
// Here is an example with four way to contruct objects of the class whose constructor takesa 
// single parameter.
//
// class and uniform initilisation
// ===============================

#include <iostream>
using namespace std;

class Circle  {
    double radius;

    public:

        Circle(double r) { radius = r; }

        double circum () { return 2 * radius * 3.14159265; }
};

int main() {

    Circle foo (10.0);     // Functional form initialisation

    Circle bar = 20.0;     // Assigment initilisation

    Circle baz {30.0};     // Uniform initialisation

    Circle quz = {40.0};   // POD like initilisation

    cout << "Foo - Circumference: " << foo.circum() << endl;
    cout << "bar - Cir............" << bar.circum() << endl;
    cout << "baz - Cir ..........." << baz.circum() << endl;
    cout << "quz - Cir............" << quz.circum() << endl;

  return 0;
}

