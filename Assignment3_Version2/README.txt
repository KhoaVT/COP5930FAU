Nov 10, 2016
COT5930 - Applied Cryptography
Student's names:
Deepthi Chigurupalli
Patorn Pongsanit
Khoa Hoang

Assignment 3: Implimenting El gamal Encryption
For this assignment we use C++ to write the program. 

Requirements:
- C++
- Boost C++ library (can download here: http://www.boost.org/)
(Read the document to do the installation, final important step: include the directory path to the property of the project)

A demo clip of the program is posted here: https://www.youtube.com/watch?v=t_oYxcWM9QM
You will have some ideas about our program from watching the demo clip above.

The execution part:

When the program is executed, it will ask user to enter a size of the key. The size can be 2bits, 10 bit, 15bits .. 256bit
The program will use Fermat's little theorem and Miller-Rabin primality test algorithm to generate a prime number based on the size of the key.
The process of generating prime number can take a long time (10 seconds, 15 seconds ...), it depends on how fast your pc is.

Next it will ask you to enter any value gg, gg must be in range (1, pr-1)
Next, you enter a secret key xx, xx must be in range (1,pr-1)
Next, you enter a value representing the message that you want to send.

Encryption
The program will ask you enter an integer k number to do the encryption, k must be in range (1,pr-1)

Then the program will automatically do the encryption and decryption to return the value of the message that you entered.





