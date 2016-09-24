'''
The Euclidean algorithm expressed in pseudocode is:
##########
procedure gcd(a, b: positive integers)
x := a
y := b
while   y ? 0
       r := x mod y
       x := y
       y := r
return x
######
'''

import math

def checkingInverse(x,y):
    x1=x # save the value of x and y to do the reverse if their GCD =1
    y1=y
    while y!=0:
        r=x%y
        print "\t" + str(x) + " = " + str(y) + "x" + str((x-r)/y) + " + "+str(r)
        x=y
        y=r
    print "\n"

    if (x==1): #do the reverse side
        print "GCD(" +str(a) +"," +str(b)+")=1 =>inverse exists \n"
        while y1!=0:
            r1=x1%y1
            if (r1 !=0):
                print "\t" + str(r1) +" = " + str(x1) + " - " +  str((x1-r1)/y1) + "x" + str(y1)
            x1=y1
            y1 =r1
        print "\n"
    else:
         print "There is no inverse of "+ "(" +str(a) +"," +str(b)+") \n"
    return 

#Main program

print "Checking if there is an invers of a modulo b"
print "Or to see if there is an integer x that (b mod ax = 1)"
print "#####################################"

print "Please enter a (a is congruent, integer)"
a=input()
print "Please enter b (integer; b larger than a)"
b=input()

print "#####################################"
#Call checking inverse function
checkingInverse(b,a)

