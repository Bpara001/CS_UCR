//=================================================
//
// Name: wong, christopher
// Login id: wongc
// Email: cwong030@student.ucr.edu
//
// Assignment name: proj6
// Lab section: 001
// TA: Chih-Hsun Chou
//
// I hereby certify that the contents of this file
// are ENTIRELY my own original work.
//
//=================================================


// =================== main.cc ======================================

//
// main.cc
//

// applied monitors and thread classes for testing
#include "ucrthreads.H"
#include <set>
#include <unistd.h>
#include <map>



//the myrand function, gives a ruandom number between 1- 99
inline int myrand(){
    static unsigned long next = 3;
    next = next * 1103515245 + 12345;
    unsigned x = (unsigned) (next/65536) % 32768;
    return x % 99;
}

//inline function for delaying
inline void mydelay(){dispatcher.wakeme_in(1);}

//declare various maps for the specific states: philosophizing, eating, waiting
map<int,int> p;
map<int,int> e;
map<int,int> w;

//declare more stuffs
class Philosopher;
class Chopstick;
vector<Philosopher*> phil;
vector<Chopstick*> chop;
Semaphore thestart;
void mydelay(int n) {usleep(n*1000);}
enum colors {green,yellow,red};


//Chopstick Class: Each chopsstick should be represented by a Monitor.
class Chopstick : public Monitor{

 public:
    colors color;               //has the attribute color
    Philosopher* left_client;         //has the attribute of the left client
    Philosopher* right_client;        //has the attribute of the right client
    Philosopher* current_owner;       //has the attribute of the current owner

    bool hold;
    bool in_transit;

    //defualt constructor
    Chopstick()
    :hold(false){
    }

    //constructor with parameters
    Chopstick(colors c)
    :color(c),hold(false){}

    bool is_in_transit(){
        EXCLUSION;
        return in_transit;

    }

    void release(){



        in_transit = true;
        hold = false;
    }

    void aquire(){



        in_transit = false;
        hold = true;
    }

};

map<string,Chopstick> stick;

//Philosopher Class: Each philosopher should be represented by a Thread
class Philosopher : public Thread{

public:
    string state;    //has the attribute of current state, either "P","W", or "E"
    Chopstick *leftstick;           //has the attribute of left chopstick
    Chopstick *rightstick;          //has the attribute of right chopstick

    int id;
    int n;

    //defualt constructor
    Philosopher(int id2, int n2)
    :Thread("Phil#"+ T2a(id2)),id(id2),n(n2) {}

    void action(){
        thestart.acquire();
        thestart.release();

        //initialize left and rightstick
        for(int i = 0; i != 120; ++i){
            state = "P";
            mydelay(myrand());  //philosophizing
            //identify chopsticks by color

            //acquire chopsticks peer protected
            stick["red"].aquire(); //need to add some stuff here?
            stick["green"].aquire(); //need to add more stuff here

            if(leftstick->hold || rightstick->hold) state = "W";

            else{
                leftstick->aquire(); rightstick->aquire();
                state = "E";
                mydelay(myrand()); // eating
                leftstick->release(); rightstick->release();
            }
        }
    }

    ~Philosopher(){}

};

//create the resource-allocatoin graph
ThreadSafeMap<Thread*, ThreadSafeMap<Chopstick*,string> > alloc;

void ReportEverythingForMe(int n)
{
    for(int i = 0; i != n; ++i){
        map<colors,string> colorcode;
        colorcode[red] = "red";
        colorcode[green] = "green";
        colorcode[yellow] = "yellow";
        cout << "       " << colorcode[chop[i]->color] << endl;
        string s = alloc[phil[i]][chop[i]];
        cout << (s == "awaited"  ? "        ^\n         /\n":
                 s == "acquired" ? "        ^/\n        V\n":
                                "\n\n");
        s = alloc[phil[i]][chop[(i+1)%n]];
        int sum = p[i] + w[i] + e[i];
        cout << phil[i]->name << " P:" << p[i]*100/sum << "% W:"<< w[i]*100/sum << "% E:"<< e[i]*100/sum <<"%\n"
             <<(s == "acquired" ? "        ^\n         /\n":
                s == "awaited" ? "        \\ \n        V\n":
                        "\n\n");
    }
    cout << "=================================================\n";
}



int main(int argc, char ** argv)
{

    //Check for correct input
	if(argc != 2){
		cerr<<"\nError:<executable> <#num of philosophers>\nex: a.out dict1.txt"<<endl;
		exit(1);
	}

    //make philosphers and chopsticks
	for(int i = 0; i < atoi(argv[1]); i++){
        phil.push_back(new Philosopher(i,0));
        chop.push_back(new Chopstick());
	}

    //figure out if there are even or odd number
	bool evenNum = false;
	if(atoi(argv[1]) % 2 == 0) evenNum = true;

	//assign left and right chopsticks to the philosphers, also assign chopstick colors
	for(int i = 0; i< atoi(argv[1]); i++){

        //assign the chopsticks current owner, right and left
        if(i != 0 && i != atoi(argv[1]) -1 ){
            chop[i]->current_owner = phil[i];
            chop[i]->right_client = phil[i+1];
            chop[i]->left_client = phil[i-1];
        }
        else if(i == 0){
            chop[i]->current_owner = phil[0];
            chop[i]->right_client = phil[i+1];
            chop[i]->left_client = phil[atoi(argv[1]) -1];
        }
        else if(i == atoi(argv[1]-1)){
            chop[i]->current_owner = phil[i];
            chop[i]->right_client = phil[0];
            chop[i]->left_client = phil[i -1];
        }

        //assign the chopstick colors
        if(evenNum){
            if(i%2 == 0) chop[i]->color = green;
            else chop[i]->color = yellow;
        }

        else{
            if(i%3 == 0) chop[i]->color = green;
            else if(i%3 == 1)  chop[i]->color = yellow;
            else chop[i]->color = red;
        }
	}

	ReportEverythingForMe(atoi(argv[1]));



    //return 0;
}
