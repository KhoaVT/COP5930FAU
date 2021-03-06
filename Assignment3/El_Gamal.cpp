//Applied Cryptography - Patorn, Khoa, Deepthi
//ElGamal encryption and decryption implementation
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int K_modulus(int prime, int aa, int bb) {
	
	int m = 0; //initialize the length of the binary array of xx
	int lenxx = bb; //save the value of the key xx for the next calculation
	int r;
	//compute the length of xx in binary
	while (lenxx != 0) {
		r = lenxx % 2;
		m++;
		lenxx /= 2;
	}
	
	int* BitArray = new int[m];
	unsigned long int* ArrP2 = new unsigned long int[m]; //Arrp2 to contain 2 to power

	int indexB = 0;
	while (bb != 0) {
		r = bb % 2;
		BitArray[indexB++] = r;
		bb /= 2;
	}

	//gg to the power of xx then mod pr
	
	ArrP2[0] = aa;
	unsigned long long int pp2;
	for (int jj = 1; jj < m; jj++) {
		pp2 = pow(ArrP2[jj - 1], 2);
		ArrP2[jj] = pp2 % prime;
	}
	//now calculate the final value of modulus	
	unsigned long long int Temp = 1;
	for (int nn = 0; nn < m; nn++) {
		if (BitArray[nn] != 0) {
			Temp = Temp*ArrP2[nn];
		}
	}

	unsigned long int ValueY = Temp%prime;
	
	delete[] BitArray;
	delete[] ArrP2;
	return ValueY;

}

/*-------------- Main program -----------------*/
int main()

{
	cout << "*** ElGamal encryption and decryption implementation ***" << endl;
	cout << "************** Deepthi - Patorn - Khoa *****************" << endl<<endl;
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


	unsigned long int yy ;
	// Calculate Y = (G to the power of xx) mod P
	//call the function to do the modulus
	yy = K_modulus(pr, gg, xx);

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
	

	int k;
	do {
		cout << "Select a random number for your k; k in range (1, " << pr - 1 << ")" << endl;
		cin >> k; //k is the number that Alice chooses

	} while (k >= pr || k <= 1);
	
	unsigned long int gamma;
	gamma = K_modulus(pr,gg,k);
	cout << "The value of gamma is " << gamma << endl;

	unsigned long int Kag;
	Kag = K_modulus(pr, yy, k);

	unsigned long int cc = message * Kag; //cc is the value of the cipher text
	
	cout << "The value of cipher text is " << cc << endl;;
	cout << "Send these values to Bob (" << gamma << "," << cc << ")" << endl<<endl; //c 
	

	//Decryption

	cout << "*********** Decryption part********************" << endl;
	unsigned long int decrypt;
	decrypt = K_modulus(pr, gamma, xx);

	int ptext = cc / decrypt;
	cout << "The plain text you have entered: " << endl;
	cout << "Here it is " << ptext << endl;

	system("PAUSE");
	return (0);
}


