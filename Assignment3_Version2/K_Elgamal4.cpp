//Applied Cryptography - Patorn, Khoa, Deepthi
//ElGamal encryption and decryption implementation

#include <boost/multiprecision/cpp_int.hpp>

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#define L2 long long 
#define BigD1 k_mp::cpp_int // cpp_int is a big big type of integer / BigD1 = Big Data
#define BigD2 unsigned long int
namespace  k_mp = boost::multiprecision;
using namespace std;


//Function: this is prime generator based on Fermat's little theorem
BigD1 Prime_generator(L2 Ksize) {

	BigD1 power2, tt, a, t5, base = 2; 

	power2 = pow(base, Ksize) / 2;

	bool Found;
	do {
		srand(time(NULL)); //reset timer 
		Found = true;
		tt = 2 * (rand() % power2) + 1;
		unsigned long long int t3 = long long int(tt);
		unsigned long long int aa;
		//limit a
		if (Ksize >= 16) {			//the size of key 
			aa = rand() % (256 / Ksize + 10);
		}
		else aa = t3 - 1;

		for (a = 2; a <= aa; a++) {
			t5 = (pow(a, t3 - 1)) % t3;
			//n = long int(t5);
			if (t5 != 1) {
				Found = false;
				break;
			}

		}

	} while (Found == false);
	return tt;
}

//Power then mod
BigD1 PowMod(BigD1 base, BigD1 exp, BigD1 mod) {
	BigD1  powmod = 1,  y = base;
	while (exp > 0) {
		if (exp % 2 == 1) powmod = (powmod*y) % mod;
		y = (y*y) % mod;
		exp /= 2;
	}

	return powmod%mod;
}

// Multiply mod
BigD1 mul_mod(BigD1 a, BigD1 b, BigD1 mod) {
	BigD1 x = 0, y = a%mod;
	while (b > 0) {
		if (b % 2 == 1) x = (x + y) % mod;
		y = (y * 2) % mod;
		b /= 2;
	}
	return x%mod;
}

/*Miller-Rabin Primality Test
3 steps
1> Find pr - 1 = (2^k)*m
2> Choose a: 1<a<pr-1
3> Compute b0 = a^m(mod pr), bi = [b(i-1)]^2
*/
//Miller-Rabin Primality Test
bool MillerRabin(BigD1 pri_test) {
	//check prime condition first
	if (pri_test < 2) return false;
	if (pri_test != 2 && pri_test % 2 == 0) return false;

	int ii = 10; // ii is the time to choose a to test

	BigD1  phi = pri_test - 1;
	BigD1 k = phi; //save value
//Step 1: find pr-1 = (2^k)*m

	while (k % 2 == 0) 	k /= 2; 

//step 2: Choose a: 1<a<pr-1, ii is iteration, ii=10 for example

	for (int j = 1; j < ii; j++) {
		BigD1 a = 1 + rand() % (pri_test - 2), temp = k;
		// step 3: Compute b0 = a^m(mod pr), bi = [b(i-1)]^2

		BigD1 b0 = PowMod(a, temp, pri_test);
		while (temp != phi && b0 != 1 && b0 != phi) {
			b0 = mul_mod(b0, b0, pri_test);
			temp *= 2;
		}
		if (b0 != phi && temp % 2 == 0) return false;
	}
	return true;
}

//Do the Modulus by using the Square-and Multiply algorithm
BigD1 K_modulus(BigD1 prime, int aa, int bb) {
	
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
	BigD1* ArrP2 = new BigD1[m]; //Arrp2 to contain 2 to power

	int indexB = 0;
	while (bb != 0) {
		r = bb % 2;
		BitArray[indexB++] = r;
		bb /= 2;
	}

	//gg to the power of xx then mod pr

	ArrP2[0] = aa;
	BigD1 pp2;
	for (int jj = 1; jj < m; jj++) {
		pp2 = pow(ArrP2[jj - 1], 2);
		ArrP2[jj] = pp2 % prime;
	}
	//now calculate the final value of modulus	
	BigD1 Temp = 1; //the problem is here, if do not give a right data type it will not work properly
	for (int nn = 0; nn < m; nn++) {
		if (BitArray[nn] != 0) {
			Temp = Temp*ArrP2[nn];
		}
	}

	BigD1 ValueY = Temp%prime;

	delete[] BitArray;
	delete[] ArrP2;
	return ValueY;

}

/*-------------- Main program -----------------*/

int main()
{
	cout << "*** ElGamal encryption and decryption implementation ***" << endl;
	cout << "************** Deepthi - Patorn - Khoa *****************" << endl << endl;
	/*      Part I-- Generating a prime number   */

	int  key_size, Count_generate = 0; //http://primos.mat.br/primeiros_10000_primos.txt
	
	int limitKey = 256; //limit the size of key, number of bits
	
	do {		
		cout << "Enter a key size (bit) of a prime number, for example 2, 4, 10, 32, ... 256 bit----: ";
		cin >> key_size;	
		
	} while (key_size > limitKey || key_size <= 1);

	//for (unsigned i = 1; i <= pr; i++) {power2 *= 2;}

	BigD1 base = 2, p_2;
	p_2 = pow(base, key_size);
	cout << "The range of prime number is " << p_2 << endl;

	bool checkP;
	BigD1 NumPrime;
	do {
		//Call Fermat's little theorem function to generate a prime number
		NumPrime = Prime_generator(key_size);
				
		checkP = MillerRabin(NumPrime);
		Count_generate += 1;

	} while (!checkP);


	cout << "#################" << endl;
	cout << "The number of time to run Fermat function to generate a prime number is " << Count_generate << endl;
	cout << "---- And the prime number is " << NumPrime << endl;
	cout << "#################" << endl << endl;


	//********Finishing part I *********************

	/* Part 2, Choosing G (gamal) number and generate public key */

	int gg;
		
	do {		
		cout << "Enter a G number; G should be in range (1, " << NumPrime - 1 << ")" << endl;
		cin >> gg;
				
	} while (gg >= NumPrime || gg <= 1);

	//Enter secret key
	int xx;
	do {
		cout << "Select a random number for your secret key; x in range (1, " << NumPrime - 1 << ")" << endl;
		cin >> xx;

	} while (xx >= NumPrime || xx <= 1);
	cout << "Your SECRET KEY is: " << xx << endl;


	BigD1 yy_temp;
	// Calculate Y = (G to the power of xx) mod P
	//call the function to do the modulus
	yy_temp = K_modulus(NumPrime, gg, xx);

	int yy = int(yy_temp); //convert data type

	cout << "The PUBLIC KEYs are (use these parameters to do the encryption): ";
	cout << "p= " << NumPrime << " and G = " << gg << " and Y= " << yy << endl << endl;

	/* #### Part 3: Encrypting the message*/

	//Encryption
	cout << "*********** Encryption part********************" << endl;
	int message;
	do {
		cout << "Enter the message you want to send, message must be in range (1, " << NumPrime - 1 << ")" << endl;
		cin >> message;

	} while (message >= NumPrime || message < 1);

	cout << endl;


	int k;
	do {
		cout << "Select a random number for your k; k in range (1, " << NumPrime - 1 << ")" << endl;
		cin >> k; //k is the number that Alice chooses

	} while (k >= NumPrime || k <= 1);

	BigD1 gamma_temp = K_modulus(NumPrime, gg, k);

	BigD2 gamma = BigD2(gamma_temp);

	cout << "The value of gamma is " << gamma << endl;

	BigD1 Kag_temp = K_modulus(NumPrime, yy, k);

	BigD2 Kag = BigD2(Kag_temp);

	BigD2 cc = message * Kag; //cc is the value of the cipher text

	cout << "The value of cipher text is " << cc << endl;;
	cout << "Send these values to the other party for decryption (" << gamma << "," << cc << ")" << endl << endl << endl;

	/* ########### Part 4: Decryption ##############*/
	//Decryption

	cout << "*********** Decryption part********************" << endl;
	BigD1 decrypt_temp = K_modulus(NumPrime, gamma, xx);
	BigD2 decrypt = BigD2(decrypt_temp);
	BigD2 ptext = cc / decrypt;
	cout << "The plain text you have entered: " << endl;
	cout << "Here it is " << ptext <<endl << endl;

	system("PAUSE");
	return 1;
}