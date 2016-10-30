//Applied Cryptography - Patorn, Khoa, Deepthi
//ElGamal encryption and decryption implementation
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

			if (count == 2) {
				cout << "pr " << pr << " is NOT prime" << endl;
				Found = false;
				break;

			}
		}
		if (count == 1)

		{
			cout << "pr " << pr << " is prime" << endl;
			Found = true;
		}

	} while (Found == false);

	cout << "Congratulation! You have found a prime pr: " << pr << endl;
	//Now enter g number
	int gg;

	do {
		cout << "Enter a G number; G should be in range (1, " << pr - 1 << ")" << endl;
		cin >> gg;

	} while (gg >= pr || gg <= 1);


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
	cout << "p= " << pr << " and G = " << gg << " and Y= " << yy << endl<<endl;


	//Encryption


	cout << "*********** Encryption part********************" << endl;
	int message;

	do {
		cout << "Enter the message you want to send, message must be in range (1, " << pr - 1 << ")" << endl;
		cin >> message;

	} while (message >= pr || message < 1);

	cout << endl;
	

	int k = 0;
	do {
		cout << "Select a random number for your k; k in range (1, " << pr - 1 << ")" << endl;
		cin >> k; //k is the number that Alice chooses

	} while (k >= pr || k <= 1);
	
	unsigned long long gamma = pow(gg, k);
	gamma = gamma%pr;
	cout << "The value of gamma is " << gamma << endl;

	unsigned long long cc = message * pow(yy, k); //cc is the value of the cipher text
	cc= cc%pr;
	cout << "The value of cipher text is " << cc << endl;;
	cout << "Send these values to Bob (" << gamma << "," << cc << ")" << endl<<endl; //c 
	

	//Decryption

	cout << "*********** Decryption part********************" << endl;
	unsigned long long decrypt = pow(gamma, xx);
	decrypt = decrypt%pr;

	int ptext;
	for (int kk = 1; kk <= pr; kk++) {
		if ((pr*kk + cc) % decrypt == 0){
		ptext = (pr*kk + cc) / decrypt;
		cout << "The plain text: " << endl;
		cout << "Here it is " << ptext << endl;
		break;
		}
		

	}

	

	system("PAUSE");
	return (0);
}


