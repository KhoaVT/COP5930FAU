from array import*
import numpy as np
from ClassProcess import*
import string

print "**********************************************\n"
print "---------DES encryption test------------------\n"
print "**********************************************\n\n"

#Ask input message to do the encryption
'''
while True:
    ptext = raw_input ("Please enter the plain text (8 characters) to encrypt: ")
    if len(ptext) <>8:
        print "Plain text must be 8 characters\n"   
        continue
    else:
        
        break

print "This is the message that you want to encrypt: \n"
print "            " + ptext +"\n"

TextIn=[]
binaryK = ''.join(format(ord(x), 'b').zfill(8) for x in ptext)
for i in binaryK:
    TextIn.append(int(i))

'''


while True:
    Plaintext = raw_input ("Please enter the plain text (16 hexa) to encrypt: ")
    if len(Plaintext) <>16:
        print "Plain text must be 16 hexadecimal characters\n"   
        continue
    elif (all(c in string.hexdigits for c in Plaintext)==False):
        print "Plain text must be hexadecimal \n"
        continue

    else:
        
        break

print "This is the plain text that you want to encrypt: \n"
print "            " + Plaintext +"\n"

Key_Processing = KeyProcess() #Call the KeyProcess class 

Hex_Bin = Key_Processing.convert(Plaintext,2)
Plaintext_input=[]
Pt_Hex=''.join('{:08b}'.format(int(x, 16)) for x in Hex_Bin)
for i in Pt_Hex:
    Plaintext_input.append(int(i))

#Finish getting the message 
#Now ask for the key to encrypt
'''
while True:
    K_text = raw_input ("Please enter a key to encrypt: ")
    if len(K_text) <3:
        print "Your key is too short\n"   
        continue
    elif len(K_text) >= 9:
        print "Your key is too long characters\n"   
        continue
    else:
        
        break

print"This is the key that you enter:  " + K_text +"\n"

KeyIn=[]
binKey = ''.join(format(ord(x), 'b').zfill(8) for x in K_text)
for i in binKey:
    KeyIn.append(int(i))

#In case that the length of the key is less than 64 bits => add '1' to make up 64 bit
if len(KeyIn)<64:
    for j in range(0,(64-len(KeyIn))):
        KeyIn.append(1)

'''
print "The key for this example is 3b3898371520f75e \n"
print "you can go to this website to verify:"
print "http://people.eku.edu/styere/Encrypt/JS-DES.html"
KeyIn = [0,0,1,1,1,0,1,1,0,0,1,1,1,0,0,0,1,0,0,1,1,0,0,0,0,0,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,0]

####################
#Read the Table PC to an array
####################



TablePC1 =Key_Processing.ReadFile('TablePC1.txt')

#Read value of key in the case that key is given before hand
#TempK1 =Key_Processing.ReadFile('key.txt')

TempK1 = KeyIn
TempK1 =np.insert(TempK1,0,1)  #Insert '1' to increase index number since the table PC count from 1, not from 0'

#Do the permatation 1 according to the table PC1
#trim off the original key from 64 bits to 56 bits
Permuation1 =TempK1[np.array(TablePC1)] 

#Split the key (56bits) into left and right halves, C0 and D0
C0 = Permuation1[0:28]
D0 = Permuation1[28:]

#Call the class KeyProcess to do the shifting in the class file

C= Key_Processing.shift2(C0)

#C=> after shifting => get 16 left hafl keys in the array X which return from function shifting
C= C.tolist() #Convert C from array to list

#shift2(D0) # call funtction to do the right half D0
D= Key_Processing.shift2(D0)
D=D.tolist()

'''
#This is the second way to do the shifting by using a function in the library

C01= C0.tolist() #convert array back to list since shift function won't work in array
D01= D0.tolist()
#now call function shift to shift C01 and D01
C1 = shift(1,C01)
D1 = shift(1,D01)
print "C1 and D1"
print C1
print D1
C2 = shift (1,C1)
D2 = shift(1,D1)

C3 = shift (2,C2)
D3 = shift(2,D2)

and so on ...
'''
#Perform second permatation for subkeys
#call function to do the permation PC2
KeyA = Key_Processing.permutationPC2(C,D) #The array KeyA contain 16 subkeys"

''' 
#################################
Now process the data. This step will use some functions in the key_process class
#################################
'''
#Read the initiate permuation for the data IP
TableIP =Key_Processing.ReadFile('TableIP.txt')
#Read the data input (the plain text to encrypt)
#Plaintext = Key_Processing.ReadFile('data.txt')

Plaintext_input = np.insert(Plaintext_input,0,1) #Insert '1' to increase index number since the table IP count from 1, not from 0
#Do the permatation 1 according to the table Initial Permutation IP
IP_text =Plaintext_input[np.array(TableIP)] #IP_text is the text after IP"

#Split the IP text (64bits) into left and right halves, L0 and R0
L0 = IP_text[0:32]
R0 = IP_text[32:]

###########

Data_Processing = DataProcess() #Call the Data Process class 
ArrayText,EncryptText = Data_Processing.process_text(L0,R0,KeyA)

print "This is the encrypt text - it is in hexadecimal form \n"
print "                 " + EncryptText
print "\n ****************  Finish  ******************************\n"

