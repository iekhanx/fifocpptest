/*
 *  27/03/2014       @ik
 *
 *                             Input / Output with files
 *                             =========================
 * 
 * C++ provides the following classes to perform an output and input of 
 * characters to and from files.
 *
 * 	ofstream          Stream class to write on the files.
 * 	ifstream          Stream class to read from files.
 * 	fsteam            Stream class to both read and write from and to files.
 *
 * These classes are derived directly or indirectly from the classes istream
 * and ostream. We have already used objects whose type were these classes,
 * cin is an object of class istream and cout is an object of class ostream.
 * Therefore, we have already have been using classes that are related to our
 * file streams. And in fact, we can use out file streams the same way we are
 * already to use cin and cout, whth the only differences that we have to 
 * associates these streams with physical files. Lets see an example:...
 */ 
#include <iostream>
#include <fstream>
#include "myswitch.h"
using namespace std;

#ifdef _ONE_

int main() {
	ofstream myfile;
	myfile.open( "example_1.txt");    //open a file

	cout << "_ONE_ an Example" << endl;
	cout << "================" << endl;

	myfile << "Writing to this file. LINE 1\n";
	myfile << "Writing to this file. LINE 2\n";
	myfile << "Writing to this file. LINE 3\n";
	myfile << "Writing an end of line\n";

	myfile.close();

	return 0;
}
#endif
/*
 * This codes creates a file called example_1.txt and insert a sentences into 
 * the same way we are used to do with cout command, but using the file 
 * stream myfile an object instead.
 */

/*
 *  Open File
 *  =========
 *
 *  The first opertation generally performed on an object of one of these 
 *  classes, is to associate it to a real file. This procedure is known as a
 *  to open a file. An open file is represented within a program by a stream
 *  (an object of these classes; in the previous example, this was myfile)
 *  and any input or output operation performed on this stream object will be
 *  applied to the physical file associted to it.
 *
 *  in order to open a file with a stream object was use its member function
 *  open:..
 *
 *  	open (filename mode);
 *  
 *  Where filename is a string representing the name of the file to be opned,
 *  and mode is an optional parameter with a combination of the following flags.
 *
 * ============================================================================
 *  ios::in		Open for input operation.
 *  ios::out		Open for ouput operation.
 *  ios::binary		Open in binary mode
 *  ios::ate		Set the initial position at the end of the file.
 *  			if this flag is not set, the initial position is the
 *  			beginning of the file.
 *  ios::app		All output operatino are performed at the end of the
 *  			file, appending the contents to the current contents
 *  			of the file.
 *  ios::trunc		If the file opened for output operation and it alreay
 *  			existed, its previous content is deleted and replaced
 *  			by the new one.
 * ============================================================================
 *
 * All these flags can be combined using the bitwise operator OR (|). For an
 * example, if we want to open the file example.bin in binary mode to add a
 * data we could do this by the following call to the member function open:..
 *
 * 	ofstream myfile;
 * 	myfile.open("example_1.txt", ios::out | ios::app | ios::binary);
 * 
 * Each of the open member functions of classes ofstream, ifstream, fstream
 * has a default mode that is used if the file is opened without a second 
 * an argument.
 *
 * 	class			default mode parameter
 * 	==============================================
 * 	ofstream		ios::out
 * 	ifstream 		ios::in
 * 	fstream 		ios::in | ios::out
 * 	==============================================
 * 
 * For ifstream and ofstream classes, ios:in and ios::out are automatically and
 * respectively assumed, even if a mode that does not include them is passed
 * as second argument to the open member function (the flags are combined).
 *
 * For fstream, the default value is only applied if the function is called
 * without specifying any value for the mode parameter if the function is
 * called with any value in the parameter the default mode is overridden, not
 * combined.
 *
 * First streams opened in binary mode performed in and output operation 
 * independantly of any format considerations. Non-binary file are known as 
 * text files, and some translation may occur due to formatting of some special
 * characters (like newline and carrige return)characters).
 *
 * Since the first task that is performed on a file stream is generally to open
 * a file, these three classes include in a constructor that automatically calls
 * the open member function and has the exact same paramters as this member.
 * Therefore, we could also have declared the previous myfile object and 
 * conduct the same opening operation in our previous example by writting:...
 *
 * 	ofstream myfile ("example_1.txt",ios::out | ios::app | ios::binary);
 * 
 * The combining object construction and strem opening in a single statement.
 * Both forms to open a file are valid and equivalent.
 *
 * To check if a file stream was successful opening a file, you can do it by
 * calling to member function is_open(). This member function returns a bool
 * value of the true, in the case that indeed the stream object is associated
 * with an open file, or false otherwise.
 *
 * 	if(myfile.is_open()) { // ok process with output;  }
 */ 	 

/* Closing file
 * ============
 *
 * When we are finished with out input and output operation on a file we shall
 * close it so that the operating system is notified and its resources become
 * available again. For that we call the stream's member function close. This
 * member function takes flushes the associated buffers and closes the file.
 *
 * 	myfile.close();
 * 
 * Once this member function is called, the stream object can be resued to open
 * another file, and the file available again to the opened by other processes.
 *
 * In case that an object is destroyed while still associated with an open file,
 * the destructor automatically calle the member function to close.
 */

/*
 * Text Files
 * ==========
 *
 * The text file streams are those where the ios:binary flag is not included in
 * their opening mode. These files are designed to store text and thus all
 * values that are input of output from and to can suffer some formatting 
 * transformations, which do not necessary correspond to their literal binary
 * values.
 *
 * Writing an operation on text files are performed in the same way we
 * operated with cout.
 */
#ifdef _TWO_

int main() {
	ofstream myfile("example_2.txt");

	if(myfile.is_open() ) {
		cout << "_TWO_ an Example" << endl;
		cout << "================" << endl;
		
		myfile << "We are writing to file named example_2.txt line 1\n";
		myfile << "we are writing to file same name line 2 \n";
		myfile << "Writing again to the same file line 3\n";
		myfile << "Writing and last line an end of line\n";
		myfile.close();
		cout << endl;
		cout << "Three lines written to file example_2.txt" << endl;
	}
	else  {
		cout << "Unable to open file example_2.txt" << endl;
		cout << "_TWO_ an Example" << endl;
		cout << "================" << endl;
	}
      return 0;
}
#endif
/*
 * Reading from a file can be performed in the same way that we did with cin.
 */
#ifdef _THREE_

int main() {
	string line;
	ifstream myfile ("example_2.txt");

	if(myfile.is_open()) {
		cout << "_THREE_ an Example" << endl;
		cout << "==================" << endl;

		while( getline (myfile, line) ) {
			cout << line << endl;
		}
		myfile.close();
	}
	else {
		cout << "Unable to open example_2.txt file" << endl;
		cout << "_THREE_ an Example" << endl;
		cout << "==================" << endl;
	}
   return 0;
}
#endif
/*
 * This last example read text file and prints out it contents on the screen.
 * We have created a while loop that reads the file line by line, using a 
 * function getline. The value returned by getline() is a reference to the 
 * stream object itself, which when evaluated as a boolean expression (as 
 * in this while loop) is true, if the stream is ready for more operation
 * and false if either the end of the file has been reached or if some 
 * other error occurred.
 */

/*
 * Checking state flags
 * ====================
 *
 * In additions to good, which checks whether the stream is ready for 
 * input/output operation, other member fuctions exist check for specific 
 * states of stream (all of them return a bool value)
 *
 *   bad() 
 *       Returns true if a reading or writing operation fail. For an example
 *       in the case that we try to write to a file that is not open for
 *       writing or if the device where we try to write has no space left.
 *
 *   fail()
 *   	Returns true in the same case as bad(), but also in the case that a
 *   	format error happens, like when an alphabatical character is extracted
 *   	when are trying to read an integer number.
 *
 *   eof()
 *   	Returns true if the file opened for ready has reached to an end of file.
 *
 *   good()
 *   	It is the most generic state flag it returns false in the same case in
 *   	which calling any of the previous functions woudl return true.
 *   	Note that good and bad are not exact opposition (good check more state
 *   	flags of once).
 *
 * The member function clear() can be used to reset the state flags.
 *
 */
   		 	      
/* get and put stream positioning
 * ==============================
 *
 * All I/O stream objects keep internally at least one internal position.
 *
 * ifstream: like istream, keep aninternal get position with the location of the
 * element to be read in the next input operation.
 *
 * ofstream: like ostrem, keep an interanl put position with the location where
 * the next element has to be written.
 *
 * Finally fstream keep both the get and put position like iostream.
 *
 * These internal stream positions point to the locations within the stream 
 * where the next reading or writing operation is performed.
 * These positions can be observed and modified using the following member
 * functions.
 *
 * tellg() AND tellp()
 *
 * These two member functions with no parameter return a value of the member
 * type streampos, which is a type representing the current get position in 
 * the case of tellg() or put position in case of tellp.
 *
 * 	seekg ( position );
 * 	seekp ( position );
 *
 * Using the prototype, the stream pointer is changed to the absolute position.
 * Counting from the beginning from the file. The type for this parameter is
 * streampos, which is the same type as returned by function tellg() tellp().
 *
 * The other form for these functions:
 *
 * 	seekg (offset, direction );
 * 	seekp (offset, direction );
 * 
 * Using this prototype, the get or put position is set to an offset value 
 * relative  to some specific point determined by the parameter direction 
 * offset is a type streamoff. And direction is of type seekdir, which is an
 * enumerated type that determined the point from where offset is counted from
 * and that can take any of the following values.
 *
 * 	ios::beg	offse counted from the beginning of the stream
 * 	ios::cur	offset counted from the current position
 * 	ios::end	offset counted from the end of the stream.
 * 
 * The following an example uses the member functions we have just seen to
 * obtain the size of file.
 */
#ifdef _FOUR_

int main() {
	streampos begin, end;
	ifstream myfile("iowithfiles.o", ios::binary);
        //ifstream myfile("example_2.txt" );	

	begin = myfile.tellg();
	myfile.seekg( 0, ios::end);

	end = myfile.tellg();

	myfile.close();

	cout << "_FOUR_ an Example" << endl;
	cout << "=================" << endl;
	cout << endl;
	cout  << "Size of file is : " << (end - begin) << endl;
   return 0;
}
#endif
 		
 /*
 * Notice the type we have used for variable begin and end.
 *
 * streampos is a specific type used for buffer and file positioning and is the
 * returned by file.tellg(). Value of this type can safely be subtracted to 
 * form other values of the same type and can also be converted  to an integer
 * type large enough the size of the file.
 *
 * These stream positioning functions use two particular type streampos and
 * streamoff. These types are also defined as member types of the stream class.
 *
 * ============================================================================
 * Type 	Member type 		Description
 * ============================================================================
 * streampos     ios::pos_type        Defined as fpos<mbstate_t>
 * 				      it can be converted to/from streamoff and
 * 				      can be added or subtracted value of 
 * 				      these types.
 *
 * streamoff 	 ios::off_type	      If is an alias of one of the fundamental
 * 				      integral types(such as int or long long).
 * 
 * Each of the member type above is an alias of it non member equivalent 
 * they are the exact same type. It does nto matter which one is used. 
 * The member type are more generic because they are same on all streams object
 * (even on streams using exotic type of characters) but the non-member type
 * are widely used in the existing code for the historical reason.
 */

/*
 * Binary files
 * ============
 *
 * Binary files reading and writing data with the extraction and inseertion
 * operators (<< and >>) and functino like getline is not efficient, since
 * we do not need to format any data and data is likely not formated in lines.
 *
 * File streams include two member function specifically designed to read and
 * write binary data sequentially write and read. The first one (write) is a
 * member function of ostream class (inherited by ofstream) and read is a 
 * member function of istream (inherited by ifstream). An object of class
 * fstream have both. Their prototype area :...
 *
 * 	write (memory_block, size);
 * 	read  (memory_block, size);
 *
 * Where memory_block is type of char* (pointer to char), and represents the
 * address of an array of bytes wher the read data elements are stored or 
 * from where the data elements to be written  are taken. The size parameter is 
 * an integer value that specifies the number of character to be read or 
 * written from/to the memory block.
 */
#ifdef _FIVE_

int main () {
	streampos size;
	char * memblock;

	//ifstream myfile("iowithfiles.o", ios::binary | ios::ate);
	ifstream myfile("example_2.txt", ios::ate);

	if(myfile.is_open() ) {
		size = myfile.tellg();

		memblock = new char[size];

		myfile.seekg (0, ios::beg);

		myfile.read(memblock, size);

		myfile.close();

		cout << "_FIVE_ an Example" << endl;
		cout << "=================" << endl;
		cout << endl;
		cout << "The entire file contents in the memory" << endl;
		cout << endl;
		cout << memblock << endl;
		delete [] memblock;
	}
	else {
		cout << "Unable to open file binary....!" << endl;
		cout << "_FIVE_ an Example" << endl;
		cout << "=================" << endl;
	}
     return 0;
}
#endif

/*
 * In this example above the entire file is read and stored in a memory block.
 * Lets examine how this is done.
 *
 * First the file is open with the ios::ate flag, which means the get pointer
 * will be positioned at the end of the file. This way when we can call to
 * a member function tellg(), we will directly obtain the size of the file.
 *
 * Once we have obtained the size of file, we request the allocation of memory
 * block large enough to hold the entire file.
 *
 * 	memblock = new char[size] ;
 * 
 * Right after that we proceed to set the get position at the beginning of the
 * file (remember that we opned the file with this pointer at end), then we
 * read the entire file in the memblock and finally closed the file.
 *
 * 	myfile.seekg(0, ios::beg);   // file pointer moved to beginning
 * 	myfile.read(memblock, size)  // read entire file in memblock with size
 * 	file.close()		     // now close the file, for good.
 * 
 * All this point we could operate with the data obtained from the file. But 
 * our program simply announces that the content of the file is in the 
 * memory and the finishes.
 */
 			
/*
 * Buffers and Synchronisation
 * ===========================
 *
 * Wben we operates with file streams, these are associated to an internal 
 * buffer object of type streambuf. This buffer object may represent a memory
 * blocks that act as an intermediatory between the stream and the physical 
 * file. For an example, with an ofstream, each time the member function put
 * (which writes a sing character) is called the character may be inserted in 
 * this intermediate buffer instead of being written directly to the physical
 * file with which the stream is associated.
 *
 * The operating system may also define other layers of buffering for reading
 * and writing to file.
 *
 * When the buffer is flushed all the data contained in the its written to the
 * physical medium (if it is an output stream). This process is called as
 * Synchronisation and takes, place under any of the following circumstances.
 *
 *    -	When the file is closed:
 * 	before closing file all the buffer that have not yet been flushed are
 * 	synchronised and all pending data is written to read to physical 
 * 	medium.
 *
 *    -	When the buffer is full
 *      Buffer have a certain size. When the buffer is full it is automatically
 *      synchronised.
 *
 *    - Explicitly, with manipulators
 *      When certain manipulators are used on streams, and explicit
 *      synchronisatiion take place. These manipulation are flushed and endl.
 *
 *    - Explicitly with member function sync()
 *      Calling the stream's member function sync() causes an immediate
 *      synchronisation. This function return an all int values equal to -1.
 *      If the stream has no associated buffer or in case of failure.
 *      Otherwise (if the stream buffer was successfully synchronised)
 *      return 0.
 */
            		 	 
