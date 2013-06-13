///////////////////////////////////////////////////
//Names: Hans Wun, Chris Wong
//Login: wunh, wongc
//Email: hwun001@ucr.edu, wongc@cs.ucr.edu
//Lab Section: 0##
//Assignment: Lab #3
//I acknowledge all content is original.
////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<string> data,text;


/**
* Converts integer to its binary equivlent
* Parameters: int n, int size, bool sign_flag
*       num <- integer that we are giong to convert
*       size <- total number of bits to convert to
*       sign_flag <-'false'(defualt) binary will be unsigned, 'true' -> signed
* Returns: string containing 'binary' equivlanet
* Purpose: To print the binary equivalent of the given integer
*/
string to_bin(const int &num,const int &size, const bool &sign_flag = false){

    //declare variables
    int n = num, temp1, s_size_temp;
    string s, s_reverse;
    bool neg_flag = false;

    //check correct input
    if(n < 0 ) assert(sign_flag); //output error when neg and unsigned

    //check to see if its a negative number when signed binary
    if(sign_flag && n < 0){
        neg_flag = true;
        n = (n * -1) - 1; //convert negative when necessary to pos
    }

    //push in 1 or 0 when appropriate
    while( n != 0 ){
        temp1 = n % 2;
        if( temp1 == 1 && !neg_flag) s += "1";
        else if (temp1 == 0 && !neg_flag) s +="0";
        else if (temp1 == 1 && neg_flag) s +="0";
        else if (temp1 == 0 && neg_flag) s +="1";
        else assert(true);  //kill program if something weird happens
        n /= 2;
    }

    //check for overflow
    s_size_temp = size - s.size();
    if(!sign_flag) assert(s_size_temp >= 0);
    else assert(s_size_temp > 0);

    //pad with 1's or 0's
    for(int i = 0; i < s_size_temp; i++){
        if(!neg_flag) s += "0";
        else s += "1";
    }

    //reverse string output to s_reverse
    for(int i = (s.size() -1); i >= 0; i--) s_reverse += s.substr(i,1);

    //if signed, set first bit to it's appropratie flag
    if(sign_flag && !neg_flag) s.substr(0,1) == "0";
    else if(sign_flag && neg_flag) s.substr(0,1) == "1";

    //return solution
    return s_reverse;
}

//parameter: ex v0 v1 v2
string find_reg(const string &s)
{
    string temp;
    for(int i  = 0; i < data.size();i++){
        if(data[i].substr(0,data[i].find(":")) == s.substr(0,s.find(":"))){

            temp = data[i].substr(data[i].find("d")+1);
            while(temp.substr(0,1) != " ") temp = temp.substr(1);
            return to_bin(atoi(temp.c_str()),16,true);
        }
    }

}


//======================================
// Assembler specific helper functions
//======================================
/**
* Converts the getline'd string to a binary string
* Parameter: entire string line to convert
* Returns: the appropiate converted binary string
*/

string assem_add(const string &s){
    string s1 = "000000", s_temp;   //set the opcode, make the return string
    int temp;

    //set d
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string d = to_bin(temp,5,false);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string ss= to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.c_str());
    string t= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += d;
    s1 += "00000100000";
    return (s1);
}

string assem_addu(const string &s){

    string s1 = "000000", s_temp;   //set the opcode, make the return string
    int temp;

    //set d
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string d = to_bin(temp,5,false);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string ss= to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.c_str());
    string t= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += d;
    s1 += "00000100001";
    return (s1);
}

string assem_sub(const string &s){

    string s1 = "000000", s_temp;   //set the opcode, make the return string
    int temp;

    //set d
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string d = to_bin(temp,5,false);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string ss= to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.c_str());
    string t= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += d;
    s1 += "00000100010";
    return (s1);
}

string assem_subu(const string &s){

    string s1 = "000000", s_temp;   //set the opcode, make the return string
    int temp;

    //set d
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string d = to_bin(temp,5,false);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string ss= to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.c_str());
    string t= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += d;
    s1 += "00000100011";
    return ( s1);
}

string assem_and(const string &s){

    string s1 = "000000", s_temp;   //set the opcode, make the return string
    int temp;

    //set d
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string d = to_bin(temp,5,false);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string ss= to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.c_str());
    string t= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += d;
    s1 += "00000100100";
    return ( s1);
}

string assem_or(const string &s){

    string s1 = "000000", s_temp;   //set the opcode, make the return string
    int temp;

    //set d
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string d = to_bin(temp,5,false);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string ss= to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.c_str());
    string t= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += d;
    s1 += "00000100101";
    return ( s1);
}

string assem_slt(const string &s){

    string s1 = "000000", s_temp;   //set the opcode, make the return string
    int temp;

    //set d
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string d = to_bin(temp,5,false);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string ss= to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.c_str());
    string t= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += d;
    s1 += "00000101010";
    return ( s1);
}

string assem_lw(const string &s){


    string s1 = "100011", s_temp;   //set the opcode, make the return string
    int temp;
    string offset;

    //set t
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string t = to_bin(temp,5,false);

    //set offset

    s_temp = s_temp.substr(s_temp.find(",")+1);
    temp = atoi(s_temp.substr(0,s_temp.find("(")).c_str());
    if(s.find("V") == -1) offset= to_bin(temp,16,true);
    else offset = find_reg(s_temp.substr(0,s_temp.find("(")));

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(")")).c_str());
    string ss= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += offset;

    return ( s1);
}

string assem_sw(const string &s){

   string s1 = "101011", s_temp;   //set the opcode, make the return string
    int temp;

    //set t
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string t = to_bin(temp,5,false);

    //set offset
    s_temp = s_temp.substr(s_temp.find(",")+1);
    temp = atoi(s_temp.substr(0,s_temp.find("(")).c_str());
    string offset= to_bin(temp,16,true);

    //set ss
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(")")).c_str());
    string ss= to_bin(temp,5,false);

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += offset;
    return ( s1);
}

string assem_beq(const string &s){

    string s1 = "000100", s_temp;   //set the opcode, make the return string
    int temp;

    //set s
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string ss = to_bin(temp,5,false);

    //set t
    s_temp = s_temp.substr(s_temp.find("$")+1);
    temp = atoi(s_temp.substr(0,s_temp.find(",")).c_str());
    string t= to_bin(temp,5,false);

    //set offsetname
    s_temp = s_temp.substr(s_temp.find(","));
    string offset= s_temp;

    //push everything back
    s1 += ss;
    s1 += t;
    s1 += offset;
    return ( s1);
}

string assem_j(const string &s){

    string s1 = "000010,", s_temp;   //set the opcode, make the return string
    int temp;

    //set offsetname
    s_temp = s.substr(s.find(" ")+1);
    string offset= s_temp;

    //push everything back
    s1 += offset;
    return (s1);
}

string assem_word(const string &s){

    string s1 = "", s_temp;   //set the opcode, make the return string
    int temp;

    //set offsetname
    s_temp = s.substr(s.find(":")+1);
    s_temp = s_temp.substr(s_temp.find("d")+1);
    while(s_temp.substr(0,1) == " ") s_temp = s_temp.substr(1);
    temp = atoi((s_temp.c_str()));

    //push everything back
    s1 += to_bin(temp,32,false);
    return ( s1);
}

string assem_dbnz(const string &s){


    string s1 ="000110", s_temp, offset;
    int temp;

    //set s
    s_temp = s.substr(s.find("$")+1);
    temp = atoi((s_temp.substr(0,s_temp.find(","))).c_str());
    string ss = to_bin(temp,5,false);

    offset = s_temp.substr(s_temp.find(","));

    s1 += ss;
    s1 += offset;
    return s1;

}

string assem_label(const string&s){

    return  "label:" + s;

}




/**
* Main function
* Parameter: name of mip's file
* Purpose: Acts as an assembler by assembling the argumennt's mip's code.
*/
int main(int argc, char** argv){

    //=======CHECK FILE PHASE ========
    //Check for correct user input
    if(argc != 2){
        cerr << "INCORRECT Usage: " << argv[0] << " <mips_file.s>" <<
             " \nexiting program" << endl;
        exit(1);
    }

    //open file for reading, check to make sure file can be opened
    ifstream infile(argv[1]);
    if(!infile){
        cerr << "Can't open input file '" << argv[1] <<"'" << endl;
        exit(1);
    }

    //======READING PHASE =======
    string line;
    bool text_readin = false, data_readin = false;
    const string blankline = "00000000000000000000000000000000";

    //Reading logic loop: getline of file, read it, find command and push
    getline(infile,line);    //get the first line
    while(!infile.eof()){

    //figure out which mode to read
        if(line.substr(0,5) == ".data") {
            data_readin = true;
            getline(infile,line);
        }
        else if(line.substr(0,5) == ".text") {
            text_readin = true;
            data_readin = false;
            getline(infile,line);
        }

        //read the 'data' portion
        if(data_readin){
            if(line.size() != 0)data.push_back(line);
           // else data.push_back(blankline);
        }

        //read the 'text' portion
        else if(text_readin){

            if(line.size() != 0){

                //cut off whitespace for line
                while(line.substr(0,1) == " ")line = line.substr(1);

                //figure out which function to call
                if(line.substr(0,line.find(" ")) == "add")
                    text.push_back(assem_add(line));
                else if(line.substr(0,line.find(" ")) == "addu")
                    text.push_back(assem_addu(line));
                else if(line.substr(0,line.find(" ")) == "sub")
                    text.push_back(assem_sub(line));
                else if(line.substr(0,line.find(" ")) == "subu")
                    text.push_back(assem_subu(line));
                else if(line.substr(0,line.find(" ")) == "and")
                    text.push_back(assem_and(line));
                else if(line.substr(0,line.find(" ")) == "or")
                    text.push_back(assem_or(line));
                else if(line.substr(0,line.find(" ")) == "slt")
                    text.push_back(assem_slt(line));
                else if(line.substr(0,line.find(" ")) == "lw")
                    text.push_back(assem_lw(line));
                else if(line.substr(0,line.find(" ")) == "sw")
                    text.push_back(assem_sw(line));
                else if(line.substr(0,line.find(" ")) == "beq")
                    text.push_back(assem_beq(line));
                else if(line.substr(0,line.find(" ")) == "j")
                    text.push_back(assem_j(line));
                else if(line.substr(0,line.find(" ")) == "dbnz")
                    text.push_back(assem_dbnz(line));
                else if(line.substr(0,line.find(" ")) != "")
                    text.push_back(assem_label(line));
                else cerr << "something went horribly wrong" << endl;
            }
            else data.push_back(blankline);
        }

        // read the next line
        getline(infile,line);
    }

    //=====SECOND PASS FOR READING
    int count = 0;
    for(int i = 0; i < text.size(); i++){
        if(text[i].substr(0,6) == "000100" || text[i].substr(0,6) == "000010"||
           text[i].substr(0,6) == "000110"){

            int s_offset = 0;

            string s_label = text[i].substr(text[i].find(",")+1);

            for(int j = 0; j < text.size(); j++){
                if(text[j].substr(6,text[j].size()- 7) == s_label){ //its found
                    s_offset = j-i - count + 1;

                    if(text[i].substr(0,6) == "000100") //if beq
                        text[i] = text[i].substr(0,16)
                        + to_bin(s_offset,16,true);
                    else if(text[i].substr(0,6) == "000010") // ifjump
                        text[i] = text[i].substr(0,6)
                        + to_bin(s_offset,26,true);
                    else if(text[i].substr(0,6) == "000110")//if dbnz
                        text[i] = text[i].substr(0,11)
                        + "00000" + to_bin(s_offset,16,true);
                    break;
                }

                else if(text[j].substr(0,6) == "label:" && text[j] != s_label)
                    count++;
            }
        }
    }

for(int i = 0; i < text.size(); i++){
    if(text[i].substr(0,6) == "label:"){
        text.erase(text.begin() + i);
         i--;
    }

}


    for(int i = 0; i < data.size(); i++) data[i] = assem_word(data[i]);


    //======WRITING PHASE =====
    ofstream outfile("init.coe");
    outfile << "memory_initialization_radix = 2;" << endl;
    outfile << "memory_initialization_vector =";

    //Write to the file
    for(int i = 0; i < text.size(); i++) outfile << endl << text[i];
    for(int i = text.size(); i < 127; i++)outfile << endl << blankline;
    for(int i = 1; i < data.size(); i++) outfile << endl << data[i];
    for(int i = data.size(); i < 130; i++) outfile << endl << blankline;
    outfile << ";"; // output final semicolon


    //close files, exit program
    outfile.close();
    infile.close();
    cout << "=====Program Complete====" << endl;
    return 0;
}
