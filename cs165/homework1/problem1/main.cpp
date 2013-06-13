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


//load libraires and use namespace std
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//uppercase array for sub
 const string UPPERCASE[27] = {"A", "B", "C","D","E","F","G","H","I","J","K","L","M",
    "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," "};

//lowercase array for sub
 const string LOWERCASE[27] = {"a", "b", "c","d","e","f","g","h","i","j","k","l","m",
    "n","o","p","q","r","s","t","u","v","w","x","y","z"," "};


//Get the char and return the int value
int frequency_counter(string s){
    for(int i = 0; i < 27; i++) if( s == UPPERCASE[i] || s == LOWERCASE[i]) return i;
    return 27;
}


//Output the analysis of the letter frequency
void output_frequency(int total, int f[]){

    string table[27] = {"A", "B", "C","D","E","F","G","H","I","J","K","L","M",
    "N","O","P","Q","R","S","T","U","V","W","X","Y","Z","SPACE"};

    for(int i = 0; i < 27; i++)
        cout  << table[i] << ": " << ((double)f[i]/total) *100 << "%  ," << f[i] << "/" << total << endl;
}


//Main function
int main(){

    //!=======================================================
    //!Phase 1: get the frequency of each letter
    //!=======================================================
    /*
    int frequency[28] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    ifstream myfile ("problem1.enc");
    //ifstream myfile ("problem1.enc-plaintext.txt");
    string line;

    while(myfile.good()){
        getline(myfile,line);
        for(int i = 0; i < line.size(); i++) frequency[frequency_counter(line.substr(i,1))] += 1;

    }

    int totalsize = 0;
    for(int i = 0; i < 26; i++) totalsize += frequency[i];
    output_frequency(totalsize,frequency);
    */


    //!========================================================
    //!Phase 2: Create decoded E1 file
    //!========================================================
    /*
      
    
    //USING EXCEL:
    //Sorted the characters of "problem1.enc" and mapped each letter frequency
    //Then sorted the characts of plaintext.txt and mapped each letter frequency
    //Matched the frequencies to the sepearte letters
    //Please see the excel spreadsheet, "frequency analysis", for further work
    
    //Using the results, compare & sort w/ excel, and map
    const string decoded[27] = {"U","G","R","X","Y","P","F","Q","H","A",
    "O","B","K","S","J","I","N","T","E","L","W","D","M","C","V"," ", "Z"};

    ifstream myfile("problem1.enc");
    ofstream decode("decoded.txt");
    string line;
    string temp;

    while(myfile.good()){
        getline(myfile,line);
        for(int i = 0; i < line.size(); i++){
            temp = line.substr(i,1);
            if(frequency_counter(temp) != 27) { decode << decoded[frequency_counter(temp)];}
            else decode << temp;
        }
        decode << endl;
    }

    myfile.close();
    decode.close();
    */


    //!========================================================
    //!Phase 3: Using a certain n,m, output solution
    //!========================================================
	
	/*
	 Number of characters: 858474
	 Factors:1, 2, 3, 6, 9, 18, 37, 74, 111, 222, 333, 666, 1289, 2578,
	 3867, 7734, 11601, 23202, 47693, 95386, 143079, 286158, 429237, 
	 858474
	*/
	
    //factored possiblities n & m's try every single combination till 
    //you get readable text
    //these values of n&m gives me readable text,
    int n = 666;
    int m = 1289;

    //shove contents of decoded.txt into a 1d array
    vector<string> v;
    string s;
    ifstream nm("decoded.txt");
    getline(nm,s);
    s = s.substr(3);  //first 3 charactes are weird
    while(nm.good()){
            for(int i = 0; i < s.size(); i++) {v.push_back(s.substr(i,1));c++;}
            v.push_back("~");
            getline(nm,s);
        }
    nm.close();

    //Output to console
    for(int j = 0; j <= m; j++){
        for(int i = j; i < v.size(); i++){
            if( (i) % m == 0 + j){
                if(v[i] == "~") cout << "\n";
                else cout << v[i];
            }
        }
    }

    cout << "\n\n\n***********Program finished" << endl;

}
