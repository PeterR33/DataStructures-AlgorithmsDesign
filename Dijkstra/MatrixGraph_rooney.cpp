/*
Author: Peter Rooney 
Date :  02-06-2024
Descritption: 
    provide the declarations for the Matrix Graph class 
*/
#include <sstream>  
#include <iomanip>
#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include "MatrixGraph_rooney.h"
#include "minmaxHeap_rooneyCopy.hpp"
#include "Queue_rooney.hpp"
using namespace std; 
MatrixGraph:: MatrixGraph (int vertices, bool directed)
{ 
  this->vertices = vertices; //teh amount of vertices will also be the size fo teh matrix 
  this->directed = directed;
  this->graph = new float*[vertices]; // intirliaze the graph with pointers, everything will be at 0 first
  for ( int i = 0; i <vertices; i++)
    {
      graph[i] = new float[vertices];
    }
  for(int i =0; i< vertices; i++)
    {
      for (int j= 0; j<vertices; j++)
        {
	  graph[i][j] = 0;
        }
    }
}
MatrixGraph:: ~MatrixGraph()
{
  for(int i = 0; i<vertices; i++)
    {
      delete graph[i];
    }
  delete [] graph;
}
void MatrixGraph :: addEdge( int v1, int v2)
{
  graph [v1][v2] = 1;
}
void MatrixGraph :: addEdge( int v1, int v2, float weight)
{
  graph [v1][v2] = weight;
}

void MatrixGraph :: removeEdge( int v1, int v2)
{
  graph [v1][v2] = 0;
  if(!directed)// if the graph is undricted we have to remove the other edge in the other direction too
    {
      graph [v2][v1] =0; 
    }
}
float MatrixGraph :: getEdgeWeight( int v1, int v2)
{
  return graph [v1][v2];
}
void MatrixGraph :: setEdgeWeight( int v1, int v2, float weight)
{
  graph [v1][v2] = weight;
  if(!directed) // it is is undirected then the edge going both ways should get the weight. 
    {
      graph[v2][v1] = weight; 
    }
}
void MatrixGraph::printRaw()
{
  for(int i =0; i< vertices; i++)
    {
      for (int j= 0; j<vertices; j++)
        {
	  cout  << setw(5) << fixed << setprecision(2) << graph[i][j]<< " " ;
           
        }
      cout <<endl;
    }
}
bool MatrixGraph :: pathExists(int v1, int v2)
{
  vector<int> path; //path to get to targe
  Queue<int> neighbors = Queue<int>();
  int visited[vertices]; //array to keep track it the vertex has been visited 
  //if the array has a zero for that vertex it has not been visited and will change to a one if it has
  for(int i = 0; i< vertices; i++)
    {
      visited[i] =0;
    }
  neighbors.enqueue(v1);
  visited[v1] = 1;
  while(!neighbors.isEmpty())
    {
      int currentNode = neighbors.front();
      neighbors.dequeue();
      if(currentNode == v2)
	{
	  return true ; 
	}
      for (int i =1; i<vertices; i++)
	{
	  if(adjacent(currentNode-1, i-1) && visited[i] == 0)
	    {
	      neighbors.enqueue(i);
	      visited[i] = 1;
	    }
	}
    }
  return false; 
}
bool MatrixGraph :: adjacent(int v1, int v2)
{
  if(graph [v1][v2] != 0)
    {
      return true;
    }
  return false;
}
std:: string MatrixGraph :: toString()
{

  stringstream connectedGraph ;
  for( int i =0; i< vertices; i++)
    {
      connectedGraph << "[" << std::setw(2) << i+1 << "]:";
      for (int j =vertices; j>=0; j--)
        {
	  if (adjacent(i,j))
            {
	      connectedGraph << "-->" << "[" << std::setw(2) << i+1 << ", " << setw(2) << j+1
			     << "::" << fixed << setprecision(2)  << setw(5) << graph[i][j] << "]";
            }

        }
      connectedGraph << "\n";
    }
  return connectedGraph.str();
}
vector<int> MatrixGraph :: getBFSPath(int v1, int v2)
{

  /*
    Algoithm to follow:
    1. Need to keep track of visited and queue and the node that came bfore the one I am checking
    2. mark the first vertex that is given as visisted (as it has to be visited)
    3. put it in the queue
    4. loop
        dequque the queue, if the node dequeed is the one we are looking for 
        then we are finished 
        if not queue its neightbors and mark it as visited 
        add the vertices that are used to the path */
    
  vector<int> path; //path to get to targe
  Queue<int> neighbors = Queue<int>();
  int visited[vertices]; //array to keep track it the vertex has been visited 
  //if the array has a zero for that vertex it has not been visited and will change to a one if it has
  int ancestor [vertices]; 
  for(int i = 0; i< vertices; i++)
    {
      ancestor[i] =-1;
    }
  for(int i = 0; i< vertices; i++)
    {
      visited[i] =0;
    }
  float cost[vertices];
  for(int i = 0; i< vertices; i++)
    {
      cost[i] =0.00;
    }
  neighbors.enqueue(v1);
  visited[v1] = 1;
  cost[v1] = 0.00; //to get to the first vertex the cost will alwasy be 0
  while(!neighbors.isEmpty())
    {
      int currentNode = neighbors.front();
      neighbors.dequeue();
      if(currentNode == v2)
	{
	  int j = v2; 
	  path.push_back(j);
	  while (j !=v1)
	    {
	      j = ancestor[j];
	      path.insert(path.begin(), j);
               
	    }
	  cout <<endl;
	  printPath(path,v1,v2, cost);
	  return path; 
	}
        
      if(!directed)
	{
	  for (int i =1; i<vertices; i++)
	    {
	      if ((adjacent(i-1,currentNode-1)!= 0 || adjacent(currentNode-1,i-1) !=0) && !visited[i] && !directed) //if the graph is undricted we need to check both sides edges of the graph
		{ 
		  neighbors.enqueue(i);
		  visited[i] = 1;
		  ancestor[i] = currentNode;
		  cost[i] = graph[i-1][currentNode-1];
		}
	    }
	}
      else
	{
	  for (int i =1; i<vertices; i++)
            {
              
	      if(adjacent(currentNode-1, i-1) && visited[i] == 0)
                {
		  neighbors.enqueue(i);
		  visited[i] = 1;
		  ancestor[i] = currentNode;
		  cost[i] = graph[currentNode-1][i-1];
                }
            }
        }
    }
  cout << "there is no path << "<<endl;
  path.push_back(-5); // just put -5 in is there is not path 
  printPath(path, v1,v2, cost);
  return path; 
}
vector<int> MatrixGraph::getDijkstraPath(int v1, int v2)
{
  vector<int>path;
  int visited[vertices]; //array to keep track it the vertex has been visited                                                                                                               
  //if the array has a zero for that vertex it has not been visited and will change to a one if it has                                                                                      
  int ancestor [vertices];  //array to keep track of the previous nodes                                                                                                                     
  //  MinHeap<int> indexQueue = MinHeap<int>(8);
  MinHeap<float> costQueue = MinHeap<float>(8);
  float cost[vertices];
  for(int i = 0; i< vertices; i++)
    {
      ancestor[i] =-1; //initialize to -1                                                                                                                             
      visited[i] =0; //0 if not visited will be 1 if it is visited                                                                                                     
      cost[i]= 99999999999.0;
    }
  cost[v1] = 0.0;
  //  visited[v1] = 1;
  costQueue.enqueue(0.0);
  //indexQueue.enqueue(v1);
  cout << "starting now" << endl;
  float checkCost;
  int currentIndex = v1;
  //deque the cost what indexes di that cost come from 
  while(currentIndex < v2)
    {
      cout<<"We are in the dijkstra loop!" <<endl;
      float currentCost  = costQueue.peek();
      currentIndex = findIndex(currentCost);
      cout <<"currenItem being checked" << currentIndex<<endl;
      cout<<"currentCost : " << currentCost <<endl;
      costQueue.dequeue();
      //      indexQueue.dequeue();
      if(visited[currentIndex] == 1) //ifthe currentItem in the min heap has already been visited then we can skip this iteration of the looop
       {
       continue;
      	}
      visited[currentIndex] =1; //mark the current Item as visited 
      if(currentIndex == v2)
	{
	   int j = v2;
	   path.push_back(j);
	   while (j !=v1)
	    {
	       j = ancestor[j];
	       path.insert(path.begin(), j);
	    }
	    cout <<endl;
	    printPath(path,v1,v2, cost);
	    return path;
	}
      for(int i = 0; i<vertices; i++)
	{
	  if(adjacent(currentIndex, i) && visited[i] == 0)
	    {
	      cout<<"graph[currentItem][i-1] " << graph[currentIndex][i]<<endl;
	      checkCost = currentCost +  graph[currentIndex][i];
	      cout <<"check cost is" << checkCost <<endl;
	      cout<<"cost[i] is " << cost[i] <<endl;
	      if(checkCost < cost[i])  
		{
		  cost[i] = checkCost;
		  ancestor[i] = currentIndex;
		  cout<<"i that is being enqueue is " << i <<endl;
		  //indexQueue.enqueue(i);
		  costQueue.enqueue(checkCost);
		  cout << "the cost min heap is ";
		  costQueue.printHeap();
		  cout <<endl;
		}
	    }
	}
    }
  path.push_back(-5);
  cout<<"path is empty" <<endl;
  return path; 
}

vector<vector<int>> MatrixGraph::getDijkstraAll(int start)
{
  vector<vector<int>> allPaths;           
  /*
   Algoirhtm to follow
  vector<vector<int>> allPaths;
  Queue<int> neighbors = Queue<int>(); //queue for the neighbors
  int visited[vertices]; //array to keep track it the vertex has been visited 
  //if the array has a zero for that vertex it has not been visited and will change to a one if it has
  int ancestor [vertices];  //array to keep track of the previous nodes 
  MinHeap<int> indexQueue = MinHeap<int>();
  MinHeap<int>costQueue = MinHeap<int>();

  float cost[vertices];
  for(int i = 0; i< vertices; i++)
    {
      ancestor[i] =-1; //initialize to -1
      visited[i] =0; //0 if not visited will be 1 if it is visited 
      cost[i]= 99999999999.0;
      
      if( i != start)
	{
	  priorityQueue.enqueue(i);
	}
      
    }
      cout<< "the start is " << indexQueue.peek()<<endl;
      cost[start] = 0.0;
      visited[start] = 1;
      costQueue.enqueue(cost[start]);

      while(!indexQueue.isEmpty())
	{
	  cout<<"We are in the dijkstra loop!" <<endl;
	  int currentItem =indexQueue.peek();
	  float currentCost  = costQueue.peek();
	  costQueue.dequeue();
	  indexQueue.dequeue();
	  visited[currentItem] = 1;
	  for(int i = 0; i<vertices; i++)
	    {
	      if(adjacent(currentItem-1, i-1)&& visited[i] == 0)
		{
		  float checkCost = currentCost +graph[currentItem][i];
		  if(checkCost < cost[i])
		    {
		      cost[i] = checkCost;
		      ancestor[i] = currentItem;
		      indexQueue.enqueue(i);
		      costQueue.enqueue(checkCost);
		    }
		}
	    }

	}
      for (int i = 0; i < vertices; i++) {
	cout << "Vertex " << i << " - Cost: " << cost[i] << ", Predecessor: " << ancestor[i] << endl;
      }
      for (int i = 0; i < vertices; i++)
	{
	if (i != start && cost[i] != 99999999999.0) { // used to check is a path even exist 
	  vector<int> path;
	  for (int j = i; ancestor[j] != -1; j = ancestor[j]) 
	  {
	    path.insert(path.begin(), j);
	  }
	  path.insert(path.begin(), start);
	  allPaths.push_back(path);
	}
      }
  */
      return allPaths; 
}
void MatrixGraph::printPath(vector<int> path, int v1, int v2, float cost[])
{
  cout<< "Path from " << v1 << " to " << v2 << "  is: " << endl;
  for (size_t i = 0; i < path.size(); i++) 
    {   
      cout << "[" << setw(2) << path[i] << ":" << setw(5) << setprecision(2) <<fixed << cost[path[i]] << "]";
      if (i < path.size() - 1)
	{
	  cout << "==>";
	}
    }
  cout <<endl;
}
string MatrixGraph::printPathString(vector<int> path, int v1, int v2, float cost[])
{
  ostringstream thePath;
  thePath<< "Path from " << v1 << " to " << v2 << "  is: " << endl;
  for (size_t i = 0; i < path.size(); i++)
    {
      thePath << "[" << setw(2) << path[i] << ":" << setw(5) << setprecision(2) <<fixed << cost[path[i]] << "]";
      if (i < path.size() - 1)
        {
          thePath << "==>";
        }
    }
  thePath <<endl;
  return thePath.str();
}

int MatrixGraph:: findIndex (int cost)
{
  for(int i =0; i <vertices; i++)
    {
      for(int j = 0; j<vertices; j++)
	{
	  if(graph[i][j] == cost)
	    {
	      return i; 
	    } 
	}
    }
  cout<<"there is no index at that cost" <<endl;
  return -1;
}
