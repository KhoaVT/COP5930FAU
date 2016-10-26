
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;



int main()
{
	int pr;
	bool Found = false;
	do {
		cout << "Enter a prime number:";
		cin >> pr;
		int count = 0; //reset counter
		for (int ii = 1; ii < pr; ii++) {
			if (pr%ii == 0)
				count += 1;
		}
		if (count >= 2)
		{
			cout << "pr " << pr << " is NOT prime" << endl;
			Found = false;
		}
		else
		{
			cout << "pr " << pr << " is prime" << endl;
			Found = true;
		}

	}
	while (Found == false);

	cout << "Congratulation! You have found a prime pr: " << pr << endl;
	//Now enter g number
	int gg;

	do {
		cout << "Enter a G number; G should be in range (1, "<< pr-1 << ")" <<endl;
		cin >> gg;

	} while (gg>=pr || gg<=1);


	//Enter secret key
	int xx;
	do {
		cout << "Select a random number for your secret key; x in range (1, " << pr - 1 << ")" << endl;
		cin >> xx;

	} while (xx >= pr || xx <= 1);
	cout << "Your SECRET KEY is: " << xx << endl;

	unsigned long long yy = pow(gg, xx);
	// Calculate Y = (G to the power of xx) mod P
	yy = yy%pr;

	cout << "The PUBLIC KEYs are (use these parameters to do the encryption): ";
	cout << "p= " << pr << " and G = " << gg << " and Y= " <<yy<< endl;


	//system("PAUSE");
    return (0);
}

