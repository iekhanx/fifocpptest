///////////////////#define none       "\033[0m"            /* to flush the previous property */
//#define none       "\033[0m"            /* to flush the previous property */
/////////////////////////////////////////////
//
// Program : Roman number generator from an integer value
//
// Date    : 03/11/2014
//
// Test    : Input from keyboard
//////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <exception>
#include <string>
#include <cstring>

// Make it pretty...
#define cyan       "\033[1;36m"     /* 1 -> bold ;    36 -> cyan */
#define yellow     "\033[1;33m"

#define cls        "\033[2J\033[1;1H"   /* Clear the screen */
#define none       "\033[0m"            /* to flush the previous property */


using namespace std;

class CRoman {

public:
   char str[4090];
   int  i;

   CRoman(int a) : i(a) {};

   void headval(char val1, char val2)   {
      str[i++] = val1; str[i++] = val2; }

   void tailval(char val1, char val2)  {
     int j;
     for(j=0; j<val2; j++)
          str[i++] = val1;              }
};

int getIntegerValue()
{
    string input = "";
    int nval;
    
    while(true) {
    cout << "Enter Integer number to convert in Roman numerals: ";
    getline(cin, input);
    stringstream myStream(input);   // convert string to number
    if(myStream >> nval) 
       break;
     cout << "Invalid Number." << endl;
    }
  return nval;
}

int main()
{
    int j;
    long number;
    CRoman roman(0);

    // Clear the screen
    cout << cls << endl;

    number = getIntegerValue();

    if (number <= 0) {
      cout << "Zero value entered. Terminating" << endl;
     }

    while (number != 0) {
     
        if (number >= 1000)
        {
            roman.tailval('M', number / 1000);
            number = number - (number / 1000) * 1000;
        }
        else if (number >= 500)
        {
            if (number < (500 + 4 * 100))
            {
                roman.tailval('D', number / 500);
                number = number - (number / 500) * 500;
            }
            else
            {
                roman.headval('C','M');
                number = number - (1000-100);
            }
        }
        else if (number >= 100)
        {
            if (number < (100 + 3 * 100)) 
            {
                roman.tailval('C', number / 100);
                number = number - (number / 100) * 100;
            }
            else
            {
                roman.headval('L', 'D');
                number = number - (500 - 100);
            }
        }
        else if (number >= 50 )
        {
            if (number < (50 + 4 * 10))
            {
                roman.tailval('L', number / 50);
                number = number - (number / 50) * 50;
            }
            else
            {
                roman.headval('X','C');
                number = number - (100-10);
            }
        }
        else if (number >= 10)
        {
            if (number < (10 + 3 * 10))
            {
                roman.tailval('X', number / 10);
                number = number - (number / 10) * 10;
            }
            else
            {
                roman.headval('X','L');
                number = number - (50 - 10);
            }
        }
        else if (number >= 5)
        {
            if (number < (5 + 4 * 1))
            {
                roman.tailval('V', number / 5);
                number = number - (number / 5) * 5;
            }
            else
            {
                roman.headval('I', 'X');
                number = number - (10 - 1);
            }
        }
        else if (number >= 1)
        {
            if (number < 4)
            {
                roman.tailval('I', number / 1);
                number = number - (number / 1) * 1;
            }
            else
            {
                roman.headval('I', 'V');
                number = number - (5 - 1);
            }
        }
    }
   
    cout << endl; 
    cout << yellow << "\t\tThe Hail Ceaser" << none << endl;
    cout << yellow << "\t\t***************" << none << endl;

    cout << "The Roman Numeral is --> ";
  
    for(j = 0; j < roman.i; j++)
       cout << cyan << roman.str[j];
       
      cout << none << endl << endl;;
    return 0;
}     
 
         
