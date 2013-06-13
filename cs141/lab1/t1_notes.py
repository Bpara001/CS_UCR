###//////////////////////////////////
### 1. basic hello world program ###
###//////////////////////////////////
print "hello world" #prints the string "hello world"



###//////////////////
### 2.Variables: ###
###/////////////////
#We do not declare variables
#no real constants
s = 1 			#int variable
m = "Suntinwong"	#string
pi = 3.14		#double

type(s)			#debugging, states what type 's' variable is



###//////////////////
### 3.Operations  ###
###//////////////////
#basic: +,-,*,/,%
#more: pow(a,b)

#operations are executed left from right
#operations follow basic order of operations

print "operations - integers"
print 5+2
print 10-3
print 20 * 4
print 12/4
print 8%3

#operations for string: +,*

print "operations - strings"
print "I dont like this class" + " because..."
print "repeatx3 " * 3



###////////////////
### 4.Input/Output:
###////////////////
#you can print multiple stuffs:
a = "string_varaible "
print 1,2,3,a,"hello"

#getting input
n = raw_input("Input integer ")
print "You typed: ", n

###/////////////////
### 5.Functions ###
###////////////////
"""
def function_name(list of parameters):
	statement1
	statement2

other defined functions: 
abs(x)
c = max(1,2,3,-10)


#inporting:
ex.
from test2 import *

"""
#function: quadratic equation
def print_solution(a,b):
	x1 = (-a+(a**2 -4*b)**0.5)/2.0
	x2 = (-a +pow(pow(a,2)-4*b,0.5))/2.0
	print x1,x2
	
a = input("Enter a: ")
b = input("enter b: ")
print_solution(a,b)




###////////////////////
### 6.Conditionals ###
###////////////////////
"""
bool expressions:
x == y
x != y
x > y
x < y
x >= y
x <= y

logic operations:
and, orc, not
"""

#basic if statement
if x> 0:
 print "x is greater then zero"

if x> 0 and x < 10:
 print "x is between 0 and 10"

#basic if else staement
if x%2 == 0:
 print "even"
else:
 print "odd"

#basic if else if statment
if x==1:
 print "x is 1"
elif x==2:
 print "x is 2"

###/////////////////////////
### 7.Type Convertion ###
###////////////////////////

a = "32"
b = int(a)
b = int("32")
b = int(1.5)  #becomes 1
b = int(-1.5) #becomes -1
b = int(0.8988) #becomes 0
b = str(1) #becomes "1"
b = float(1) #becomes 1.0



###//////////////
### 8.Loops ###
###//////////////

#using a while loop
i = 1
while i <= 10
 print i
 i = i +1



#using a for loop
for i in range(0,3)
	print "hello"


###/////////////////////////
### 9. More on strings ###
###/////////////////////////

import string

s = "Hello"
print s[0] #prints 'H'
print len(s) #prints '5', or length of the string
print s[-1] #prints '-o' or last char
print s[-4] #prints 'e', or 4th to last char
print s[1:3] #prints "el", or antyhing between the 1st and 3rd character
print s[:3] #prints "Hel", or anything up to the 3rd character
print s[:] #prints "Hello", or the entire string

