/* Course: CS 170 fall quarter , 2012

 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  Project 1

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
*/
//main.cpp

//load libraries
#include "tree.H"
using namespace std;

//global constants
#define WIDTH 3 //Define the width size
const int defualt[9] = {4,1,5,6,3,2,7,8,0};


//function that outputs the puzzle according to the vector's contents
void output_puzzle(vector<int> v){

    //Output it to the console
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";

        //Output newline character when necessary
        if( (i+1) % WIDTH == 0 && i != 0) cout << endl;
    }
}

//function that handles the user input and checks valid input
//If input is not valid, return an empty vector
void get_user_input(vector<int> &v) {

    //Create objects & varibles
    int userinput; string input_defualt;
    bool repeat = false;
    bool zeroexists = false;


     //Prompt defualt input
    cout<< "Use defualt puzzle and search? (y/n)\n" << endl;
    cin >> input_defualt;

    //If custom user input
    if(input_defualt != "yes" && input_defualt != "y" && input_defualt != "YES" && input_defualt != "Yes"){

        //Output the introduction text
        cout << "Enter your puzzle, use a zero to represent the blank\n";

        //Get the user's inputs
        for(int i = 0; i < WIDTH; i++){
            cout << "Enter row #"<< i+1 << " use space or tabs between numbers: ";
            for(int j = 0; j < WIDTH; j++){
                cin >> userinput;
                v.push_back(userinput);
            }
        }

        output_puzzle(v); //output the contents of the puzzle to the user

        //Check for valid input
        for(int i = 0; i < v.size(); i++){
            if(v[i] == 0) zeroexists = true; //check if zero exist
            for(int j = 0; j < v.size(); j++){
                if(v[i] == v[j] && i != j) repeat = true; //check for repeated numbers
            }
        }

        //If invalid input, do this:
        if(repeat or !zeroexists) {
            cout << "You have entered an invalid puzzle" << endl;
            if(repeat) cout << "You have entered a number more than once." << endl;
            if(!zeroexists) cout << "You have not entered a zero." << endl;
            cout << "Please Re-Enter the puzzle!\n" << endl;
            v.clear();
        }
    }

    //If defualt puzzle
    else{
		
        v.clear();
		for(int i = 0; i < (WIDTH * WIDTH); i++) v.push_back(defualt[i]);

    }



}

//Get the search type from the user
//Returns the search type int, 1 or 2 or 3.
int get_search_type(){

    string input;
    while(input != "1" && input != "2" && input != "3"){
        cout << "\nEnter your choice of algorithm\n"
             << "   1. Uniform Cost Search\n"
             << "   2. A* with the Misplaced Title heuristic.\n"
             << "   3. A* with the Manhattan distance heuristic." << endl;
        cin >> input;
        if(input != "1" && input != "2" && input != "3") cout << "Invalid input" << endl;
    }

    if(input == "1") cout << "\n(1)Selected 'Uniform Cost Search'" << endl;
    if(input == "2") cout << "\n(2)Selected 'A* w/ Misplaced Title heur.'"<< endl;
    if(input == "3") cout << "\n(3)Selected 'A* w/ Manhattan distance heur.'" << endl;
    return atoi(input.c_str());

}


//Main function
int main(){

    //Output the introduction text
    cout << "=============================================\n"
         << "Welcome to SunTinWong's 8-puzzle solver!\n\n";

    //Create the container that will hold the initial state puzzle numbers
    vector<int> v;

    //Get the userinput and output it to the screen
    while(v.size() == 0) get_user_input(v);

    //Get the search type;
    int search_type = get_search_type();

    //Output a useful message
    cout << "\nGenerating Tree..." << endl;

    //Find and print the solution
    Tree t(v);
    t.general_search(search_type);

    //Output exiting program
    cout << "\n****Program complete. Exiiting.\n" << endl;

    return 0;

}




