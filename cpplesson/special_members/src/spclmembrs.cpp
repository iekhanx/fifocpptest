/*
 * SPECIAL MEMBERS
 * ===============
 *
 * Special members function are member functions that are implicitly as member of
 * class under certain cirucumstances. There are SIX cirumustances.
 *
 *        Member function                        typical form for class C
 *        ===============                        ========================
 * 1 	Default constructor				C::C();
 * 2	Desctructor 					C::~C();
 * 3  	Copy constructor				C::C (const C&);
 * 4	Copy assigment 					C& operator= (const C&);
 * 5	Move constructor				C::C (C&&);
 * 6	Move assignment					C& operator= (C&&);
 *
 * Lets expand each ot these Special member of SIX circumstances.
 *
 * Default constructor
 * ==================
 *
 * The default constructor is the constructor called when object of class are 
 * declared, but are not initilised with any argument.
 *
 * If a class definition has no constructor, the compiler assumes the class to 
 * have an implicitly default constructor. Therefore, after declaring a
 * class like this below:
 *
 *    class Example{
 *      public:
 *         int total;
 *         void accumulate (int x) {total =x; }
 *   };
 * The compiler assumes that the example above has default constructur.
 * Therefore, objects of this class can be constructed by simply declaring
 * them without any arguments. Example..:
 *
 *    Example ex;
 *
 * But as soon as a class has some constructor taking any number of parameters
 * explicitly declared, the compiler no longer provides an implicit default
 * constructor, and no longer allows the declaration of new object of that class
 * without arguments. For example the following class:..
 *
 *     class Example2 {
 *     	 public:
 *     	 	int total;
 *     	 	Example2(int initial_value) : total(initial_value) {};
 *		void accumulate(int x) { total += x; }
 *     }
 * Here, we have declared a constructor with a parameter of type int. Therefore,
 * the following object declaration would be correct.
 *
 * 	Example2 ex (100); 	// ok call constructor.
 *
 * But following is not valid... as you may see
 *
 * 	Example2 ex;		// NOT ok no default constructor
 *
 * Would not be valid since the class has been declared with an explicit 
 * constructor taking one argument and that replace the implicit default
 * constructor taking none.
 *
 * Therefore, if objects of this class need to be constructed without an argument
 * the poroper default constructor shall also be declared in the class.
 * For example....
 */
#include <iostream>
#include <string>
#include "myswitch.h"
using namespace std;


#ifdef _THREE_

class Example3 {
     	string data;
   public:
	Example3 (const string& str) : data(str) {}
	Example3 () {}
	const string& content() const {return data; }
};

int main() {
	Example3 foo;
	Example3 bar ("An Example");
	
	cout << "bar's contents: " << bar.content() << endl;
   return 0;
}  			
#endif
/* Here, example3 has a default constructor(Example3()) defined as an empty block
 *
 *   Example3 ();
 *
 * This allows objects of class Example3 to be constructed without arguments
 * (like foo was declared in the example) Normally a default constructor like
 * this is implicitly defined for the all classes that thave no other constructor
 * and thus no explicit definition is required. But in this case, Example3
 * has another constructor...
 *
 *         Example3 (const string& str);
 *
 * And when any constructor is explicitly declared in a class NO implicit
 * default constructor is automatically provided.
 *
 */

/* 
 *  Destructor
 *  ===========
 *
 * Destructor fulfill the opposite functionality of constuctor.
 * The are reponsible for the necessary cleanup needed by a class when its life
 * time ends. The classes we have defined in previous chapter did not allowcate
 * any resource and thus did not really require any clean up.
 *
 * But now, lets imagine that the class in the last example allowcates a dynamic
 * memory to store the string if has as data member, in this case it would be
 * very useful to have a function called automatically at the end of the object's
 * life in charge of releasing this memory. To do this, we use destructor.
 * A destructor is a member function very similar to a default constructor.
 * It take no arguments and return nothing not even void. It also uses the class
 * name as its own name, but preceding with ~ tilde sign.
 */

#ifdef _FOUR_
// Destructor use exhibit.
class Example4 {
       string* ptr;
   public:
	// constructor default.
	Example4 () : ptr(new string) {}
	Example4 (const string& str) : ptr(new string(str)) {}
	// Destructor default
	~Example4 () {delete ptr; }
	// access contents
	const string& content() const {return *ptr; }
};

int main () {
	Example4 foo;
	Example4 bar ("An Example");

	cout << "bar's contents: " << bar.content() << endl;
   return 0;
}
#endif

/*
 * On construction, Example4 allocates storage for a string. Storage that is 
 * later released by destructor.
 *
 * The destructor for an object is called at the end of its lifetime,
 * in the case of foo and bar this happens at the end of function main.
 */

/* Copy Constructor
 * ================
 *
 * When an object is passed a nameed object of its own type as an argument,
 * its copy constructor is invoked in order to construct a copy.
 *
 * A Copy constructor is a constructor whose first parameter is of type
 * reference to the class itself(possibly const qualified) and which can be 
 * invoked with a single argument of this type. For example, for a class myClass
 * the copy constructor may have the following signature.
 *
 *     MyClass::MyClass (const MyClass&);
 *
 * if a class has no custom copy no move constructor (or assigments) defined,
 * an implicit copy constructor is provided. This copy constructor simply
 * perform a copy of its own members. For example, for class such as:
 *
 *     class MyClass {
 *        public:
 *           int a, b; string c;
 *     }
 * 
 * An implicit copy constructor is automatically defined. The definition 
 * assumed for this function performes a shallow copy, roughly equivalent to:
 *
 *     MyClass::MyClass(const MyClass& x) :a(x.a), b(x.b), c(x.c) {}
 *
 * This default copy constructor may suit the needs of may classes. But shallow
 * copies only copy the members of the class themselves, and this is probably
 * not what expect for classes like class Example4 was defined above, because
 * it contains pointers of which it handles its storage. For the class, 
 * performing a shallow copy mean that the pointer value is copied, but not the
 * contents itself. This mean that both objects(the copy and the original)
 * wouldbe sharing a single string object(they would both be pointing to the 
 * same object).and at some point (on destruction) both objects would try to
 * delete the same block of memory, probably causing the program to crash on
 * runtime. This can be solved by defining the following custom copy
 * constructor that performs a deep copy.
 */
#ifdef _FIVE_
class Example5  {
      string *ptr;
   public:
        //default constructor....
	Example5 (const string& ptr) : ptr(new string(str)) {}
        // defalut destructor...
	~Example5 () {delete ptr; }
	// Copy constructor..
	Example5(const Example5& x) : ptr(new string(x.content())) {}
	// access contents. deep copy.
	const string& content() const
	{return *ptr; }
};

int main() {
	Example5 foo ("An Example");
	Example5 bar = foo; // object passed as its own object for initilise.

	cout << "bar's Contents: " << bar.content() << endl;
   return 0;
}
#endif

/*
 * The deep copy performed by this copy constructor allocates storage for a new
 * string, which is initilised to contain a copy of the original object in this
 * way, both objects (copy and an original) have distinct copies of the content
 * stored in different location.
 */

/*
 * Copy Assignment
 * ===============
 *
 * Object are not only copied on constructor when they are initilised. The can
 * also be copied on any assignment operation. See the difference:..
 *
 *    MyClass foo;
 *    MyClass bar (foo);  // object initilisation copy constructor called.
 *    MyClass baz = foo;  // object initilisation copy constructor called.
 *    foo = bar;          // objct already initilised copy assignment called.
 *
 * Note that baz is initilised on construction using an equal sign but this is 
 * not an assigment operation(although if it may look like). The declaration
 * of an object is not a an assigment operation, it is just another of the 
 * syntaxes to call single-argument constructor.
 *
 * The assignment foo is an assigment operation. No object is being declared
 * here, but an operation is be performed on an existing object foo.
 *
 * The copy assigment operator is an overload of operator= which takea a value
 * or reference of the class itself as parameter. The return value is generally
 * a reference to *this (although this not require). For example, for a class
 * MyClass, the copy assignment may have the following signature.
 *
 *    MyClass& operator= (const MyClass&);
 *
 * The copy assignment operator is also a special function and is also defined
 * implicitly if a class has not custom copy nor move assigment (nor move 
 * cosntructor defined.
 *
 * But again, the implicit version perform a shallow copy which is suitable for
 * may classes, but not for clases with pointer to objects they handle its
 * storage, as is the case in Example5. In this case not only the class incurs
 * the risk of deleting the pointed object twice, but the assignment creates
 * memory leaks by not deleting the object pointed by the object before the
 * assigment. These issues could be solved with a copy assignment that deletes
 * the previous object and perform a deep copy.
 *
 *   Example5& operator= (const Example& x) 
 *   {
 *       delete ptr;
 *       ptr = new string (x.content());
 *       return *this;
 *   }
 *
 * Or even better, since its string member is not a constant, it could be re-
 * utilize the same string object.
 *
 *    Example5& operator= (const Example5& x)
 *    {
 *    	 *ptr = x.content();
 *    	 return *this;
 *    }
 */
        
/*
 * Move Constructor and Assigment
 * ==============================
 *
 * Similarly copying moving also uses the value of an object to set the value 
 * to another object. But unlike coping the content is actually transferred
 * from one object (the source) to the other (the destination), the source
 * loses that content, which is taken over by the destination. The moving only
 * happens when the source of the value is an unnamed object.
 *
 * Unnamed object are objects that are temporary in nature, and thus haven't
 * even been given a name. Typical example of unamed object are return values
 * of the functions of type-cast.
 *
 * Using the value of temporary object such as these to finitilise another 
 * object or to assign it value, does not really require a copy the object
 * is never going to used for anything else, and thus its value can be moved
 * into the destination object. These cases trigger the move constructor
 * and move assignments.
 *
 * The move constructor is called when an object is initilised on construction
 * using an unamed temporary. Like wise, the move assignment is called when
 * an object is assigned the value of an unnamed temporary:
 *
 * 	MyClass    fn();	// function returning a MyClass object
 * 	MyClass    foo;		// default constructor called
 * 	MyClass    bar = foo;	// Copy constructor called.
 * 	MyClass    baz = fn();	// Move constructor called
 * 	foo = bar;		// copy assigment called
 * 	bas = MyClass()'	// Move assignment called.
 *
 * Both the values returned by fn and the valaue constructed with MyClass are
 * unnamed temporaries, int these cases, there is no need to make a copy.
 * because the unnamed object is very short lived and can be acquired by the 
 * other object when this is amore efficient operatorn.
 *
 * The move constructor and move assignment are member that take a parameter
 * of type lvalue reference to the class itself.
 *
 * 	MyClass (MyClass&&);               //  move constructor
 * 	MyClass& operator= (MyClass&&);    // move-assignement 
 *
 * An lvalue reference is specified for following the type with two 
 * ampersands(&&). As a parameter, an lvalue reference matches arguments of 
 * temporary of this type.
 *
 * The concept of moving is most usefule for object that manage the storage 
 * they use, such as object thatallocate storage with new and delete in such
 * object, copying and moving are really different operations.
 * Copying from A to B mean that new memory is allocated to B and they the 
 * entire content of A is copied to B in his new memory allocated area.
 * Moving from A to B mean that the memory alreay allocated to A is transferred
 * to B without allocating any new memory storage. It involves simply copying
 * the pointer.
 */
#ifdef _SIX_
class Example6 {
    string * ptr;
  public:
	Example6 (const string& str) : ptr(new string(str)) {}
	~Example6() { delete ptr; }
	// move constructor
	Example6 (Example6&& x) : ptr(x.ptr) 
        { x.ptr == nullptr; }
	// move assignment
	Example6 operator= (Example6&& x)
	{
		delete ptr;
		ptr = x.ptr;
		x.ptr = nullptr;
	     return *this;
	}

	// access content
	const string& content() const
	{ return *ptr;  }
	
	// addtion
	Example6 operator+(const Example6 rhs)
	{ return Example6(content() + rhs.content()); }
};

int main() {
	Example6 foo ("An Example 6");
	Example6 bar = Example6("Example Move");  // move construction

	foo = foo + bar;	// move assignment 

	cout << "Foo's Contents : "<< foo.content() << endl;
   return 0;
}
#endif
/*
 * Compiler already optimize many cases that formally require a move 
 * construction call in what is known as return value.
 * Optimization most notably when the valaue returned by function is used to 
 * initilise an object in these case the move constructor may actually never
 * get called.
 *
 * Note that even though lvalue references can be used for the type of any 
 * function parameter, it is a seldom useful for uses other than the move
 * constructor. Pvalue reference are tricky and unnecessary uses may be the 
 * source of errors quite difficult to track.
 */

/*
 * Implicit Member
 * ===============
 *
 * The six special members functions described above are member implicitly 
 * declared on classes under certain circumstances.
 *
 * Member function           Implicit defined               Default definintion
 * ===============           ================               ===================
 * Default Constructor   if no other constructors            does nothing
 * Destructor            if no destructor                    does nothing
 * Copy Constructor      if no move constructor & no move    copy all
 *                       assignment                          members
 * Copy assignment       if no move constructor & no move    copy all 
 *                       assignment                          members
 * Move constructor     if no destructor, no copy constructor Move all 
 *                      and no copy nor move assignment       Members
 * Move assignment      if no destructor, no copy constructor Move all
 *                      and no copy nor move assigment        Members
 * ============================================================================
 *
 * Notice how not all special member functions are implicitly defined in the 
 * some cases. This is mostly due to backwards compatibility with C structures
 * and earlier C++ versions, and in fact some include deprecated cases.
 * Fortunately each class can select explicitly which of these members exists
 * with their default dfinition or which are deleted by using the keyword 
 * default and delete, respectviely. The syntax is either one of ..
 *
 *    function_declaration  = default;
 *    function_declaration  = delete;
 */
#ifdef _SEVEN_
class Rectangle {
	int width, height;
   public:
	Rectangle (int x, int y) : width(x), height(y) {}
	Rectangle () = default;
	Rectangle (const Rectangle& other) = delete;
	int area() { return width * height; }
};

int main() {
	Rectangle  foo;
	Rectangle  bar (10, 12);
	
	cout << "bar's Area: " << bar.area() << endl;
   return 0;
}
#endif
/*
 * Here, Rectangle can be constructed either with two int arguments or be 
 * default constructed (with no argurments). It cannot however, be 
 * copy-constructed from another Rectangle object. Because this function has
 * been deleted. Therefore, assuming the objects of the las example, the
 * following statement would not be valid.
 *
 *    Rectangle baz (foo);
 *
 * It could, however, be made explicitly valid by defining its copy constructor
 *
 *    Rectangle::Rectangle(const Rectangle& other) = delete;
 *
 * Which would be essentially equivalents to:
 *
 *    Rectangle::Rectangle (const Rectangle& other) :
 *                         width(other.width), height(other.height) {}
 *
 * Notice, that the keyword default does not define a member function equal to
 * the default constructor(ie where default constructor mean constructor with
 * NO parameters), but equal to the constructor that would be implicitly
 * defined if no deleted.
 *
 * In general, and for future compatility, classes that explicitly defined ONE
 * copy/move CONSTRUCTOR or one copy/move ASSIGNMENT but not both, are an
 * encouraged to specify either delete or default on the other special member
 * functions they don't explicitly defined.
 */ 


 
