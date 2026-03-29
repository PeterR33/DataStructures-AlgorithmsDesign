/*                                                                             
Author: Peter Rooney                                                           
Date: 04/07/24                                                                 
Description:                                                                   
  This class test the Matrix graph. It creates a user interface where the user 
can creat graphs using files and find paths between vertices 
usage: 
<exe> {-u|-w} <file> [-ud]
*/
#include <iostream>
#include<stdlib.h>
#include<string>
#include <iomanip>
#include <vector>
#include<fstream>
#include"MatrixGraph_rooney.h"
#include <sstream>
#include <cstring>

using namespace std; 
void menu(); //method to print out graph 
void usage(); //if incorrect usage
MatrixGraph createGraphWeighted(string, bool); // method to create weighted graph
MatrixGraph createGraphUnWeighted(string, bool); //method to create unweighted graph 
int main (int argc, char* argv[]) 
{
  bool newFile = false;
  string newFileName = "";
  if(argc <2)
    {
      usage();
    }
  else if( argc == 4 && strcmp(argv[1],"-w")==0 && strcmp(argv[3],"-ud")== 0 ) //weighted and undirected
    {
      bool directed = false;
      string fileName  = argv[2];
      MatrixGraph graph = createGraphWeighted(fileName, directed);
      string input;
    do
      {
	menu();
	cin>>input;
	switch(input[0]) 
	  {
	  case '1':
	    cout<< graph.toString()<< endl;
            break;
	  case '2':
	    int v1,v2; 
	    cout << "From vertex: " <<endl;
	    cin >> v1;
	    cout << "find vertex: " <<endl;
	    cin >>v2;
	    graph.getBFSPath(v1, v2);
	    break;
	  case '3': 
	    int i1,i2;
	    cout<<"Integer 1:" <<endl;
	    cin >> i1;
	    cout<<"Integer 2:" <<endl;
	    cin>> i2;
	    graph.getDijkstraPath(i1,i2);
	    break;
	  case '4':
	    int start; 
	    cout<< "what index should we start from" << endl;
	    cin>>start;
	    //	    graph.getDijkstraAll(start);
	    cout<<"is there a seg fault" <<endl;
	    break;
	  case '5':
	    {
	      cout<< "Enter a file name"<<endl;
	      cin>> newFileName;
	      MatrixGraph newGraph= createGraphWeighted(newFileName, false);
	      newFile = true;
	      cout << newGraph.toString()<<endl;
	      break;
	    } 
	  case '6':
	    {
	      if(newFile == false)
		{
		  cout << "No file has been created yet." <<endl;
		}
	      else
		{
		  MatrixGraph newGraph= createGraphWeighted(newFileName, true);
		  int v1, v2; 
		  cout<<"From vertex: " <<endl;
		  cin >> v1;
		  cout <<"find vetex: "<< endl;
		  cin>>v2;
		  vector<int> bfsPath = newGraph.getBFSPath(v1,v2);
		  //String path = bfsPath.pritnBFSString(
		}
	      break;
	    }
	  case '9':
	    graph.printRaw();
	    break;
	  case '0':                 
	    break;
	  default: 
	    cout<< "This is not an option, choose another option"<<endl;
	  }
      } while(input[0] !='0');
    }
  else if( argc == 4 && strcmp(argv[1],"-u")==0 && strcmp(argv[3],"-ud")== 0 ) //u weighted and undirected
    {
      bool directed = false;
      string fileName  = argv[2];
      MatrixGraph graph = createGraphUnWeighted(fileName, directed);
      string input;
        do
	  {
            menu();
            cin>>input;
            switch(input[0]) 
	      {
	      case '1':
		cout<< graph.toString()<< endl;
                break;
	      case '2':
		int v1,v2; 
		cout << "From vertex: " <<endl;; 
		cin >> v1;
		cout << "find vertex: " <<endl;
		cin >>v2;
		graph.getBFSPath(v1, v2);
		break;
	      case '3':
		{
		  cout<< "Enter a file name"<<endl;
		  cin>> newFileName;
		  MatrixGraph newGraph= createGraphWeighted(newFileName, true);
		  newFile = true;
		  cout<< newGraph.toString()<<endl;
		  
		  break;
		} 
	      case '4':
		{
		  if(newFile == false)
		    {
		      cout << "No file has been created yet." <<endl;
		    }
		  else
		    {
		      MatrixGraph newGraph= createGraphWeighted(newFileName, true);
		      int v1, v2; 
		      cout<<"From vertex: " <<endl;
		      cin >> v1;
		      cout <<"find vetex: "<< endl;
		      cin>>v2;
		      newGraph.getBFSPath(v1,v2);
		    }
		  break;
		}             
	      case '9':
		graph.printRaw();
		break;
	      case '0':                 
		break;
	      default: 
		cout<< "This is not an option, choose another option"<<endl;
	      }
	  } while(input[0] != '0');
    }
  else if( argc == 3 && strcmp(argv[1],"-u")==0 ) //unweighted and undirected graph
    {
      bool directed = true;
      string fileName  = argv[2];
      MatrixGraph graph = createGraphUnWeighted(fileName, directed);
      string input;
        do
	  {
            menu();
            cin>>input;
            switch(input[0]) 
	      {
	      case '1':
		cout<< graph.toString()<< endl;
                break;
	      case '2':
		int v1,v2; 
		cout << "From vertex: " <<endl;; 
		cin >> v1;
		cout << "find vertex: " <<endl;
		cin >>v2;
		graph.getBFSPath(v1, v2);
		break;
              case '3':
		{
		  cout<< "Enter a file name"<<endl;
		  cin>> newFileName;
		  MatrixGraph newGraph= createGraphWeighted(newFileName, true);
		  newFile = true;
		  cout <<newGraph.toString()<<endl;
		  
		  break;
		} 
	      case '4':
		{
		  if(newFile == false)
		    {
		      cout << "No file has been created yet." <<endl;
		    }
		  else
		    {
		      MatrixGraph newGraph= createGraphWeighted(newFileName, true);
		      int v1, v2; 
		      cout<<"From vertex: " <<endl;
		      cin >> v1;
		      cout <<"find vetex: "<< endl;
		      cin>>v2;
		      newGraph.getBFSPath(v1,v2);
		    }
		  
		  break;
		}
	      case '9':
		graph.printRaw();
		break;
	      case '0':                 
		break;
	      default: 
		cout<< "This is not an option, choose another options"<<endl;
	      }
	  } while(input[0] !='0');
    }
  else if( argc == 3 && strcmp(argv[1],"-w")==0 ) //weighted and undircted graph 
    {
        bool directed = true;
        string fileName  = argv[2];
        MatrixGraph graph = createGraphWeighted(fileName, directed);
        string input;
        do
        {
            menu();
            cin>>input;
            switch(input[0]) 
	      {
	      case '1':
		cout<< graph.toString()<< endl;
                break;
	      case '2':
		int v1,v2; 
		cout << "From vertex: " <<endl;; 
		cin >> v1;
		cout << "find vertex: " <<endl;
		cin >>v2;
		graph.getBFSPath(v1, v2);
		break;
	      case '3':
		int i1,i2;
		cout<<"Integer 1:" <<endl;
		cin >> i1;
		cout<<"Integer 2:" <<endl;
		cin>> i2;
		graph.getDijkstraPath(i1,i2);
		break;
	      case '4':
		int start;
		cout<< "what index should we start from" << endl;
		cin>>start;
		//      graph.getDijkstraAll(start);                                                                                                                        
		cout<<"is there a seg fault" <<endl;
		break;
	      case '5':
		{
		  cout<< "Enter a file name"<<endl;
		  cin>> newFileName;
		  MatrixGraph newGraph= createGraphWeighted(newFileName, false);
		  newFile = true;
		  cout << newGraph.toString()<<endl;
		  break;
		}
	      case '6':
		{
		  if(newFile == false)
		    {
		      cout << "No file has been created yet." <<endl;
		    }
		  else
		    {
		      MatrixGraph newGraph= createGraphWeighted(newFileName, true);
		      int v1, v2;
		      cout<<"From vertex: " <<endl;
		      cin >> v1;
		      cout <<"find vetex: "<< endl;
		      cin>>v2;
		      vector<int> bfsPath = newGraph.getBFSPath(v1,v2);
		      //String path = bfsPath.pritnBFSString(                                                                                                               
		    }
		  break;
		}
	      case '9':
		graph.printRaw();
		break;
	      case '0':
		break;
	      default:
		cout<< "This is not an option, choose another option"<<endl;
	      }
	} while(input[0] !='0');

    }
  else
    {
      usage();
    }
  return 0; 
}

void menu ()
{
  cout << "\nWelcome to the Graph Tester!" << endl;
  cout << "1) Print the graph" << endl;
  cout << "2) Find a BFS path" << endl;
  cout << "3) Find a Single Dijkstra Path" << endl;
  cout << "4) Find all Dijkstra Paths from a start" << endl;
  cout << "5) Start a file" << endl;
  cout << "6) Add a BFS path to the file" << endl;
  cout << "7) Add single Dijkstra Path to file" << endl;
  cout << "8) Add all Dijkstra Paths from a start to the file" << endl;
  cout << "0) Quit" << endl;
}
void usage()
{
  cout << "incorrect usage" <<endl;
}

//method to create weighted graph 
MatrixGraph createGraphWeighted(string fileName, bool directed)
{
  ifstream readFile(fileName); // read the file 

  string firstLine;
  getline(readFile, firstLine);
  stringstream getVertices (firstLine);
  int vertices;
  getVertices >> vertices;
  MatrixGraph graph = MatrixGraph(vertices, directed);
  string line; 
  while(getline(readFile, line))
    {
      stringstream getVertices(line);
      int v1,v2,weight;
      getVertices >>v1;
      getVertices >>v2;
      getVertices>>weight;
      graph.addEdge(v1-1,v2-1, float(weight));
    }
  return graph;
}
//method to createUnweighted graph 
MatrixGraph createGraphUnWeighted(string fileName, bool directed)
{
  ifstream readFile(fileName); // read the file 
  string firstLine;
  getline(readFile, firstLine);
  stringstream getVertices (firstLine);
  int vertices;
  getVertices >> vertices;
  MatrixGraph graph = MatrixGraph(vertices, directed);
  string line; 
  while(getline(readFile, line))
    {
      stringstream getVertices(line);
      int v1,v2;
      getVertices >>v1;
      getVertices >>v2;
      graph.addEdge(v1-1,v2-1);
    }
  return graph;
}
