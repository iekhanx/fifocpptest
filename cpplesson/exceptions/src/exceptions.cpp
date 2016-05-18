/*
 *     24/03/2014    @ik
 *
 *                             Exceptions
 *                             ==========
 *
 * Exceptions provide a way to react to exceptional circumstances like runtime
 * errors in the program by transferrring control to a special function called
 * handlers.
 *
 * To catch exceptions, a portion of code is palced under exception inspection.
 * This doe by enforcing that portion of code in a try-block. When an 
 * exceptional circumstance arises within that block an exception is thrown
 * that transfers the control to the exception handler if no exception is 
 * thrown, the code continues normally and all handers are ignored.
 *
 * An exception is thrown by using the throw keyward from inside the try-block
 * Exception handlers are declared with keyword catch, with must be placed
 * immediately after the try block.
 */
// Exception catch throw etc..
#include <iostream>
#include <exception>
#include "myswitch.h"
using namespace std;

#ifdef _ONE_
int main() {
    try {
         throw 20;
    }
    catch(int e)
    {
       cout << "_ONE_ an Example" << endl;
       cout << "================" << endl;
       cout << "An exception occurred, Exception Near " << e << endl;
    }
  return 0;
}
#endif 
/*
 * The code under exception handling is enclosed in a try block. This example
 * code simply throw an exception 
 *
 *    throw 20;
 *
 * The exception handler is declare with the catch keyword immediately after
 * afte closing braces of the try block. The syntax for catch is similar to a 
 * regular function with one parameter. The type of this parameter is very 
 * important, since the type of the argument passed by the throw expression is
 * checked against it and only in the case they match, the exception is 
 * caught by that handler.
 *
 * Multiple handler catch exception can be chained each one with a different
 * type. Only the handler whose argument type matches the type of the exception
 * specified in the throw statement is executed.
 *
 * if an ellipses (...) is used as the parameter of the catch block that 
 * handler will catch any exception no matter what the type of the exception 
 * thrown. This can be used as a default handler that catches all the
 * exceptions not caught by other handlers.
 *
 *   try  {
 *           //codes goes here...
 *   }
 *   catch (int param) { cout << "int exception"; }
 *   catch (char param) { cout << "char exeception"; }
 *   catch (...) { cout << "default exception."; }
 *
 * In this case the last handler would catch any exception thrown of a type 
 * that is neither in no char.
 *
 * After an exception has been handled the program execution resume after the
 * try-catch block not after the throw statement.
 *
 * It is also possible to nest try-catch block withmore external try blocks.
 * In these cases, we have the possibility that an internal catch block forward
 * the exception to its external level. This done with the expression throw;
 * with no arguments. For an example...
 *
 *  try {
 *     try {
 *          code goes here...
 *     }
 *     catch (int n) { 
 *               throw;
 *      }
 *  }
 *  catch (...) {
 *      cout << "An Exceptin occurred!" << endl;
 *   }
 */

/* 
 * Excepton specification
 * ======================
 *
 * Older code may contain dynamic exception specifications. They are now 
 * deprecated in C++ but still supported a dynamic exception specification
 * follows the declararion of function appending a throw specifiers to it
 * for an example...
 *
 *      double myfunction (char param) throw (int);
 *
 * This declares a function called my function, which take one arguments of 
 * type char and return a valaue of type double. if this functino throws a an 
 * exception of some type other than int, the function call std::unexpected 
 * instead of looking fora handler or calling std::terminate.
 *
 * If this throw specifiers is left an empty with no type, this mean that
 * std::unexpected is called for any exception. Functions with no throw 
 * specifier regular functions never call std::unexpected, but follow the 
 * normal path of looking for their exception handler.
 *
 *    int myfunction (int param) throw (); // all exception calling unexpected
 *    int myfunction (int param);          // normal exceptioin handling
 */

/* Standard Exception
 * ==================
 *
 * The C++ Standard library provides a base class specifically designed to 
 * declare an objects to be thrown as an exceptin it is called std:exception
 * and is defined in the <exception> handler. This class has a virtual member
 * function called WHAT that retuens a null-terminated character sequence of
 * type char * and that can be overwritten in derived class to contain sort of
 * description of the exception.
 */ 
#ifdef _TWO_
class myexception  : public exception {
	virtual const char * what() const throw()
         {
               return "My Exception happed";
         }
 } myex;

int main () {
	try {
		throw myex;
	    }
	catch(exception& e )
	{
		cout << e.what() << endl;
	}
   return 0;
}
#endif
/*
 * We have palced a handler that catches exception objects by reference notice
 * the ampersand & after the type therefore, this catches also classes derived
 * from exception, like our myex object of type myexception.
 *
 * All exception thrown by components of the C++ STandard library throw
 * exception derived from this exception class. These are as follow:
 *
 *       Exception                         Description
 * ===========================================================================
 * bad_alloc            thrown by new on allocation failure
 * bad_cast             thrown by dynamic_cast when it fail in a dynamic cast
 * bad_exception        thrown by certian dynamic exception specifier
 * bad_typeid           thrown by typeid
 * bad_function 	thrown by an empty function object
 * bad_weak_ptr		thrown by shared _ptr when passed a bad weak_ptr
 *
 * Also deriving from exception header <exception> dfines two generic 
 * an exception type that can be iherited by custom exception to report an error
 *
 *      Exception                         Description
 * ============================================================================
 * logic_error		error related to the internal logic of the program
 * runtime_error	error declared during runtime
 *
 * A typical example where standard exceptions need to be checked for is on
 * memory allowcateion.
 */
#ifdef _THREE_
int main() {
	try {
		int * myarray = new int[1000];
	}
	catch(exception& e)
	{	
		cout << "_THREE_ an Example" << endl;
		cout << "==================" << endl; 
		cout << endl;
		cout << "Standard exception : " << e.what() << endl;
	}
    return 0;
}
#endif
/*
 * The exception that may be caught by the exception handler in this example
 * is a bad_alloc. Because bad_alloc is derived from the standard base class
 * exception, it can be caught capturing by reference, capture all related 
 * classes.
 */ 

