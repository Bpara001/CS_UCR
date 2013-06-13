//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: assn2
// class: cs141
//
// I hereby certify that the contents of this file
// re ENTIRELY my own original work.
//
//=================================================
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

////////////////////////////////////////////////
/////////////////Square CLASS///////////////////
////////////////////////////////////////////////
class Square
{
private:

    vector<int> v;   //used to hold the F's and R's
    vector<int> v2;  //used to hold locations of max values
    vector<int> v3;  //used to hold value of second
    int height;         //height of rectangle
    unsigned int width;          //width of rectangle
    int max_length;     //hold the max length
    int second_max_length; //hold the second to max length


//HELPER FUNCTION: FIND MIN:
//finds the min int of the 3 values and returns it
    int find_min(int a, int b, int c){
        if(a <= b && a <= c) return a;
        else if(b <= a && b <= c ) return b;
        else return c;
    }

public:

//DEFUALT CONSTRUCTOR
    Square()
    :height(0),width(0)
    {}

//CONSTRUCTOR with 2 parameters
    Square(int a, int b)
    :height(b),width(a)
    {}

//ADD member function:
//adds string 'c' to the square object (vector v)
    void add(string c){
        if(c == "F") v.push_back(1);
        else if(c == "R") v.push_back(0);
    }

    void add(int i){
        if(i > 0) v.push_back(1);
        else v.push_back(0);
    }

//ACCESOR function
//prints the contents of V with apporpiate newline characters
    void print_all(){
        for(unsigned int i = 1; i <= v.size(); i++){
            cout << "'"<<v[i-1]<<"'";
            if(i % width == 0)
                cout << endl;
        }
    }

//Member function:
//Does dynamic programming for finding the largest square
//determines the length of the square for the lowest left corner
//modifies the values inside the vecotr
    void do_logic(){
        for(unsigned int i = 0; i < v.size(); i++){
            if(i > width){
                if (v[i] == 0) v[i] = 0;
                else v[i] += find_min(v[i -1],v[i-width],v[i-width-1]);
            }
        }
    }

//ACCESSOR & Memberfunction:
//sets the max length variable
//Returns the value of largest length inside the vector
//SHOULD ONLY USE AFTER do_logic
    int find_max(){
        int max = v[0];
        for(unsigned int i = 0;i < v.size();i++){
            if(v[i] > max)
                max = v[i];
        }
        max_length = max;
        return max;
    }

//Member function:
//Finds the location of all squares that have the highest length
//SHOULD ONLY USE after find_max
    void find_locations()
    {
        for(unsigned int i = 0; i < v.size(); i++)
        {
            if(v[i] == max_length)
                v2.push_back(i);
        }
    }

//Member function:
//deletes specifc square starting at value p, with height of num
//sets all the corrosponding points to 0
    void delete_value(int p,int num)
    {
        v[p] = 0;
        if(num == 1) return;
        else{
            v[p-1] = 0;
            v[p-width] = 0;
            v[p-width - 1] = 0;
            delete_value(p-1,num-1);
            delete_value(p-width,num-1);
            delete_value(p-width-1,num-1);
        }
    }

//Member function:
//finds the second largest value of the square
//SHOULD ONLY use after find_locations
//sets second largets variable to apporpiate value
    void find_second_largest()
    {
        //special case #1
        if(max_length == 0) second_max_length = 0;

        //special case #2
        else if(max_length == 1 && v2.size() > 1) second_max_length = 1;

        //REGULAR CASE
        else{
            for(int unsigned i = 0; i < v2.size(); i++){
                Square s(width,height); //create another square
                for(int unsigned j = 0; j < v.size(); j++)
                    s.add(v[j]);
                s.delete_value(v2[i],max_length);   //delete one of
                s.do_logic();                       //largest squares
                v3.push_back(s.find_max());         //recalcuate the max
            }                              //shove 2nd max value into vector

            second_max_length = v3[0];     //finds the 2nd max value
            for(unsigned int i = 0; i < v3.size(); i++)
                if(v3[i] > second_max_length) second_max_length = v3[i];
        }
    }

//Prints the solution to the console
//SHOULD ONLY USE AFTER find_second_largest()
    void print_solution()
    {
        cout << (max_length * max_length) << " "
        << (second_max_length * second_max_length) << endl;
    }

//Returns the max area
    int get_max_area()
    {
        return max_length * max_length;
    }

//Returns the second largest area
    int get_second_max_area()
    {
        return second_max_length * second_max_length;
    }

};


///////////////////////////////////////////////////////////
/////////////////////// MAIN FUNCTION /////////////////////
///////////////////////////////////////////////////////////

//MAIN function -> TEST HARNESS
int main(int argc, char ** argv)
{
//Check for correct input
	if(argc != 3){
		cerr<<"\nError: <executable> <filename> <filename>" << endl;
		exit(1);
	}

//Open infile and outfile, create f and o stream objects
    ifstream infile;
    ofstream outfile;
    infile.open(argv[1]);
    outfile.open(argv[2]);

//Check for vaild files
    if(infile.fail()){
        cerr << "Error: Could not open \"" <<argv[1] << "\"" << endl;
        exit(1);
    }
    if(outfile.fail()){
        cerr << "Error: Could not create \"" <<argv[2] << "\"" << endl;
        exit(1);
    }

//get total num of squares
    string in;
    getline(infile,in);
    int total_num_squares = atoi(in.c_str());
    int count  = 0;

    //DO THIS FOR ALL MATRIXES
    while(count < total_num_squares){

    //Get height and width of the square
        getline(infile,in);
        if(in == "") exit(1);
        int h =  atoi((in.substr(0,in.find(" "))).c_str());
        int w =  atoi((in.substr(in.find(" "))).c_str());
        Square s = Square(w,h);

    //Populate square object
        for(int i = 1; i <= (h*w); i++){
            infile >> in;
            s.add(in);
        }
        s.do_logic(); //do dynamic programming to find largest square
        s.find_max(); //find the largest length
        s.find_locations(); //find location of multiple largest lengths
        s.find_second_largest(); //find the second largest length
        s.print_solution(); //print solution to console
        outfile << s.get_max_area() << " " << s.get_second_max_area() << endl;
        count++; //write to output file and increment counter
        getline(infile,in); //move infile pointer
        getline(infile,in); //move infile pointer
    }

//Close infile and outfile
    infile.close();
    outfile.close();
    cout << "\n***Program sucessflly terminated***\n" << endl;
}
