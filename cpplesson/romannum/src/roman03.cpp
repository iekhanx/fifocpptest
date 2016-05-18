
#include <iostream>
using namespace std;

string intToRoman(int num) {
	string roman;
	int th,h,t,o;
	char *ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
	char *tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	char *hundreds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	char *thousands[] = {"","M","MM","MMM","MMMM","MMMMM"};

	//if (num =< 4000) {
	if (num <= 4000) {
		th = num / 1000;
		num = num % 1000; //Get rid of 1000s

		h = num / 100;
		num = num % 100; //Get rid of 100s

		t = num / 10;
		o = num % 10;
		roman += thousands;
		roman += hundreds[h];
		roman += tens[t];
		roman += ones[o];
	}
	else
		roman = "Please enter a smaller number \n";
	return roman; 
}

int main()
{
	int num;
	cout<<"What number would you like to convert between 1 and 3999? ";
	cin>>num;
	string output = intToRoman(num);
 //	system("pause");
	return 0;
}

// Read more: http://www.physicsforums.com 
