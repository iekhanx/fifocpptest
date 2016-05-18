/*
 *  20/03/2014  @ik
 *  23/03/2014  @ik
 *====================================================================
 *
 *
 * POLYMORPHISM
 * ============
 *
 * Before getting any deeper into this chapter you should have a proper under
 * standing of pointer and classes inheritance. If you are not really sure of
 * the meaning of any of the following expressions, you should review the 
 * indicated sections.
 *
 *      Statement                              Explained in:
 * =========================================================================
 * int A::b(int c) {}                        Classes 
 * a->b                                      Data structures
 * class A: public B {}                      Friendship and Inheritance
 * =========================================================================
 */
        
/*
 * Pointer to Base Class.
 * ======================
 * On of the key feature of class inheritance is a pointer to a derive class is
 * a type -compatible with a pointer to its base class.
 * Polymorphism is the art of takeing an advantage of this simple but powerful
 * and verstile feature.
 *
 * The example below tha rectangle and triangle can be rewritten using pointing
 * to this feature.  
 */
#include <iostream>
#include "myswitch.h"
using namespace std;

#ifdef _ONE_
class Polygon {
	protected:
	   	int width; int height;
	public:
		void set_values(int a, int b)
		{ width = a; height = b; }
};

class Rectangle : public Polygon{
	public:
		int area()
		{ return width * height; }
};

class Triangle : public Polygon {
	public:
		int area()
		{ return (width * height / 2); }
};

int main()
{
	Rectangle rect;
	Triangle  trgl;

	Polygon * ppoly1 = &rect;
	Polygon * ppoly2 = &trgl;

	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);

	cout << rect.area() << '\n';
	cout << trgl.area() << '\n';
}
#endif

/*
 * Function main declares two pointer to Polygon (named ppoly1 and ppoly2).
 * These are assigned the address of rect and trgl respectively, which are
 * an objects of type Rectangle and Triangle. Such assignments are valid, 
 * since both Rectangle and Triangle are classes derived from Polygon.
 *
 * Declaring pploy1 and ppoly2 (with *ppoly1 and *ppoly2) is valid and allows
 * us to access the members of their pointed objects. For an example, the 
 * following two statements would be equivalent in the previous example.
 *
 *     ppoly1-> set_values(4,5);
 *     rect.set_values(4,5);
 *
 * But because the type of ppoly1 and ppoly2 is pointer to Polygon (and not a 
 * pointer to Rectangle not pointer to Triangle), only the members inherited
 * from the Polygon can be accessed and not those of the derived classes
 * the Rectangle and Triangle. That is why the program above acces the area 
 * members of both object using rect and trgl directly, instead of the pointer,
 * the pointer to the base class cannot access the area members.
 *
 * Member area could have been accessed with the pointers to Polyugon if area 
 * were a member of Polygone instead of member of its derived class, but the 
 * problem is that Rectangle and Triangle implement different version of area, 
 * therefore, there is not a single common version that could be implemented 
 * in the base class. 
 */


/* 
 * Virtual members
 * ===============
 *
 * Virtual member is a member function that can be redefined in a derived class
 * while a preserving it calling properties through references. The syntax
 * for a function is become a virtual is to precede its declaration with 
 * VIRTUAL KEYWORD. As depicted in following program.
 */
#ifdef _TWO_
class Polygon {
  protected:
	int width, height;
  public:
	void set_values(int a, int  b)
	{ width = a; height = b; }
	
	virtual int area()    // Virtual keyword used to declare
        { return 0;   }
};

class Rectangle : public Polygon {
    public:
	int area()            // overriding virtual function here...
	{ return width * height; }
};

class Triangle : public Polygon {
   public:
	int area()          // .... here too overriding..
	{  return width * height / 2; }
};

int main() {
	Rectangle rect;		// an objects created.
	Triangle  trgl;
	Polygon   poly;

	Polygon  *ppoly1 = &rect;  // pointers to polygon clss initialised
	Polygon  *ppoly2 = &trgl;  // with object reference.
	Polygon  *ppoly3 = &poly;

	ppoly1->set_values(4,5);   // pointers filled with values..
	ppoly2->set_values(4,5);
	ppoly3->set_values(4,5);
	
	cout << "_TWO_ an Example" << endl; // std output for this example
	cout << "================" << endl;

	cout << ppoly1->area() << endl;  // program output ...
	cout << ppoly2->area() << endl;
	cout << ppoly3->area() << endl;
  return 0;
}
#endif
/*
 * In this example, all three classes (Polygon, Rectangle, Triangle) have the
 * same members width, height, and functions set_values, and area.
 *
 * The member functions area has been declaredas virtual in the base class it is
 * later redefined in the each of the derived classes, Non-virtual members, 
 * can be redefined in derived classes, but non-virtual members of the derived 
 * classes, cannot be accessed through a reference of the base class i.e. 
 * if Virtual is removed from the declaration of area in the examaple above, 
 * all three call to area would be returned zero, because in the all cases, 
 * the version of the base class would have been called instead.
 *
 * Therefore, essentially what the virtual keyward does, is to allow member 
 * of a dervied class with the same name as one in the base class to be 
 * appropriately called from a pointer, and more precisely when the type of 
 * the pointer is a pointed to the base class that is pointing to an 
 * object of the derived class, as in the above example.
 *
 * A class that declares or inherit a virtual function is called 
 * polymorphic class.
 *
 * Note that despite of the virutality of one of its members polygon was 
 * regual class, of which even an object was inistatiated poly with its 
 * own definition of member area that always return 0
 *
 */ 

/*
 * Abstract Base Classes
 * =====================
 *
 * Abstract base classes are somthing very similar to the Polygon class in the 
 * previous example. They ARE THE CLASSES THAT CAN ONLY BE USED AS BASE CLASSES
 * ,and thus are allowed to have virtual member functions without definition 
 * (known as pure virtual function). The syntax is to replace their definition 
 * by =0 (and equal sign and zero) 
 *
 * An abstract base Polygon class could look like:
 *
 *     // abstract class CPolygon
 *     class Polygon  {
 *         protected: 
 *		int width, height;
 *         public:
 *         	void set_values(int a, int b)
 *         	{ width = a; height = b; }
 *             virtual int area() =0;
 *    }
 *  
 * Notice that area has no definition, this bas been replaced by =0, which make
 * it a pure virtual function. Classes that contain at least one pure virtual
 * function are known as ABSTRACT BASE CLASS.
 *
 * Abstract base classes cannot be used to instatiate objects. Therefore, this
 * last abstract base class version of Polygon could NOT be used to 
 * declare objects like :
 *
 *       Polygon poly Or mypolygon;   // this wiil not work...cause
 *                                    // Polygon abstract base class.
 *
 * But an abstract base class is not totally useless it can be use to create 
 * a pointers to it, and take an advantage of all its polymorphic abilities.
 * For an example, the following pointer declaration would be valid.
 *
 *      Polygon * ppoly1;
 *      Polygon * ppoly2;
 *
 * And can actually be dereferenced when pointing to objects of dervied (non-
 * abstract) classes. Here is the entire example.
 */
#ifdef _THREE_
class Polygon {
  protected:
	int width, height;
  public:
	void set_values(int a, int b)
	{ width = a; height = b; }
	
	virtual int area() =0;
};

class Rectangle : public Polygon {
    public:
	int area(void) { return width * height; }
};

class Triangle  : public Polygon {
    public:
	int area (void) { return width * height / 2; }
};

int main () {
	Rectangle rect;
	Triangle  trgl;

	Polygon * ppoly1 = &rect;
	Polygon * ppoly2 = &trgl;
	
	ppoly1->set_values(4,5);
	ppoly2->set_values(4,5);

	cout << "_THREE_ an Example" << endl;
	cout << "==================" << endl;

	cout << "ppoly1 area: "  << ppoly1->area() << endl;
	cout << "pppoy2 area: "  << ppoly2->area() << endl;

       return 0;
}
#endif
/*
 * In this example, objects of different but related types are referred to 
 * using a unique type of pointer (Polygon *) and the proper member function 
 * is called every time, juist because they are virtual. This can be really 
 * useful in some cirucumstances. For example, if it is even possible for a 
 * member of the abstract base class Polygon to use the special pointer this 
 * to access the proper virtual members, even though Polygon itself has no 
 * implementation for this function.
 */
#ifdef _FOUR_
// pure virutal member can be called
// from the abstract base class.
class Polygon {
    protected:
	int width, height;
    public:
	void set_values(int a, int b)
	{ width = a; height = b ; }

	virtual int area() =0;// abstract base class virtual function	

	void printarea()
	{
            cout << "_FOUR_ an Example" << endl;
	    cout << "=================" << endl;

	    cout << this->area() << endl; // Pointing to base class BUT
         }                             // data from dervied class ie.
                                       // Rectangle's area function 
};                                     // and Triangle class  
                                    
class Rectangle : public Polygon {
    public:
	int area(void) // derived class overriding virtual function
	{ return width * height;  }
};

class Triangle : public Polygon {
    public:
       int area (void)
	{ return width * height / 2; }
};

int main (){
	Rectangle rect;
	Triangle  trgl;

	Polygon * ppoly1 = &rect;
	Polygon * ppoly2 = &trgl;

	ppoly1->set_values(4, 5);
	ppoly2->set_values(4, 5);

	ppoly1->printarea();
	ppoly2->printarea();
   return 0;
}
#endif
/*
 * Virtual members and abstract classes grant C++ polymorphic characterstics, 
 * most useful for object oriented projects. Of course, the example above
 * are very simple use cases, but the features can be applied to an arrays of
 * objects or dynamically allowcated objects.
 *
 * Here is an another an example, that combines some of the features, in the
 * later chapters, such as dynamic memory, constructor, initilises and
 * polymorphism.
 */

#ifdef _FIVE_
// dynamic allocation and polymorphism
class Polygon {
   protected:
	int width, height;
   public:
	Polygon (int a, int b) : width(a), height(b) {}
	
	virtual int area() =0;

	void printarea() {
		cout << "_FIVE_ an Example" << endl;
		cout << "=================" << endl;

		cout << this->area() << endl;
	}
};

class Rectangle : public Polygon {
    public:
	Rectangle(int a, int b) : Polygon(a, b) {}
	int area (void)
	{
		return width * height;
        }
};

class Triangle  : public Polygon{
    public:
	Triangle(int a, int b) : Polygon(a, b) {}
	int area (void)
	{
		return width * height / 2;
	}
};

int main() {
                            // using new keyword to allocate dynamic memory.
	Polygon * ppoly1 = new Rectangle(4,5);
	Polygon * ppoly2 = new Triangle(4,5);

	ppoly1->printarea();
	ppoly2->printarea();

	delete ppoly1;     // releasing dynamically allocated memory.
	delete ppoly2;
   return 0;
}
#endif
/*
 * Notice that the ppoly pointers...
 *
 *    Polygon * ppoly1 = new Rectangle (4,5);
 *    Polygon * ppoly2 = new Triangle  (4,5);
 *
 * are declared being of a type poiinter to Polygon class but the objects 
 * allocated have been declared having been derived class type directly
 * Rectangle and Triangle.
 */





 
