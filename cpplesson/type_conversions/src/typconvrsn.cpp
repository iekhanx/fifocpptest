/*
 *     23/03/2014          @ik
 *
 *                                  TYPE CONVERSION
 *                                  ===============
 * 
 * Implicit Conversion
 * ===================
 *
 * An implicit conversion are automatically performed when a value is copied to
 * a compatible type for an example:
 *       
 *       short a = 2000;
 *       int   b;
 *
 *       b = a;    // the type conversion took place, here.
 *
 * Here, the value of a is promoted from short to int without the need of any
 * explicit operator. This is known as standard conversion.
 * Standard conversion affect fundamental data type, and allows the conversion
 * between numerical type short to int or int to float, double to int or 
 * bool and some pointer conversion.
 *
 * Conversion to int from some smaller type or to double from float is known
 * as promotion and is guaranteed to produce the exact same value in the
 * destination type. Other conversion between arthmatic type may not always be
 * able to represent same value exactly.
 *
 *    If a negative integer value is converted to an unsinged type, the
 *    resulting value corresponds to its 2s complements bitwise, represent
 *    (i.e -1 become the largest value representable by the type, -2 the 
 *    second largest.
 *
 *    The conversions from to bool consider false equivelent to zero for 
 *    numeric types and to null pointer for pointer type, true is equivalent
 *    to all other values and is converted to equivalent of 1
 *
 *    if the conversion is from a floating point to type an integer type, the 
 *    value is truncated  (the decimal part is removed) if the result lies,
 *    outside the ranges of representable value by the type, the conversion
 *    causes undefined behavior.
 *
 *    Otherwise, if the conversion is between numeric type of the same king
 *    (integer to integer or floating to floating), the conversion is valid,
 *    but the value is implementation specific and may not be portable.
 *
 * Some of these conversions may imply a loss of precision, which the compiler
 * can signal with warning. This warning can be avoided with an explicit 
 * conversion.
 *
 * For non-fundamental types, array and functions implicitly convert to pointer
 * and pointers in general allows the follwoing conversion.
 *
 *      Null pointer can be converted to pointer of any type.
 *      Pointer to any type can be converted to void pointer
 *      Pointer upcast pointer to a derived class can be converted to a pointer
 *      of an accessible and unambiguous base class. without modifying its
 *      const or volatile qualification.
 *
 * Implicit Conversion with Classes
 * ================================
 *
 * In the world of classes, implicit conversion can be controlled by mean of 
 * three  member functions.
 *
 *     Single -argument constructions : allows implicit conversion from
 *     particular type to initilise an object.
 *
 *     Assignment Operator : allows implicit conversion from a particular type
 *     on assigment.
 *
 *     Type-cast operator : allows implicit conversion to particular type.
 *
 * For an example:
 */
#include <iostream>
#include "myswitch.h"
using namespace std;

#ifdef _ONE_
class A {} ;

class B {
   public:
     // conversion from A constructor
     B (const A& x) {cout << "B Constructor called" << endl; }

     // conversion from A assignment
     B& operator= (const A& x) { return *this; }

     // conversion to A type-cast operator
     operator A()  { return A(); }
};

int main() {
	A foo;
	B bar = foo;	// calls constructor
	bar = foo;	// calls assignment
	foo = bar;	// call type cast operator

	cout << "_ONE_ an Example" << endl;
	cout << "================" << endl;


     return 0;
}
#endif
/*
 * The type-cast operator uses a particular syntax, it uses the operator 
 * keyword follwoed by the destination type and an empty set of parenthesis
 * Notice that the return type is the destination type and thus is not
 * specified before the operator keyword.
 */

/*
 * Keyword Explicit
 * ================
 *
 * On a function call C++ allows one implicit conversion to happen for each
 * argument. This may be somewhat problematic for the classes, because it is
 * not always what is intended. For an example, if we add this following 
 * function to the last example.
 *
 *       void fn (B arg) {}
 *
 * This function take an argument of type B but it could as well be called 
 * with an object of type A as an Artument.
 *
 *       fn (foo);
 *
 * This may or may not be what was intended. But in any case if can be prevented
 * by marking the affected constructor with the explicit keyword.
 */
#ifdef _TWO_
class A {};

class B {
  public:
	explicit B (const A& x) {cout << "Explicit constructor called" << endl;}

	B& operator= (const A& x) { return *this; }

	operator A() {return A(); }
};

  void fn (B x) {}

int main () {
	cout << "_TWO_ an Example" << endl;
	cout << "================" << endl;

	A foo;
	B bar (foo);
	bar = foo;
	foo = bar;

	fn (bar);    // fn(foo) // not allowd for explicit ctor

   return 0;
}
#endif
/*
 * Additionally, constructor marked with explicit cannot be called with the
 * assignment-like syntax. In the above example bar could not have 
 * constructed with   
 *
 *       B bar = foo;
 *
 * Type-cast member functions(those described in the previous section) can also
 * be specified as an explicit. This prevents implicit conversion in the same
 * way as explicity specified constructors do for the destination type.
 */
             

/*
 * Type casting 
 * ============
 *
 * C++ is a strong typed language. Many conversions, specially those that imply
 * a different interpretation of the value, require an explicit coversion,
 * known in C++ as type-casting. There exist two main syntaxes for generic
 * type casting functional and c-like.
 *
 *     double x = 10.3;
 *     int  y;
 *     y  = int(x);   // functional notation
 *     y = (int) x;   // c-like notation
 *
 * The functionality of these generic forms of type-casting is enough for most
 * needs, with functional data type. However, these operators can be applied
 * indiscriminatlely on classes and pointers to classes, which can lead to code
 * that while being syntatically conrrect can cause runtime errors. for
 * an example the follwoing code compiles without an errors.
 */
#ifdef _THREE_
class Dummy {
	double i, j;
};

class Addition {
	int x, y;
   public:
	Addition(int a, int b) : x(a), y(b) {};
	// Addition(int a, int b) { x = a; y = b; }
	int result()
        { return x + y; }
};

int main(){
	Dummy d;
	Addition * padd;
	padd = (Addition*) &d;
	cout << "_THREE_ an Example" << endl;
	cout << "==================" << endl; 

	cout << padd->result() << endl;

    return 0;
}
#endif
/*
 * The program declares a pointer to aAddition, but then it assigns to it a 
 * reference to an object of another unrelated type using explicit type-cast.
 *
 *     padd = (Addition *) &d;
 *
 * Unrestricted explicit type-casting allowes to convert any pointer into any
 * other pointer type, independently of the type they poiint to. The 
 * subsequent call to member result iwll produce either a run time error ro
 * some other unexpected result.
 *
 * In order to control these type of conversion between classes, we have four
 * specific casting operatiors : 
 *    
 *       dynamic_cast
 *       reinterpret_cast
 *       static_cast
 *       const_cast 
 *
 * Their formats is to follow the new type enclosed between angle bracket
 * and immediately after, the expression to be converted between parenthesis.
 *
 *     dynamic_cast <new_type> (expression)
 *     reinterpret_cast <new_type> (expression)
 *     static_cast <new_type> (expression)
 *     const_cast <new_type> (expression)
 *
 * The traditional type-casting equivalent to tese expression would be
 *
 *      (new_type) expression
 *      new_type   (expression)
 *
 * But each one with it own special characterstics.
 */

/*
 * Dynamic Cast
 * ============
 *
 * The 'dynamic_cast' can only be used with pointers and references to classes.
 * (or with void*) Its purpose is to ensure that the result of the type 
 * conversion points to a valid complete object of the destination pointer type.
 *
 * This naturally includes pointer upcast(converting from poiinter-to-derived
 * to pointer-to-base), the same way as allowed as an implicit conversion.
 *
 * But dynamic_cast can also downcast(convert from point-to-base to pointer-to
 * -derived) polymorphic classes those with virtual members if and only if the
 *  pointer object is a valid complete object of the target type for an example
 */
#ifdef _FOUR_
#include <exception>

class Base { virtual void dummy() {} };
class Derived : public Base { int a; };

int main() {
try {
	Base * pba  = new Derived;
	Base * pbb  = new Base;
	Derived * pd;

	pd = dynamic_cast<Derived*>(pba);
	if(pd == 0)
         cout << "Null pointer on first type-cast" << endl;

	pd = dynamic_cast<Derived*>(pbb);
	if(pd == 0)
	  cout << "Null pointer on second type-cast" << endl;
   } catch (exception e)
        {
            cout << "_FOUR_ an Example" << endl;
	    cout << "================" << endl;
	    cout << "Exception : " << e.what(); 
       }
    return 0;
}
#endif
/*
 * Compatibility notes:
 * --------------------
 *
 *  This type of dynamic_cast require Run-Time Type information RTTI to keep 
 *  track of dynamic type. Some compilers support this feature as an option
 *  which is disabled by default. This need to be enabled for runtime type
 *  checking using dynamic_cast to work property with these type.
 *
 *  The code above tries to perform two dynamic cast from pointer object of type
 *  base* (pbs and pbb) to pointer object of type Derived* but only the first
 *  one is successful. Notice their respective initlisation.
 *
 *      Base * pba = new Derived;
 *      Base * pbb = new Base;
 *
 * Even though both are pointer of type Base* pba actualy point to an object 
 * of type Derived, while pbb point to an object of type Base. Therefore, when
 * their respective type-cast performed using dynamic_cast, pba is point to 
 * full object of class Derived, whereas pbb is pointing to an object of class
 * Base, which is an incomplete object of class Derived.
 *
 * When dynamic_cast cannot cast a pointer because it is not a complete object
 * of the required class as in the second conversion in the previous example
 * It returns a null-pointer to indicate the failure. If dynamic_cast is used
 * to convert to a reference type and the conversion isnot possible, an 
 * exception of type bas_cast thrown instead.
 *
 * dynamic_cast can also perform the other implicit cast allowed on pointers 
 * casting null pointer between types even between unreletated  classes and
 * casting any pointer of any type of a void* pointer.
 */

/* 
 * static_cast
 * ===========
 *
 * static_cast can be performed conversions between pointer to related classes.
 * Not only upcast (from pointer-to-dervied to pointer-to-base) but also a 
 * downcast from (pointer-to-base to pointer-to-derived) No checks are performed
 * during runtime to guarantee that the object being converted  is in fact a 
 * full object of the destined type. Therefore it is up to the programmer to 
 * ensure that the conversion is safe. On the other side, if does not 
 * incure the overhead of the type safety  checks of dynamic_cast.
 *
 *     class Base {};
 *     class Derived : public Base {};
 *     Base * a = new Base;
 *     Derived * b = static_cast<Derived*>(a);
 *
 * This would be valid code, although b wourld point to an incomplete object of
 * the class and could lead to runtime erros if dereferenced.
 *
 * Therefore, static_cast is able to perform with pointers to classes not only
 * the conversions allowed implicitly but also their opposit conversion.
 *
 * static_cast is also able to perform all conversion allowed implicitly not 
 * only those with pointer to classes, but also able to perform the opposite
 * of these it can    
 *
 *   Covert from void* to any pointer type in this case if guarantee that if the
 *   void* value was obtained by converting from that same pointer type, the
 *   resulting pointer value is the same.
 *
 *   Covert integer, floating point values and enum type to enum type.
 *
 *   Additionally static_cast can also performed the following:
 *
 *       Explicitly call single argument constructor or a conversion operator.
 *       Covert to rvalaue references
 *       Covert enum class value into integer or floating point values.
 *       Covert any type to void, evaluating and discarding the value.
 */
  
/*
 * Reinterpret_cast
 * =================
 *
 * reinterpret_cast converts any pointer type to any other pointer type, of 
 * unrelated classes. The operation result is a simple binary copy of the value
 * from one pointer to other. All pointer conversions are allowed neither the
 * content pointed not the pointer type itself is checked.
 *
 * It can also cast pointers to or from integer type. The format in whchi is 
 * this integer value represent a pointer is platform, specific. The only
 * gurantee is that pointer cast to an integer type large enough to fully 
 * contain it such as intptr_t is guaranteed to be able to be cast back to a
 * valid pointer.
 *
 * The conversion that can be performed by reinterpret_cast but not by
 * static_cast are low level operations based on the reinterpreting the binary
 * representation of the types, which on most cases result in code which is the
 * system specific and thus non portable for an example:
 *
 *     class   A { };
 *     class   B { }
 *     A * a = new A;
 *     B * b = reinterpret_cast<B*>(a);
 *
 * This code compiles, although if does not make much sense, since now b point
 * to an object of a totally urelated and likely incompatible class.
 * Dereferencing b is unsafe.
 *
 *
 * const_cast
 * ==========
 *
 * This type of casting manipulates the constaness of the object pointed by a 
 * poiinter, either to be a set of to be removed. For an example, in order to 
 * pass a const pointer to function that expects a non-const_argument.
 */
#ifdef _FIVE_
void print (char * str)
{ 
   cout << "_SIX_ an Example" << endl;
   cout << "================" << endl;
   cout << endl;
   cout << str << endl;
};

int main() {
	const char * c = "sample text to print";
	print (const_cast<char *> (c) );
    return 0;
}
#endif

/*
 * The example above is guaranteed to work because function print does not 
 * write to the pointed object. Note though that removing the constness of
 * a pointed object to actually write to it cause undefined behavior.
 */

/* 
 * typid
 * =====
 *
 * typid allows to check the type of an expression.
 *
 * type (expression)
 *
 * This operator returns a reference to a constant object of type type_info
 * that is defined in the standard header <typeinfo>. A value returned by the
 * typeid can be compared with another value returned by typeid using 
 * operator== and != or can serve to obtain a null-terminated character 
 * sequence representing the data type or class name by using it name() member.
 *
 */
#ifdef _SIX_
// typeid
#include <typeinfo>

int main() {
	int * a, b;
	a=0; b=0;

	if(typeid(a) != typeid(b) ) {
	  cout << "_SIX_ an Example" << endl;
	  cout << "================" << endl;
	  cout << "a and b are of different types" << endl;
	  cout << "a IS " << typeid(a).name() << endl;
	  cout << "b IS " << typeid(b).name() << endl;
    }
  return 0;
}
#endif
/*
 * When typeid is applied to classes, typeid uses the RTTI to keep track of the
 * type of the dynamic objects. When typeid is applied to an expression whose
 * type is a polymorphic class, the result is the type of the most derived
 * complete object.
 */
#ifdef _SEVEN_
// typeid using with polymorphic class.
#include <typeinfo>
#include <exception>

class Base { virtual void f () {} };
class Derived : public Base {};

int main() {
  try {
	Base * a = new Base;
	Base * b = new Derived;

	cout << "_SEVEN_ an Example" << endl;
	cout << "==================" << endl;

	cout << "a is : " << typeid(a).name() << endl;
	cout << "b is : " << typeid(b).name() << endl;

	cout << "*a is : " << typeid(*a).name() << endl;
	cout << "*b is : " << typeid(*b).name() << endl;
  } catch (exception& e)
    {
	cout << "Exception : " << e.what() << endl;
    }
 return 0;
}
#endif
/*
 * Note: The string returned by member name of the type_info depends on the 
 * specific implementation of your compiler and library. It is not necessarily
 * a simple string with its typical type name, like in the compiler use to 
 * produce this output.
 *
 * Notice how the type that typeid considers to pointer tis the pointer type 
 * itself (both a and b are of type class Base *). However, when typeid is
 * applied to object like *a and *b typeid yields their dynamic types i.e.
 * the type of their most derived complete object.
 *
 * If the type typeid evaluates is a pointer preceded by the dereference
 * operator(*), and this pointer has a null value, type id throw a 
 * bad_typeid an exception.
 */
   
	 
   
