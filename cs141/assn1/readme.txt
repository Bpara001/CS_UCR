Chris Wong
wongc
10/17/2011
860923521

FEATURES:
-A new integer class,"BigInt",
-Built in Multiplying operation 
-Built in Adding operation
-Built in comparison operation
-string return function

INCLUDES:
-the "BigInt" object class
-factorial function, (commented out; recomment to implement)
-Test harness (with 20 test cases testing the operations)
-All in one file!!

HOW TO USE:
-must have python
-to declare a BigInt object, simply declare it like any other class
MUST USE INT as paramter
	examples: x = BigInt(10)  #creates a BigInt object with value 10
 		  y = BigInt("10") #DO NOT declare like this!!!
-using overloaded operations
	examples: z = BigInt(1) + BigInt(5) #creates BigInt object with 1+5 -> 6
		  Print BigInt(591) + BigInt(22) #prints value of 613
		  z = z * BigInt(3) #multiplies z by 3


Readme.

For my Bigint class, I used a string data structure to hold my data. Using the built in + operator to only add single digit characters, i created a full adding function that uses grade-school logic. Next, with my completed adding function, i created a multiply function that again uses the grade-school logic. 

I choose to use the string to hold my data beacuse of the already built in functions for that class. I could eaisly call the size of the string using len(s), and pad zero's by adding the '0' character then converting it into a int/bigint.

All my problems that arose were because of syntax errors. I had trouble with loop implementation, and tabbing because i was not use to the language. I was able to fix all the errors (other wise it would nto complie)

This class supports the factorial program supplied by the professor, and can compute 500! in 10 seconds.

I have supplied a basic test harness to show my algoritum for adding and multiplying works successfully with various test cases that excersie carrying, zero padding, and speical cases such as multiplying by zero. 

I did not simply print the text aka, 
"print test#1: 1+1 = 2"(since thats cheating), 
instead i actaully added/multipled the BigInt objects, "print test#1: 1+1 = ", BigInt(1) + BigInt(1)"
