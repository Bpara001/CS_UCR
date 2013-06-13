/* Course: CS 165 fall quarter , 2012

 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  assn 1

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
*/
//main.cpp


//load libraries
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Find the determinate of a 2x2 matrix
long long det(long long a,long long b,long long c,long long d)
{
    return ( (a*d) - (c*b));
}


//Generate the key using LCG method
unsigned short int generate_key(int a, int b, int n, int r0){
	
	return (unsigned short int)((r0*a + b)% n);
	
}


int main(){

	//!===================================================
	//!Phase 1: read the file as pairs of 16bit numbers (get cipher text)
	//!===================================================

    vector<unsigned short int> v;
	unsigned char in;
	ifstream myfile("problem2.enc");

	while(myfile.good()){
	    in = myfile.get();
        unsigned char temp = in;
	    in = myfile.get();
	    v.push_back( ((unsigned short int)(temp) << 8) | (unsigned short int)(in));
	    //cout << v[v.size()-1] << endl;
	}
	

    //!===================================================
	//!Phase 2: get the key
	//!===================================================


    /*GETTING THE LCG VALUES:
    Used this website: http://sandeepmore.com/blog/tag/breaking-lcg/
    Used wolfram to calculate gcd; showing work here,

    getting r values -> ciphertext XOR plaintext
    
    ciphertext #1: 59417
    ciphertext #2: 57937
    ciphertext #3: 45548
    ciphertext #4: 61158
    ciphertext #5: 43711

	(from %!-Adobe)
    plaintext #1:9505
	plaintext #2:20563
	plaintext #3:11585
	plaintext #4:25711
	plaintext #5:25189

	output = ciphertext XOR plaintext

    let d(i,j) =  |output(i)-output(1)    output(i+1)-output(2) |
                  | output (j)-output(1)  output(j+1)-output(2) |

    thus,
    d(2,3) = 2 527 583
    d(3,4) = 245 175 551

    next, gcd ( d(2,3),d(3,4)) -> 58781 = n 
    solving a & b
    
    r1 = (r0*a + b)mod n
    r0 = 52536, r1 = 45570, r3 = 40109
    
    45570 = (52536*a + b) mod 58781
    40109 = (45570*a + b) mod 58781
    two equations, two unknown's
    -> a = 313, b= 1701
   
    */

	/*

    long long out1= 52536;
    long long out2= 45570;
    long long out3= 40109;
    long long out4= 35465;
    long long out5= 51418;

    cout << det(out2 - out1, out3 - out2, out3-out1,out4-out2) << endl; //d(2,3)
    cout << det(out3 - out1, out4 - out2, out4-out1,out5-out2) << endl; //d(3,4)
	*/
	
	
	//!===================================================
	//!Phase 3: plaintext = ciphertext XOR key
	//!===================================================
	
	//Genearte the key values for every 2byte area
	int a = 313;
	int b = 1701;
	int n = 58781;
	vector<unsigned short int> keys;
	keys.push_back((unsigned short int)(52536));  //push initial value
	for(int i = 1; i < v.size(); i++) keys.push_back(generate_key(a,b,n,keys[i-1]));
	
	//Xor -> do this 8 bits at a time, ciphertext and keys
	for(int i = 0; i< v.size(); i++)  {
		
		unsigned short int temp = (v[i] ^=  keys[i]);
		unsigned short int mask1 = 0xFF00;
		unsigned short int mask2 = 0x00FF;
		cout << (unsigned char)((temp & mask1) >> 8); //output the first byte
		cout << (unsigned char)((temp & mask2)); //output the second byte
	}
	
	
	
	return 0;
}
