#include <iostream>

#include <cmath>

#include <string>

 

using namespace std;

 

//Declare Variables

void PrintRoman (int x);

int x;

//---------------------------------------------------------------------------

 

int main()

{

 

        cout << "Please enter an integer value below 5000 that you would like to be converted to Roman numerals and press Enter:" << endl << endl;

        cout << "Your integer is: ";

        cin >> x;

        cout << endl;

 

        PrintRoman(x);

 

        cin.get ();

        cin.get ();

        return 0;

}

 

void PrintRoman (int x)

{

 

        //Declare Variables

        int nM;

        int nD;

        int nC;

        int nL;

        int nX;

        int nV;

        int nI;

 

        //design an algorithm to convert an integer to a Roman Numeral.

 

        //Thousands (M's) = x/1000

        nM = x/1000;

 

        //Display nM number of M's

        switch (nM)

        {

                case '0' : cout << "";

                break;

                case '1' : cout << "M";

                break;

                case '2' : cout << "MM";

                break;

                case '3' : cout << "MMM";

                break;

                case '4' : cout << "MMMM";

                break;

                case '5' : cout << "MMMMM";

                break;

        }

 

        //Get xremainder x%1000

        x = x%1000;

 

        //500s (D's) = x/500, and remainder

        nD = x/500;

        x = x%500;

 

        //Display nD number of D's

        switch (nD)

        {

                case '0' : cout << "";

                break;

                case '1' : cout << "D";

                break;

        }

 

        //Hundreds (C's) = x/100

        nC = x/100;

        x = x%100;

 

        //Display nC number of C's

        switch (nC)

        {

                case '0' : cout << "";

                break;

                case '1' : cout << "C";

                break;

                case '2' : cout << "CC";

                break;

                case '3' : cout << "CCC";

                break;

                case '4' : cout << "CD";

                break;

        }

 

        //Fiftys (L's) = x/50

        nL = x/50;

        x = x%50;

 

        //Display nL number of L's

        switch (nL)

        {

                case '0' : cout << "";

                break;

                case '1' : cout << "L";

                break;

        }

 

        //Tens (X's) = x/10

        nX = x/10;

        x = x%10;

 

        //Display nX number of X's

        switch (nX)

        {

                case '0' : cout << "";

                break;

                case '1' : cout << "X";

                break;

                case '2' : cout << "XX";

                break;

                case '3' : cout << "XXX";

                break;

                case '4' : cout << "XL";

                break;

        }

 

        //Fives (V's) = x/5

        nV = x/5;

        x = x%5;

 

        //Display nV number of V's

        switch (nV)

        {

                case '0' : cout << "";

                break;

                case '1' : cout << "V";

                break;

        }

        //Ones (I's) = x/1
        nI = x;

        //Display nI number of I's

        switch (nI)

        {

                case '0' : cout << "";

                break;

                case '1' : cout << "I";

                break;

                case '2' : cout << "II";

                break;

                case '3' : cout << "III";

                break;

                case '4' : cout << "IV";

                break;

        }

 

}

