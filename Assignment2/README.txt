Oct 22, 2016
COT5930 - Applied Cryptography
Student's names:
Deepthi Chigurupalli
Patorn Pongsanit
Khoa Hoang

Assignment 2: Implimenting the DES
For this assignment we use python to program the DES encryption and decryption, then we apply the Cipher Block Chain mode.

Requirements:
	-Python 2.7
	-Install some extra modules such as: Numpy, bitstring, binascii
	-For the IDE, you can use Visual Studio, or PyCharm, or WingIDE

There are two main parts in the zip file, DES_Encrypt.py and DES_Decrypt.py
When you run the encryption part, the program will call the ClassProcess.py which contains all the functions for the encryption
So make sure you also copy all the tables text and ClassProcess.py.
Do the same thing when you run decryption, copy all the table text and ClassProcess.py into the same directory

When you execute the DES_Encrypt, it will ask you to enter a plain text that you want to encryp. You can enter any character, 
however, the length should be 8xn. This means that you have to enter 8 or 16 or 24 ... characters.

Then it will ask you to enter a key. To make it easy, it just asks you to enter any key you like 
but its lenght has to be longer 3 and smaller 8 characters. 
In case you enter a short key (length <8), it will automatically add 1 or 0 to generate a 64bits key.
The key for the encryption and decryption must be the same.

For the sake of displaying, the encryption will render an encrypted text in hexadicemal value. The encryption would return a
weird encrypted text if it displays in ascii character.

For the Initialization Vector: a string of 0 and 1 is assigned to this vector => see in the TableIV.txt

When you execute the Decryption parts, it will ask you to enter encrypted text (hexadicemal value) and the key.
It will return exactly the same plain text that you enter in the encryption part if you provide the same key.



