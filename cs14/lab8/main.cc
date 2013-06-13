/*
 * cs014_10su1 lab 8
 * main.cc
 */

#include "Graph.H"

int main(int argc, char* argv[]) {

    if(argc != 2) {
      cerr << "Usage error: expected <executable> <input>" << endl;
      exit(1);
    }
    
    //ifstream ifs(argv[1]);

    //if(!ifs) {
     // cerr << "Input file not found." << endl;
      //exit(1);
   // }

    Graph g(argv[1]);

    //ifs.close();

    g.bfs();

    g.output_graph();

    cout << "The End." << endl;

    return 0;
}
