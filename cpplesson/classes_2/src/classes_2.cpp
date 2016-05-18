/*
 *  20/03/2014    @ik
 *
 *
 * Overloading operator
 * ====================
 *
 * Classes essentially defined new type to be used in C++ code. And types in
 * C++ not only interact with code by means of constructions and assignments
 * They also interact by means of operators. For examples take follwoing 
 * operation on the fundamental type
 *
 *    1 int a, b c;
 *    2 a = b + c;
 *
 * Here different variables of a fundametals type int are applied the 
 * addition operator and then the assignment. for fundamental arithmatic 
 * type the meaning of such operations is generally obivious and unambigus 
 * but may not be so for certain class type for example below:
 *
 *      struct {
 *            string product;
 *            float price;
 *     } a, b, c;
 *     a = b + c;
 *
 * Here it is not obvioius what the result of the addtion operation on b 
 * and c does in fact this code alsone would cause a compilation error. 
 * since file type myclass has no defined behavior for additions. However, 
 * C++ allows most operators to be overloaded so that their behavior 
 * can be defined for just about any type including classes. 
 * Here is list of all the operators that can be overloaded.
 *
 * +  -  *  /  =  <   >   +=   -=   *=    /=   <<   >>   <<=    >>=
 * ==   |=   <=  >=  ++   --  %   &   ~   !  |  ^   &=  ^=  |=  ||  %= 
 * []  {}  ,  ->*  ->  new  delete  new[]  delete[]
 *
 * Operators are overloaded by mean of operator functions which are regular 
 * functions with special names their name begins by the operator keyword
 * followed by the operator sign that is overloaded as follow:
 *
 *     type operator sign (parameters) { * boady * }
 *
 * For examples creation vector  are sets of two coordinate x and y. The
 * addition operation of the two cartesian vector is defined as the addition
 * both x coordinates together and both y coordinate together. For examples
 * the cartesian vector (3,1) and (1,2) together would result in (3+1, 1+2)
 * = (4,3). This could be implemented in C++ with the follwoing code.
 */
#include <iostream>
#include "myswitch.h"

using namespace std;

  // operator over loading as 
  // Member function OR
  // Non Member function. 
  // Next example afte #else depict the codes.
  
#ifdef _ONE_
class CVector {
   public:
	int x, y;
	CVector () {};
	CVector (int a, int b) : x(a), y(b) {}
	CVector operator + (const CVector&);
};

// Function implementation
CVector CVector::operator+ (const CVector &param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
   return temp;
};

int main() {
	CVector foo (3,1);
	CVector bar (1,2);
	CVector result;
	result  = foo + bar;
        
 cout << "_ONE_ an Example" << endl;
 cout << "=================" << endl; 
 cout << endl;
 cout << "Result x=  " << result.x << "  Result y=  " << result.y << endl;
    return 0;
}
#endif 
/*
 * So many appearances of CVector consider that some them refer to the 
 * class name (ie. the type ) CVector and some others are functions with 
 * that name constructor which must have the same name as the class.
 *
 *     CVector (int, int) : x(a), y(b) {}  // function CVector constructor
 *     CVector operator+ (const CVector&)  // function returns CVector
 *
 * The function opertor+ of class CVector overloads the addtions operator(+)
 * for that type. Once declared, this functnio can be called either 
 * implicitly using operator, or explicitly using its functional name.
 *
 *     c = a + b;
 *     a.operator+ (b);
 * Both expression are equivalent
 *
 * In the earlier chapter the copy assignment function was introduced as 
 * one of the special member functions that are implictly defined even 
 * when not explicitly declared, in the class. The behavior of theis 
 * function by default is to copy the whole content of the data members 
 * of the object passed as argument. The one at the left side.
 *
 *    CVector d (2, 3)
 *    CVector e;
 *    e = d;
 * 
 * The copy assigment member is the only operator implicitly 
 * defined for all 
 * classes. Of course if can be redefined for any other functionality. 
 * Such as for example, to copy only certain members or perform additional
 * initilisation.
 *
 * The operator overloaded functions are just regular functions which can 
 * have any behavior, there is actually no requirement that the operation
 * performed by that overloadeed bears a relation to the mathmatical or 
 * usual meaning of the operator. although it is strongly recommended. 
 * for example a class that overloads operator+ to actually subtract 
 * or that overloads operator== to fill the object with zeros, is 
 * preferctly valid. although using such a class could be challenging.
 *
 * The parameter pexted for a member function overload operation such as
 * operator+ is natually the operand to the right hand side of the operator.
 * This s common to all binary operators (those with an operands to its left
 * and oneoperand to its right) But operators can come in diverse forms, 
 * Here is you have a table with summary of the parameters needed for each 
 * of the different operators than can be overloaded.
 *
 * Expression         Operator       Member functon     nonMember Function
 * =========          =======        ==============     ==================
 * @a                + - * & | ++ --  A::operator@()     operator(A)
 * a@                ++ --            A::operator@(int)  operator(A,int)
 * a@b + - * / % ^ & | <> == |= <= >= << >> && ||, A::operator(B) 
 * operator(A,B)
 * a@b = += -= *= /= %= ^= &= |= <<= >>= [] A::operator@(B) 
 * a(b,c...)           ()             A::operator() (B,C...)
 * a->b                ->             A::operator->()
 * (TYPE) a            TYPE           A::operator TYPE()
 *
 * Where a is an object of class A, b is an object of class B and C an 
 * object of class C TYPE is just any type that operators overloads the 
 * convension to type TYPE
 *
 * Notice that some operatos may be overloaded in two form either as a 
 * member function. The first case has been used in the example above 
 * for operator+. But some operator can also be overloded as non-member 
 * functions; in this case the operator function takes an object of the 
 * proper class as first argument. As below example:
 */
#ifdef _TWO_ 
class CVector{
  public:
	int x,y;
	CVector () {}
	CVector (int a, int b) :x(a), y(b) {}
};

CVector operator+ (const CVector & lhs, const CVector & rhs) {
	CVector temp;
	temp.x = lhs.x + rhs.x;
	temp.y = lhs.y + rhs.y;
   return temp;
}

int main () {
	CVector foo (3,1);
	CVector bar (1,2);
	CVector result;
	result = foo + bar;

   cout << "_TWO an Example" << endl;
   cout << "===============" << endl;
   cout << endl;	
   cout << "Result x= " << result.x << "   Result y= "<< result.y << endl;
   return 0;
}
#endif

/*
 *  The Keyword this
 *  ================
 * 
 * The keyword this represent s a pointer to the object whose member 
 * function is being executed it is used within a class member function to
 * refer to the object itself.
 *
 * One of its uses can be to check if a parametere passed to a member 
 * function is the object itself for an example:
 */
#ifdef _THREE_
class Dummy {
   public:
	bool istime(Dummy& param);
};

bool Dummy::istime(Dummy& param)
{
	if(&param == this) return true;
	else return false;

      //(&param == this) ? true : false;
}

int main() {
	Dummy a;
	Dummy * b = &a;
	if( b->istime(a) ) {
	  cout << "_THREE_ an Example" << endl;
	  cout << "==================" << endl;
	  cout << endl;
	  cout << "Yes &a is b " << endl;
	}
	return 0;
}
#endif
/*
 * It is also frequently used in operator= member that return objects by 
 * reference. Following with the examples on cartesian vector seen before,
 * to operator= function could have been defined as :
 *
 * 	CVector& CVector::operator= {const CVector &param)
 * 	{
 * 		x = param.x;
 * 		y = param.y;
 * 		return *this;
 * 	}
 * In fact, this function is very similar  to the code that the compiler 
 * generates implicitly for this class for operator=.
 */

/* 
 * Static members
 * ==============
 *
 * A class can contain static members, either data or functions.
 *
 * A static data member of a class is also known as a class variable,
 * because there is only one common variable for all the objects of that 
 * same class, sharing the same value, i.e. its value is not a different
 * from the one object of this calls to another.
 *
 * For an example, it may used for a variable within a class that can 
 * contain a counter with the number of object of that class that are
 * currently allowcated as in the following example.
 */
#ifdef _FOUR_
class Dummy {
  public:
	static int n;
	Dummy () { n++; };
	~Dummy () { n--; }; 		
};

int Dummy::n=0;

int main() {
	Dummy a;
	//Dummy b[5];
	Dummy * c = new Dummy;

	cout << "_FOUR_ an Example" << endl;
	cout << "-----------------" << endl;
	cout << endl;
	cout << a.n << endl;
	delete c;
	cout << Dummy::n << endl;
   return 0;
}
#endif
/*
 * In fact, static members have the same properties as non member variable
 * but they enjoy class scope. For that reason, and to avoid them to be 
 * declared several times, they cannot be initilised directly in the class
 * but need to be initilised somewhere outside of it. As in the 
 * previous example.
 *
 * 	int Dummy::n = 0;
 * 
 * Because it is a common variable value for all the objects of the same
 * class, it can be referred to as a member of any object of that class
 * or even directly by the class name (of course this is only valid for
 * static members).
 *
 * 	cout << a.n << endl;
 * 	cout << Dummy::n << endl;
 *
 * These two call above are referring to the same variable the static 
 * variable n within class Dummy shared by all objects of this class.
 *
 * Again it is just like a non-member variable, but with a name that 
 * require to be accesed like a member of a class (or an object)
 *
 * Classes can also have static member functions. These represent
 * the same members of a class that are common to all object of that class
 * acting exactly as non-member functions, but being accessed like member
 * of the class. Because they are alike non-member functions, they cannot
 * access non static members of the class, neither member variable nor 
 * member functions. They neither can use the keyword this.
 */

/*
 * Const member functions
 * ======================
 *
 * When an object of a class is qualified as a const object.
 *
 * 	const MyClass myobject;
 *
 * The access to its data members from outside the class is restricted to
 * read only as if all its data members where const for those accessing
 * them from outside of the class. Note though that the constructor is 
 * still called and is allowed to initilise and modify these data members.
 */
#ifdef _FIVE_
class MyClass {
   public:
	int x;
	MyClass(int val) : x(val) {}
	int get() {return x; }
};

int main() {
	const MyClass foo(100);
	//foo.x = 20;		// not valid cannot be modified.
	cout << "_FIVE_ an Example" << endl;
	cout << "=================" << endl;
	cout << endl;
	cout << foo.x << endl;	// ok data member x can be read
     return 0;
};
#endif
/*
 * The member function of a const object can only be called if they are 
 * themselves specified as const members; in the example above, member
 * get which is not specified as const cannot be call from foo. To specify
 * that the member is a const member, the const keyword shall follow the
 * function prototype, after the closing parantheses of its parameters.
 *
 * 	int get() const {return x; }
 *
 * Note that const can be used to qualify the type returned by a member
 * function. This const is not the same as the one which specifies a 
 * member as const. Both are independant and are located at different place
 * in the function prototype.
 *
 * 	int get() const { return x; };         // const member function
 * 	const int& get() { return x; };        // member function returing
 * 	const int& get() const { return x; };  // const member functino 
 * 	                                         returning const & 
 *
 * Member functios specified to be const cannot modify non static data 
 * members nor cal other non const member functions. In essence, const
 * members shall not modify the stateof an object.
 *
 * Const objects are limited to access only members marked as const, but
 * not const object are not restricted can access both const members and
 * non const members alike.
 *
 * You may think that anyway you are seldom going to declare const objects,
 * and thus making all members that don't modify the object as const is 
 * not worth the effort, but const objects are actually very common.
 * Most functions taking classes as parameters actually take them by const
 * referece, and thus, these functions can only access their const members.
 */
#ifdef _SIX_
class MyClass {
	int x;
   public:
	MyClass(int val) : x(val) {}
	const int & get() const { return x; }
};

void print (const MyClass& arg) {
	cout << "_SIX_ an Example" << endl;
	cout << "================" << endl;
	cout << endl;
	cout << arg.get() << endl;
}

int main() {
	MyClass foo (10);
	print(foo);

	return 0;
}
#endif
/*
 * In this example, get was not specified as a const member, the call to 
 * arg.get() in the print function would not be possible because const 
 * object only have access to const member functioons.
 *
 * Member functions can be obverloaded on their constness i.e. a class may
 * have two member functions with identical signatures,except that one
 * is const and the other is not, in this case the const version is called
 * only when the object is itself const, and the non const version is 
 * called when the object is itself not-const.
 */
#ifdef _SEVEN_
class MyClass {
	int x;
    public:
	MyClass (int val) : x(val) {}
	const int& get() const { return x; };
	int & get() { return x; };
 };

int main() {
	MyClass foo (10);
	const MyClass bar (20);
	foo.get() = 15 ;	// ok get() returns int&
	//bar.get() = 25;	// Not ok get return const int&
	cout << "_SEVEN_ an Example" << endl;
	cout << "==================" << endl;
	cout << endl;
	cout << foo.get() << endl;
	cout << bar.get() << endl;
   return 0;
}
#endif

/*
 * Class Template
 * ==============
 *
 * Just like we can create function templates, we can also create class
 * templates, allowing classes to have members that uses template 
 * parameters as types for an example :...
 *
 * 	template <class T>
 * 	class mypair {
 * 		T values [2];
 * 	    public:
 * 	    	mypair( T first, T second)
 * 	    	{
 * 	    	    values[0] = first; values[1] = second; 
 * 	    	}
 * 	}
 *
 * The class that we have just defined serve to store tow elements of any 
 * valid type. For an example if we wanted to declare an object of this 
 * class to to store two integer values of type int with values 115 and 
 * 36 we would write : ...
 *
 * 	mypair<int> myobject (115, 36);
 *
 * This same class could also be used to create an object to store any 
 * other type of such as :
 *
 * 	mypair <double> myfloats (3.4, 2.18);
 *
 * The constructor is the only member function in the previous class 
 * template and it has been defined inline within the class definition
 * itself in case that a member function is defined outside the definition
 * of the class template, it shall be preceded with the template <..>
 * prefix.
 */
#ifdef _EIGHT_
template <class T>
class mypair {
	T a, b;
	public:
	mypair (T first, T second)
	{ 
		a = first;
		b = second;
 	}
		T getmax();
};
	
template <class T> T mypair<T>::getmax()
{
	T retval;
	retval = a > b ? a : b;
	return retval;
}

int main () {
	mypair <int> myobj (100, 75);

	cout << "_EIGHT_ an Example" << endl;
	cout << "==================" << endl;
	cout << endl;
	cout << myobj.getmax() << endl;
	return 0;
}
#endif
/*
 * Notice the syntax of the definition of member function getmax():
 *
 * 	temple <class T> T mypair<T>::getmax()
 *
 * Confused, by so many T's? There are three, T's in this declaration. The
 * first one is the template parameter. The Second one T is refer to the
 * type returned by the function. And the Third one T (The one between an
 * angled bracket> it specifies that this function's template paramter
 * is also the class template paramter.
 */

/* 
 * Template Specialisation
 * =======================
 *
 * It is possible to define a different implementation for a template when
 * a specific type is passed as template argument. This called a 
 * template specilasation.
 *
 * For an example lets suppose that we have a very simple class called 
 * mycontainer that can store one element of any type and that has just
 * one member function called increase, which increase its value. But we
 * find that when it stores an element of type char if would be more 
 * convenient to have completely different implementation with a function
 * member uppercase, so we decide to declare a class template spcilisation
 * for that type :..
 */
#ifdef _NINE_
// Template Specilisation
template <class T>
class mycontainer {
	T element;
   public:
	mycontainer (T arg) : element(arg) {}
	T increase () 
	{	
		return ++element; 
   	}
};

// class template specilisation
template <>
class mycontainer <char> {
	char element;
   public:
	mycontainer (char  arg) : element(arg) {}
	// function declaration and definition.
	char uppercase ()
	{
		if((element >= 'a') && (element <= 'z') )
			element += 'A' - 'a';
		       return element;
	}
};

int main() {
	mycontainer<int> myint (7);
	mycontainer<char> mychar ('j');

	cout << "_NINE_ an Example" << endl;
	cout << "==================" << endl;

	cout << myint.increase() << endl;
	cout << mychar.uppercase() << endl;

	return 0;
}
#endif
/*
 * This is a syntax used for the class template specilisation.
 *
 * 	template <> class mycontainer <char> { ... };
 *
 * First of all, notice that we precede the class name with template <>
 * including an empty parameter list. This is because all type are known
 * and not template arguments are required for this specilisation, but 
 * still it is the specilisation of a class template, and thus if
 * require to be noted as such.
 *
 * But more important that this prefix, is the <char> specilisation 
 * parameter after the class template name. This specialisation parameter
 * itself identifies the type for which the template class is being 
 * specilised char. Notice the diffeence between the generic class
 * template and the specilisation:
 *
 * 	template <class T> class mycontainer { ... } ;
 * 	template <> class mycontainer <char> { ... } ;
 *
 * The first line is the generic template, and 
 * The Secont one is the SPECILISATION.
 *
 * When we declare specilisation for a template class, we must also define
 * all its members, even those identical to the generic template class,
 * because the there is no inheritance  of members from the generic
 * template to the specilisation.
 */

