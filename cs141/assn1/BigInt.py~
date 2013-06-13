"""
CS 141 Project 1

Your Name: ChrisTopher Wong
Your Student ID: 860 923 521
Version 1.0
"""

#_____START OF BIGINT CLASSS_______

class BigInt:

    #FUNCTION: init
    #parameters: x -> must be integer
    #Constructor::constructs a new BigInt objects for integer x
    def __init__(self, x=0):
	self.integer = x

    #function: str
    #paramters: none
    #Acessor:: returns the string representation of a BigInt number
    def __str__(self):
        return str(self.integer)

    #FUNCTION: cmp
    #paramters: other -> must be integer or bigint (cannot be string)
    #Acessor::returns a negative integer if self < other, zero if self ==
              #other, a positive integer if self > other
    def __cmp__(self, other):
	if self.integer < int(other): 	 #check if self < other, returns -1
		return -1
	elif self.integer == int(other): 	 #check if self == other, returns 0
		return 0
	else:				 #else, return 1
		return 1

    #FUNCTION: add
    #paramters: other -> must be integer or bigint (cannot be string)
    #Acessor, returns the sum of self and other; returns (self + other)
    def __add__(self, other):
	s1 = str(self.integer) 	#make first int into char array
	s2 = str(other)		#make second int into char array
	s3 = ""
	s3_reverse = ""
	i = 1			#counter increment
	j = -1			#counter for back pointer
	c = 0
	while i <= len(s1) or i <= len(s2):	#MAIN addition loop
		if i > len(s1):			#if s2 has more digits then s1
			temp_sum = int(s2[j]) + c
		elif i > len(s2):		#if s1 has more digits then s2
			temp_sum = int(s1[j]) + c
		else:				#if s1 has same digits as s2
			temp_sum = int(s1[j]) + int(s2[j]) + c
		c = 0				
		if temp_sum > 9:		#compensate for carry over
			c = 1
			temp_sum = temp_sum %10
		s3 +=  str(temp_sum)		#add subtotal
		i = i +1			#increment total count
		j = j -1			#increment backward count
	if c == 1:				#compensate for last carry
		s3 += "1"
	j = -1					#return reverse of the string
	for k in range(0,len(s3)):
		s3_reverse += s3[j]
		j = j -1
        return BigInt(s3_reverse)
	
    #Function: mul
    #paramters: other -> must be int or bigint (cannot be string)
    #Acessor,returns the product of self and other; ex, returns (other * self)
    def __mul__(self, other):
	if self.integer < other:		#if self < other
		s1 = str(self.integer)
		s2 = str(other)
	else:					#else, self > other
		s1 = str(other)
		s2 = str(self.integer)
	s3 = BigInt(0)
	cnt1 = 0				#0 pading counter
	cnt2 = -1				#Rear pointer
	for i in range(0,len(s1)):
		s3_subtotal = BigInt(0)		#create a subtotal
		for j in range(0,int(s1[cnt2])):
			s3_subtotal += BigInt(s2)
		for k in range(0,cnt1):
			s3_subtotal += BigInt(str(s3_subtotal) + "0")
		cnt1 += 1			#increment padding counter
		cnt2 -= 1			#decrement rear pointer
		s3 += s3_subtotal		#add subtotal to total
	return s3
 
#____END OF BIGINT CLASS___

#Factorial function (commented out); can also be used for testing purposes
"""
def fact(n):
    if n == 0:
        return 1
    else:
        return n*fact(n-1)

if __name__ == '__main__':
    import sys
    if len(sys.argv) < 2:
        sys.exit('Usage: %s <number>' % sys.argv[0])
    prod = BigInt(1)
    k = int(sys.argv[1])
    for i in range(k):
        prod = prod * BigInt(i+1)
        print prod, fact(i+1)
"""

#MAIN TEST HARNESS
#Here I will prove that my algoritum works with various test cases
print "\n===================================="
print "Chris Wong's BigInt python class"
print "===================================="
print "Lets do some BigInt adding!"
print "TEST#1: 1+1 =", BigInt(1) + BigInt(1)
print "TEST#2: 5+8 =", BigInt(5) + BigInt(8)
print "TEST#3: 10+5 =", BigInt(10) + BigInt(5)
print "TEST#4: 13+9 =", BigInt(13) + BigInt(9)
print "TEST#5: 14+18 =", BigInt(14) + BigInt(18)
print "TEST#6: 184+1337 =", BigInt(184) + BigInt(1337)
print "TEST#7: 999999+1 =", BigInt(999999) + BigInt(1)
print "TEST#8: 999999+888888 =", BigInt(999999) + BigInt(888888)
print "TEST#9: 282588175+9178589 =", BigInt(582588175) + BigInt(9178589)
print "TEST#10: 100+0 =", BigInt(100) + BigInt(0)

print"\nNow lets try some BigInt multiplying!"
print "TEST#11: 1*1 =", BigInt(1) * BigInt(1)
print "TEST#12: 5*8 =", BigInt(5) * BigInt(8)
print "TEST#13: 10*5 =", BigInt(10) * BigInt(5)
print "TEST#14: 13*9 =", BigInt(13) * BigInt(9)
print "TEST#15: 14*18 =", BigInt(14) * BigInt(18)
print "TEST#16: 184*1337 =", BigInt(184) * BigInt(1337)
print "TEST#17: 999999*1 =", BigInt(999999) * BigInt(1)
print "TEST#18: 999999*888888 =", BigInt(999999) * BigInt(888888)
print "TEST#19: 282588175*9178589 =", BigInt(582588175) * BigInt(9178589)
print "TEST#20: 100*0 =", BigInt(100) * BigInt(0)


