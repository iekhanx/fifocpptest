/*
 * Friendship and Inheritance
 * ==========================
 *
 * In principle, private and protected members of class cannot be accessed from
 * outside the same class in which they are declared.
 * 
 * However, this rule does not apply to FRIENDS.
 *
 * Friends are function or classes declared with the friend keyword.
 *
 * A non member function can access the provate and protected members of a 
 * classif it is declared a friend of that class. That is done by including
 * a declaration of an exeternal function with the class, and 
 * preceding it with the keyword FRIEND.
 */
// friend function
#include <iostream>
#include "myswitch.h"
using namespace std;

#ifdef _ONE_
class Rectangle {
       int width, height;
   public:
	Rectangle () {}
	Rectangle (int x, int y) :width(x), height(y) {}
	int area()
	{ return width * height; }
	friend Rectangle duplicate (const Rectangle&);
};

Rectangle duplicate(const Rectangle& param)
{
	Rectangle res;
	res.width = param.width * 2;
	res.height = param.height * 2;
	return res;
}

int main() {
	Rectangle foo;
	Rectangle bar (2,3);
	foo = duplicate (bar);

	cout << foo.area() << endl;
   return 0;
}
#endif
/*
 * The duplicate function is a friend of class Rectangle. Therefore, function
 * duplicate is able to access the member width and height (which are private)
 * of the different object of type Rectangle.
 * Notice though that neither in the declaration of duplicate nor in its later
 * use in main member function duplicate is considered a member of class 
 * Rectangle. If isn't it simply has access to its private and protected
 * member of variable without being member.
 *
 * Typical use cases of friend function are operations that are conducted
 * between two different classes accessing private and protected member
 * variable or functions of both.
 */

/*
 * Friend Classes
 * ==============
 *
 * Similar to friend function a friend class is a class whose member have an
 * access to the private or protected members of another class.
 */
#ifdef _TWO_
class Square;

class Rectangle {
        int width, height;
  public:
	int area() {return width * height; }
	void convert(Square a);
};

class Square {
	friend class Rectangle;
   private:
	int side;
   public:
	Square (int a) : side(a) {}
};

void Rectangle::convert(Square a)
{
	width = a.side;
	height= a.side;
}

int main() {
	Rectangle rect;
	Square sqr (4);
	rect.convert(sqr);
	cout << "_TWO_ Friend Class:  " << rect.area() << endl;
   return 0;
}
#endif

/*
 * In example, class Rectangle is a friend of class Sqare, allowing Rectangle's
 * member functions to access private and protected member of Square. More 
 * concretely, Rectangle access the member variable Square::side, which
 * describes the side of the square.
 *
 * There is something else new in this example, at the beginning of the program
 * there is an empty declaration of class Square. This is necessary because
 * class Rectangle uses Square as a parameter in member function convert and
 * Square uses Rectangle declaring as a Friend.
 *
 * Friendship are never conrresponded unless specidied ni our example Rectangle
 * is considered a friend class by Square, but Square is NOT considered as a 
 * friend  by Rectangle. Therefore, the member functions of Rectangle can 
 * access the protected and private members of Square but NOT other way round
 * Of course Square could also be declared friend or Rectangle if needed
 * granting such access.
 *
 * Another property of friendship is that they are not transitive. The friend
 * of a friend is not considered a friend unless explicitly specified.
 */

/*
 * Inheritance between Classes
 * ===========================
 *
 * Classes in C++ can be extended, creating new classes which retain character
 * stic of the base class. This process known as inheritance, involves a base
 * class and derived class the derived class inherits the members of the base
 * class on the top of which it can add its own members.
 *
 * For an example lets imagine a series of classes to describe two kind of 
 * Polygon, rectangle and triangle. These two Polygons have ceertain common
 * properties, such as the values needed to calculate their area, they both
 * can be described simply with a height and width (or base).
 *
 * This could be represented in the world of classes with a class Polygon
 * from which we would derive the two other onnes Rectangle and Triangle.
 *
 *                          ---------------------
 *                                  Polygon
 *                          ---------------------
 *                                    |
 *           -------------------------------------------
 *        CRectangle  |                       / CTriangle                  
 *     --------------------------------------------------------   
 * 
 * The Polygon classes wourld contain members that are common for both types of
 * polygon. In out case width and height. And Rectangle and Triangle would be
 * its derived class, with specific features that are different from one type
 * of polygon to the other.
 *
 * The inheritance relationship of two classes is declared in the derived class
 * Derived classes definition use the follwoing syntax:
 *
 *    class derived _class_name : public base_class_name
 *
 * Where derived_class_name is the name of the derived class and nase_class_name
 * is the name of the class on which it is based ON.
 * The public access specifier may be replace by one of other access_specifier
 * (protected or private) These access specifier limits the most accessible
 * level for the member inherited from the base class. The members with a more
 * accessible level are inherited with this level instead, which the members
 * with an equal or more restrictive access level keep their restrictive level
 * in the derived classs.
 */

#ifdef _FOUR_
// Derived class

class Polygon {
  protected:
	int width, height;
  public:
	void  set_values(int a, int b) { width = a; height = b;}
};

class Rectangle : public Polygon {
   public:
	int area()
        { return width * height; }
};

class Triangle  : public Polygon {
   public:
	int area() 
        { return width * height / 2; }
};


int main() {
	Rectangle rect;
	Triangle  trgl;

	rect.set_values(4,5);
	trgl.set_values(4,5);

	cout << "_FOUR_ Example" << endl;
        cout << "==============" << endl;
	cout << "Rectangle Area " << rect.area()  << endl;
	cout << "Triangle  Area " << trgl.area()  << endl;
   return 0;
}
#endif
/*
 * The object of the class Rectangle and Triangle each contain members 
 * inherited Polygon. These are (variable) width and height and function 
 * set_valaues() function.
 *
 * The protected access specifier used in class Polygone is similar to private
 * its only difference occurs in fact with inheritance. When a class ihherits
 * another one, the members of the derived class can access the protected 
 * members of the inherited from the base class, but not its private members.
 *
 * By declaring width, height as protected instead of private, these members
 * are also accessible for the derived class Rectangle and Triangle, instead of
 * just members of Polygon. If they were public, they could be access just from
 * anywhere.
 * We can summerize the different access tyhpes accroding to which function
 * can access them in the follwoing way.
 *
 *       Access                public      protected    private
 * ==============================================================
 * member of the same class     yes         yes          yes
 * member of derived class      yes         yes          no
 * not members                  yes         no           no
 *
 * Where "not members"  represent any access from outside the class such as 
 * from main, from another class or from a function.
 * In the example above the members inherited by Rectangle,Triangle have the 
 * same access permission as they had in their base class Polygon.
 *
 * 	Polyvon::width        // protected access
 * 	Rectangle::width      // protected access
 *
 * 	Polygon::set_values()   // public access
 * 	Rectangle::set_values() // public access.
 *
 * This is becaus the inheritance relation has been declared using the public
 * keyword on each of the derived class
 *
 *    class Rectangle : public Polygon {  //   //
 *
 * This public keyword after colon (:) denotes the most accssible level the 
 * members inherited from the class that following in (this case Polygon) will
 * have from the derived class (in this case Rectangle). Since public is the 
 * most accessible level, by specifiying this keyword the derived class with 
 * inherit all the members with the same levels they had in the base class.
 * 
 * With protected all public members of the base class are inherited as 
 * protected in the derived class. Conversely if the most restricted access
 * level is specified (private) all the based class member are inherited as 
 * private and thus cannot be accessed from the derived class.
 *
 * For example if daughter were a class derived from the mother that we defined.
 *
 *      class Daughter : protected Mother {
 *
 * This would set protected as the less restrictive access level for the member
 *  of Daughter that it inherited from mother. That is all member that were 
 *  public in the mother would become protected in Daughter. Of course this 
 *  would not restrict Daughter from declaring its won public members. 
 *  That less restrictve access level is only set for the members interited 
 *  from mother.
 *
 * If no access level is specified for the inherited, the compiler assume 
 * private for the classes declared with keyword classe and public for those 
 * declared with struct.
 *
 * What is inherited from the base class?
 * ======================================
 *
 * In principle, a derived class inherits ever member of base class except:
 *
 *     Its constructor and its destructor
 *     its assignment operator members(operator)
 *     its friends
 *
 * Although the constructors and destructors of the base class are not 
 * inherited as constructor and destructors in the derived class, they are 
 * still called by the derived class's construtor. Unless otherwise specified
 * the constructor or a derived classes call the default constructors of the 
 * base class(ie the constructor taking no arguments) which must exists. 
 * Calling a different constructor of a base class is possible, using the same 
 * syntax a to initilise member variables in the initilisation list. 
 *
 *    derived_constructor_name (paramter) : base _constructor_name (parameter)
 *
 * For an example:    
 */
// constructor and derived classes
#ifdef _FIVE_

class Mother {
   public:
	Mother()     // constructor
	{  cout << "Mother : no parameters " << endl; }

	Mother(int a)
	{  cout << "Mother : int parameter " << endl; }
};

class Daughter  : public Mother {
    public:
  	Daughter (int a)	// constructor
	{ cout  << "Daughter : int parameter " << endl; }
};

class Son   : public Mother {
    public:
	Son (int a)	// constructor
	{ cout << "Sone  : int parameter " << endl; }
};

int main() {
	Daughter kelly(0);
	Son bud(0);

    return 0;
}
#endif
/*
 * Notice the different between which mother constructor is called when a new 
 * Daughter objects is created and which when it is a Son object. 
 * The difference is due to the different constructor declaration of 
 * daughter and son.
 *
 *    Daughter (int a);	// nothing specified call default constructor.
 *    Son (int a);	// constructor specified call the specific constructor
 */

/*
 *  Multiple Inheritence
 *  ====================
 *
 * A Class may inherit from more than one class by simply specifying more base
 * classes, separated by commas, in the list of a class's base classes(ie
 * after the colonP Foe an example, if the program had a specific class to 
 * print on screen called output, and we wanted out classes Rectangle and
 * Triangle to also inherit its members in addition to those of Polygon
 * we could write:
 *
 *     class Rectangle  : public Polygone, public Output;
 *     class Triangle   : public Polygone, publin Output;
 *
 * Following is a complete an example:
 */

#ifdef _SIX_

class Polygon {
   protected:
	int width, height;
   public:
	Polygon(int a, int b) : width(a), height(b) {}
};

class Output {
   public:
       static void print(int i);
};

void Output::print(int i)
 {	cout << "_SIX_ an Example " << endl;
        cout << "=================" << endl;
        cout << i << endl;
 }

class Rectangle : public Polygon, public Output {
    public:
	Rectangle(int a, int b) : Polygon(a, b) {}
	int area()
	{ return width * height; }
};

class Triangle : public Polygon, public Output {
    public:
	Triangle (int a, int b) : Polygon(a, b) {}
	int area()
	{  return width * height / 2 ; }
};

int main() {
	Rectangle rect (4,5);
	Triangle  trgl(4,5);

	rect.print (rect.area());
	Triangle::print (trgl.area());
    return 0;
}
#endif
	
	
