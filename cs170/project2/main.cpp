/* Course: CS 170 fall quarter , 2012
 First Name: Christopher
 Last Name: Wong
 Login id: wongc
 email address: cwong030@student.ucr.edu
 Student id: 860 923 521

 Assignment: Programming  Project 2

 I hereby certify that the code in this file
 is ENTIRELY my own original work.
========================================================================
*/
//main.cpp

#include "node.H"
#include <fstream>
#include <math.h>

//Global Varibles
vector<Object> dataset; //Structure to hold data
Node solution; //Structure to hold the solution
int numf = 0; //Number of features
int numi = 0; //Number of instances

//Reads in the file,puts, all relevant data into the vector dataset.
//Param: filename, the name of the file which to read in & analyze
void read_file(string filename){

	  //open the file & check to see if its a valid file
	  string line; ifstream myfile; myfile.open(filename.c_str());
	  if(!myfile.is_open()){
		  cout <<"'"<<filename<< "' is not a valid file name. Exiting"<< endl;
		  exit(1);
	  }

	  //read the contents of the file
	  while ( myfile.good() ){
		getline (myfile,line);
		if(line == "") break;

		//for each line, do this
		double classnum = 0; vector<double> features;
		for(int i = 2; i < line.size(); i = i+16){

			//get the raw number
			double n=atof(line.substr(i,9).c_str())*pow(10,atof(line.substr(i+11,3).c_str()));

			//Get the class number, or Get the feature
			if(i == 2) classnum = n;
			else {features.push_back(n);}
		}

		//put the object into the dataset & increment number of instances
		Object o(classnum,features); dataset.push_back(o);
		numi++;
	  }

	  //Get the number of features
	  numf = dataset[0].feature.size();

    //Close the file
    myfile.close();
}

//Nearest Neighbor algorithim
//Parma: v, vector which holds all features of the unknown object,
//		 v2, vector that holds which features are active in the calculation
//Returns: The predicted outcome for this object
double nn(vector<double> v, vector<char> v2){

	//calculate ecluid distance from each instance
	double distance, lowest_class = -1, lowest = 0;
	for(int i = 0; i < dataset.size(); i++){
		double subtotal = 0;
		for(int j = 0; j < numf; j++)
			if(v2[j]==1)subtotal+= pow((v[j]-dataset[i].feature[j]),2);
		distance = sqrt(subtotal); 

		//Determine if its the lowest number encountered
		if( (lowest_class == -1 || distance < lowest) && distance != 0 ){
			lowest = distance; lowest_class = dataset[i].classnum;
		}
	}
	return lowest_class; //return which class is the closest neighbor
}

//Does a cross validation check with the given active feature vector
//Param: active, vector indicating which features are used ( 0 or 1)
//Returns: Precentage of nearest neighbors that were correct
double do_cross_validation(vector<char> active){
	//run through the dataset and determine if its a correct guess
	double num_correct = 0;
	for(int i = 0; i < numi; i++)
		if( nn(dataset[i].feature,active) == dataset[i].classnum) num_correct++;
	return (num_correct / (double)numi); //return % of correct answers
}

//Integer to binary function,from (http://www.cplusplus.com/forum/general/10898/)
//Param: n, a Integer needs to be convereted to binary
//Returns: Binary in form of a string represeted with '0' and '1''s
string dec2bin(unsigned long n ){
  string result;
  do result.push_back( '0' + (n & 1) );
  while (n >>= 1);
  reverse( result.begin(), result.end() );
  return result;
  }

//Runs the foward selection or backward elimination algorithm
//Param: type, denotes which search to run; 0 <- foward, 1 <- backward
//returns the solution to Node sol
void selection(int type = 0){
	vector<Node> tree;
	int total = 0; int activenum; int unactivenum;

	//Either run backward elimination or forward selection
	if(type == 0) {unactivenum = 0; activenum = 1;}
	else {unactivenum = 1; activenum = 0;}
	vector<char> active; for(int i = 0; i < numf; i++) active.push_back(unactivenum);

	while(true){
		tree.clear(); int pos = 0; int modified = 0;//clear temp tree and pos

		//For each feature, do
		for(int i = 0; i < numf; i++){
			if(active[i] == unactivenum){

				//activate a feature, do cross valid. check
				if(total != 0) active[i] = activenum ;
				double temp = do_cross_validation(active);
				tree.push_back(Node(temp,active));

				//output, check highest cross valid. results,deactive feature,
				cout << "    Using Feature(s)" << tree[tree.size()-1].string_activef()
				     << " accuracy is " << temp * 100<< "%" << endl;
				if(solution.cv < temp){solution.cv = temp; solution.active = active;}
				if(tree[i].cv >= tree[pos].cv) pos = i;
				active[i] = unactivenum; total++; modified++;
				if(total == 1) break;
			}
			else tree.push_back(Node());
		}

		if(modified == 0) break; //break out if needed

		//Get the features with the highest c.v check results
		active = tree[pos].active;
		cout << "Feature set" << tree[pos].string_activef()
			 <<" is best, accuracy is "<<tree[pos].cv *100<<"%"<<endl;
	}
}


//Runs my customly made algorithm
void suntinwong_algorithm(){
	vector<char> active; for(int i = 0; i < numf; i++) active.push_back(0);
	string s;
	
	//Go through a brute force search
	for(unsigned int i = 0; i < pow(2.0,numf); i++){
		for(int j = 0; j< numf; j++){

			//Convert integer to binary, set active features
			s = dec2bin(i);
			while(s.size() != numf)  s = "0" + s;
			if(s.substr(j,1) == "1") active[j] = 1;
			else active[j] = 0;
		}

		//Do cross validation check, output, set sol. if applicable
		double temp = do_cross_validation(active); Node node(temp,active);
		if(solution.cv < temp){solution.cv = temp; solution.active = active;}
		cout << "Feature set"<<node.string_activef() << " has an accuarcy of "
			 << temp * 100 << "%" << endl;

	}
}

//Main function: Run specific search using cross valid. to find relevant features
int main(){

	//Initialize and Read the user's file
	cout << "Welcome to SunTinWong's Feature Selection ALgorithm\n"
		 << "Type in the name of the file to test: " << endl;
	string filename; cin >> filename;
	read_file(filename);

	//Determine which algorithm to run
	cout << "Type the number of the algorithm you want to run\n"
	     << "1)Foward Selection\n2)Backward Elimination\n3)SunTinWong's Algorithm"
	     << endl;
	int input; cin >> input;

	//output number of features and number of instances
	cout <<"This dataset has "<<numf<<" feature(s)(not including class attrib),with "
	     << numi << " instance(s)" << endl;

	//do the calculation
	cout << "\nBeginning search.\n" << endl;
	if(input == 1) selection(0);
	else if(input == 2) selection(1);
	else if(input == 3) suntinwong_algorithm();
	else return 0;

	//output the results
	cout << "\nFinished search!! The best feature subset is "
		 << solution.string_activef() << ", which has an accuracy of "
		 << solution.cv * 100 << "%" << endl << endl;
}
