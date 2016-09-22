import math
from array import*

#function to check primitive root
def checking(a,b):

    resultMod =[] #initiate an array to content the integer 1 to p-1
    arrayA = range(1,a)

    for ii in arrayA:
        test1=int(math.pow(b,ii))
        numIn = int(test1%p)
        resultMod.append(numIn)

    print "The result of mod " + str(a)
    print resultMod

    print "##########################" +'\n'

    #Check to see if there is duplicate value
    countMod =0
    for kk in resultMod:
        if (resultMod.count(kk)>1):
            countMod +=1

    if (countMod>0):
        print str(b) +" is not the primitive root of " +str(a)
    else:
        print str(b) +" is the primitive root of " +str(a)
    return

#Main program check primitive root 

print "Check a number of a primitive root of prime number p"

print "Please enter a prime number"
p=input()
print "Please enter a number to check primitive root"
x=input()

checking (p,x);





    
