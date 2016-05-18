//
//  20/03/2014  @ik
//
/*  Classes (I)
 *  ===========
 *
 * Classes are an exapnded concept of data structure like data structure they
 * can contain data members but they can also contain functions as a members.
 *
 * An object is an instatiantion of a class,in terms of variables a class would
 * be the type and an object would be a variable.
 *
 * Classes are defined using either keyword class or keyword struct with 
 * following syntax:
 *
 * class class_name {
 * 	access_specifier_1;
 * 	   member1
 * 	access_specifier_2
 * 	  member_2
 * 	  ...
 *  } object_names;
 *
 *  Where class name is valid identifier for the object_name is a optional list
 *  of names for objectsof this class. This body the declaration can contains
 *  member which can either be data or a funciton declarations, and optionally
 *  access specifier.
 *
 *  The format is the same as for plain data structures, except that they can 
 *  also be include function and have this new thing called access specifier
 *  An access specifier is one of the follwoing three keywords:
 *
 *  	private
 *  	public
 *  	protected
 *
 * Three specifiers modify the access right for the member that follow them.
 *
 * private: member of class are accessible only from within other members
 * 	    of the same class or from friendss
 *
 * protected:  members are accessible from the other members of the SAME class
 *            or from their friends, but also from member of their derived 
 *            class
 *
 * public:   members are accessible from the anywhere where the object is
 * 	     visible.
 *
 * By default all members of a class declare with class keyword have provate
 * access access for all its members.
 * Therfore, any members that is declared before any other access specifier
 * has private access automatically.
 *
 * class Rectangle {
 * 	int width; int height;
 * 	public:
 * 	void set_values(int, int);
 * 	int area(void);
 * } rect;
 *
 * Declare a class i.e. type called Rectangle and object i.e. variable of this
 * class call rect. The class contain four members two data members of type int
 * (member of width and height) with private access, because private is default.
 * access level and two member functions with public access the function
 * set_values and area of which for now we have only included their declaration
 * but not their definition.
 *
 * Notice, the difference between the class name and the object name in the
 * previous example. Rectangle was the class name.(i.e typeS) where rect was
 * an object of type Rectangle it is the same relationship int and a have in
 * in the following declaration.
 *
 * int a
 *
 * where int is the type name (the class) and a is the name of the object.
 *
 * After declaring Rectangle and rect any of the public member of object rect
 * can be accessed as it whey were normal; functions or normal variables, by
 * simply inserting a dot(.) between object name and member name.
 * the following the same syntax accessing the member of plain data struct.
 *
 * rect.set_values(3,4);
 * myarea = rect.area();
 *
 * The only member of rect that cannot be access from the outside of the class
 * are width, and height, since they have private access identifier and they can
 * only be referred to from within other members of that same class.
 *
 */

#include <iostream>
#include "myswitch.h"
using namespace std;
#ifdef _ONE_
class Rectangle {
	int width, height;
   public:
	void set_values(int, int);
	int area() { return width * height; }
};

void Rectangle::set_values(int a, int b)
{ 
	width = a; height = b;
}
 
int main (){
	Rectangle rect;
	rect.set_values(9,6);
        cout << "_ONE_ an Example" << endl;
	cout << "================" << endl;
	cout << "Area " << (3- rect.area()) << '\n';
   return 0;
}
#endif

/*
 * This example reintroduces the scope resolution(::) seen in the earlier 
 * chapter in relation to namespace. Here it is used in the definition of 
 * function set_values() to define member of the a class outside the class 
 * itself.
 *
 * Notice that the definition of the member function area has been included 
 * directly within the definition of a class Rectangle given its extreme 
 * simplycity. Conversely, set_valaue it is merely declared with its prototype 
 * within the class. but it definition is outside it in this outside 
 * defnitions, the operator of scope(::) is used to specify that the function 
 * being defined is a member of the class Rectangle and not a regular 
 * non-member function.
 *
 * The scope resolution(::) speficies the class to which the member being 
 * declared belongs, granding exactly the same scope properties as if this 
 * function definition was directly included within the class definition. 
 * For an example, the function set_values() in the previous example has 
 * access to the variable width and height, which are private members of the 
 * class Rectangle, and thus only accessible from the other members of the 
 * class such as this.
 *
 * The only difference between defining a member function completely within 
 * the class definition or to just include its declaration in the function and 
 * define it later outside the class, is that in the first clase the function 
 * is automatically considered an inline member function by the compiler with 
 * in the second it is a normal (not inline) class member function. This 
 * causes no differences in behavior, but only on the possible compiler 
 * optimizations.
 *
 * Member width, and height have private access(remember that if noting else is
 * specified then all the member variable within class defined with keyword 
 * class have private access) By declaring them private access from outside 
 * the class is not allowed. This makes sense, since we have already defined 
 * a member function to set_value for those members within a object the member 
 * function set_values. Therefore, the rest of the program does not need to 
 * have direct access to them. Perhaps in a so simple example as this, it is 
 * difficult to see how restricting access to these variable may useful, but 
 * in greater projects it may be very important that values cannot be modified 
 * in an unexpected way(unexpected from the point of view of the object).
 *
 * The most importantly property of a class is that it is a type, and as such, 
 * we can declare multiple objects of it. For an example, following with the 
 * previous example of class Rectable, we coudl have declared the object rectb 
 * in an addition object rect.
 */
#ifdef _TWO_
class Rectangle {
      int width, height;
   public:
	void set_values(int, int);
	int area() { return width * height; }
};

void Rectangle::set_values(int x, int y)
{ 
	width = x;
 	height = y;
}

int main() {
	Rectangle rect, rectb;
	rect.set_values(3,4);
	rectb.set_values(5,6);

	cout << "_TWO_ an Example" << endl;
	cout << "================" << endl;

	cout << "rect Area : " << rect.area() << endl;
	cout << "rectb Area : " << rectb.area() << endl;
 
     return 0;
}
#endif
/*
 * In this example above the class (type of the objects) is Rectangle of which there are two instances  i.e. objects rect and rectb. Each one of the has its own member variable and member functions.
 *
 * Notice that the call rect.area() function does not give the same result as 
 * the call to rectb.area(). This is because each object of class Rectangle has
 * its own varibales width and height as they in some way have also their own 
 * function members set_values and area that operate on the object own member 
 * variables.
 *
 * Classes allow programming using object oriented paradigam. Data and function
 * are both members of the object, reducing the need ot pass and carry 
 * handlers, or other sate variables as arguments, to functions, because they 
 * are part of the object whose member is called. Notice that no arguments 
 * were passed on the calls to rect.area() and rectb.area(). Tose member 
 * functions are directly used the data members of the their respective 
 * objects rect and rectb.
 */

/*
 * Constructor
 * ===========
 *
 * What would happen in the previous example if we called the member function 
 * area before having called set_values? An underterminated result, since the 
 * members width and height had never been assigned a value.
 *
 * In order to avoid that a class can include a spcial function called its 
 * constructor which is automatically callse wherever, a new object of this 
 * class is created, allowing the class to initilise member variables or 
 * allocate storage.
 *
 * This constructor function is declared just like a regular member function, 
 * but with a name that matches the class name and without any return type, 
 * not even void.
 *
 * The Rectangle class above can easily be improved by implmenting a 
 * constructor.
 */
#ifdef _THREE_
class Rectangle {
       int width, height;
   public:
	Rectangle (int,int);
	int area () {
	return  width * height ; 
	}
};

Rectangle::Rectangle (int a, int b)
{
	width = a;
	height = b;
}

int main() {
	Rectangle rect (3,4);
	Rectangle rectb (5,6);
	
	cout << "_THREE_ an Example" << endl;
	cout << "==================" << endl;
	
	cout << "rect Area : " << rect.area() << endl;
	cout << "rectb Area : " << rectb.area() << endl;
  return 0;
}
#endif
/*
 * Ths result of this examaple are idetical to those of the previous example.
 * But now, class Rectable has no member function set_values, and has instead 
 * a constructor that performs a similar action. It initilises the value of 
 * width and height with the argument passed to it.
 *
 * Notice how these arguments are passed to the constructor at the moment at 
 * which the objects of this class are created.
 *
 * 	Rectanle  rect (3,4);
 * 	Rectanle  rectb *5,6);
 *
 * Constructor cannot be called explicitly as if they are regular member 
 * functions. They are only executed once, when a new object of that class 
 * is created.
 *
 * Notice how neither the constructor prototype declaration (within the class) 
 * nor the latter constructor definition, have return valaues, not even void. 
 * Constructor never return values, they simply initilize the object.
 */

/*
 * Overloading constructor
 * =======================
 *
 * Like any other function, a constructor can also be overloaded with different
 * versions taking different parameters, with a different number of parameters 
 * and or parameters of different types. The compiler will automatically call 
 * the one whose paramters match the arguments.
 */
#ifdef _FOUR_
class Rectangle {
	int width, height;
  public:
	Rectangle ();
	Rectangle (int, int);
	int area (void) {return width * height; }
};

Rectangle::Rectangle () {
	width = 5;
	height = 6;
}

Rectangle::Rectangle(int a, int b) {
	width = a;
	height = b;
}

int main () {
	Rectangle rect (3,4);
	Rectangle rectb;

	cout << "_FOUR_ an Example"  << endl;
	cout << "================="  << endl; 

	cout << "rect Area : " << rect.area() << endl;
	cout << "rectb Area : " << rectb.area() << endl;
   return 0;
}
#endif
/*
 * In the above example two objects of class Rectable are constructed  rect 
 * and rectb is constructed with two arguments, like in the example before.
 *
 * But example also introduces a special kind of constructor the DEFULT 
 * CONSTRUCTOR.
 * The default constructor is the constructor that TAKE NO PARAMETERS and it is
 * a SPECIAL because it is called when an object is declared but is not 
 * initialised with any arguments. In the example above the default constructor
 * is called for rectb object. Note how rectb is not even constructed with an 
 * empty set of parantheses in fact empty parameters cannot be used to call 
 * the default constructor.
 *
 *    Rectangle rectb;     // ok default constructor called.
 *    Rectangle rectc();   // oops default constructor NOT called.
 *
 * This is because the empty set of parentheses would make of rectc a function 
 * declaration instead of an object declaration. it would be a function that 
 * takes no arguments and returns a value of type Rectangle.
 */
 
/*
 *  Uniform Initilisation
 *  ======================
 *
 * The way of calling constructor by enclosing their arguments in paranthesis, 
 * as shown above, known as functional form. But constructor can also be 
 * called with other syntaxes.
 *
 * First constructor with a single parameter can be called using the variable 
 * intilised syntax an equal sign followed by the argument.
 *
 * 	class_name object_name = initilisation_values.
 *
 * More recently C++ introduced the possibilty of constructor to be called 
 * using uniform initilisation which essentially is the same as the function 
 * form but using brases {} instead of parantheses()
 *
 * 	class_nake object_name {value, value, value ...}
 *
 * Optionally, this last syntax can be included an equal sign before the braces
 * 
 * Here is an example with four way to construct objects of a class whose 
 * constructor take a single paramter.
 */
#ifdef _FIVE_
// classes with uniform initilisation facility 
class  Circle {
	double radius;
   public:
	Circle(double r ) {radius = r; }
	double circum() { return 2 * radius * 3.14159265; }
};

int main() {
	Circle foo (10.0); 	// functional form
	//Circle bar = 20.0;	// Assignment initilisation
	//Circle baz {30.0};	// Uniform initilisation
	//Circle qux = {40.0};	// POD Like;

	cout << "_FIVE_ an Example " << endl;
	cout << "==================" << endl;

	cout << "foo's circumference " << foo.circum() << endl;
	return 0;
}
#endif
/*
 * An advantage of uniform initilisation over functional form is that unlike 
 * parentheses, braces cannot be confused with function declaration, and thus 
 * can be used to explicitly called default constructor.
 *
 * 	Rectangle rectb;	// default constructor called
 * 	Rectangle rectc();	// Function declaration default cons not called
 * 	Rectangle rectd{};	// default constructor called.
 * 
 * The choice of syntax to call constructor is largely a matter of style. 
 * Most existing code currently uses functnioal form, and some newer style 
 * guides, suggest to choose uniform initilisation over the others, even 
 * though it also has its potential pitfalls for preferences of 
 * initilizere_list as it type.
 */
 
/*
 * Member Initilisation in constructors
 * ====================================
 *
 * When a constructor is used to initilise other members, these other members 
 * can be initilised directly without resorting to statments in it body. 
 * This is done by inserting, becore the constructor's body a colon(:) and a 
 * list of initilisation for the class members. For an example, consider a 
 * class with the following declaration.
 *
 * 	class Rectangle {
 * 		int width, height;
 * 	   public:
 * 	   	Rectangle(int, int);
 * 	   	int area () {return width * height; }
 *      };
 *
 * The constructor for this class could be defined, as usual as :
 *
 * 	Rectangle::Rectangle(int x, int y) {width = x; height = y; }
 *
 * But it could also be defined using member initilisation as :
 * 	
 * 	Rectangle::Rectangle(int x, int y) : width(x), {height(y);}
 * 
 * or Even:
 * 	
 * 	Rectangle::Rectangle(int x, int y) : width(x), height(y) {}
 * 
 * Note how in this last case, constructor does nothing else than initilise its 
 * members, hence if hase empty function body.
 *
 * For members of fundamental types, it makes no difference which of the way 
 * above the constructor is defined, because they are not initilised by 
 * default, but for member objects those whose type is a class if they are 
 * not initlised aafter the colon, they are default constructed.
 *
 * Default constructing all members of a class may or may always not be 
 * convenient in some cases, this is waste when the member is then reinitilised
 * otherwise in the constructor but in the some other cases, default 
 * construction is not even possible when the class does not have a default 
 * constructor in these case, members, shall be initilized in the member 
 * initilisation list for example.
 */
#ifdef _SIX_
class Circle {
	double radius;
   public:
	Circle(double r) : radius(r) {}
	double area() {return radius * radius * 3.14159265; }
};

class Cylinder {
	Circle   base;
	double height;
    public:
	Cylinder(double r, double h) : base (r), height(h) {}
	double volume() { return base.area() * height; }
};

int main() {
	Cylinder foo (10,20);
	
	cout << "_SIX_ an Example" << endl;
	cout << "================" << endl;

	cout << "foo's valume : " << foo.volume() << endl;
   return 0;
}
#endif
/*
 * In this example class Cylinder has a member object whose type is another
 * class base type is Circle. Because objects of class Cicle can only be 
 * constructed with a parameter, Cylinder's constructor need to call base's
 * constructor, and the only way to do this is in the member initilisation list
 *
 * These initilisation can also used uniform initiliser syntax using braces
 * {} instead parenthese ()
 *
 * Cylinder::Clylinder (double r, double h) : base(r), height(h) {} ;
 */
 
/*
 * Pointers to classes
 * ====================
 *
 * Objects can also be pointed to by pointer. Once declared, a class become a 
 * valid type, so it can be used as the type pointed to by a pointer 
 * for an example:
 *
 * 	Rectangle * prect;
 * 
 * is a pointer to an object of class Rectangle
 *
 * Similarly as with plain data structur, the members of an object can be 
 * accessed directly from a pointer by isomg the arrow operator (->). 
 * Here is an example with some possible combinations.
 */
#ifdef _SEVEN_
class Rectangle {
	int width, height;
   public:
	Rectangle (int x, int y) : width(x), height(y) {}
	int area(void) { return width * height; }
};

int main() {
	Rectangle obj (3,4);
	Rectangle * foo, * bar, * baz;
	foo = &obj;
	bar = new Rectangle (5,6);
	baz = new Rectangle[2]{{2,5}, {3,5}};

	cout << "_SEVEN_ an Example" << endl;
	cout << "==================" << endl;

	cout << "obj's Area  : " << obj.area() << endl;
	cout << "*foo's Area : " << foo->area() << endl;
	cout << "*bar's Area : " << bar->area() << endl;
	cout << "baz[1]'s Area : " << baz[0].area() << endl;
	cout << "baz[2]'s Area : " << baz[1].area() << endl;

	delete bar;
	delete [] baz;
	return 0;
}
#endif
/*
 * This example makes use of several operators to operate on the object and 
 * pointers operators *,&,.,->, []. They can be interpreted as :
 *
 * Expression                          can be read as
 * ============================================================================
 * *x		ponited to by x
 * &x 		address of x
 * x.y	 	member y of object x
 * x->		member y of object pointed by x
 * (*x).y	member y of object pointed to by x (equivalent to the previous)
 * x[0]		first object pointed by x
 * x[1]		second object pointed to by x
 * x[n]		(n+1) th object pointed by x
 * ============================================================================
 *
 * Most of these expressions have been introduced in the earlier chapters. 
 * Most notably the chapter about arrays, introduced the offset operator []
 * and the chapter about plain data structures introduced the arrow operator.
 */

/*
 * Classes defined with struct and union
 * =====================================
 *
 * Classes can be defined not only with the keyword class, but also with the
 * keyword struct and union.
 *
 * The keyword struct, generally used tp declared plain data structurs, can 
 * also be used to declare classes that have member functions, with the same
 * syntax as with keword class. The only difference between both is the
 * members of classes with the keyword struct have public accessble by default
 * while member of classes declared with the keyword class have private 
 * access by default. For all other purpose both keyword are equivalent in 
 * this  context.
 *
 * Conversely, the concept of union is different that of claases declared with
 * struct and class, since union only store one data member at a time, but 
 * nevertheless they are also classes and can thus also hold member function.
 * The default access in union class is public.
 */
 

