/* 
Author: Peter Rooney 
Date: 03/30/34
Description: 
   This class create a grah using an adjacency matrix
Usage: 
*/
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
#include "minmaxHeap_rooneyCopy.hpp"
#include "Queue_rooney.hpp"

class MatrixGraph 
{
 private: 
        
  int vertices; 
  bool directed ; 
  float ** graph ; //the matrix representation of the graph, beucase we can add and remove edges at run time 
  //it should be dynmaically allocated memory
 public: 
  MatrixGraph(int, bool);
  ~MatrixGraph();
  void addEdge (int, int );
  void addEdge (int, int, float);
  void removeEdge(int, int);
  bool adjacent (int, int);
  float getEdgeWeight(int, int);
  void setEdgeWeight (int, int, float);
  std:: string toString();
  void printRaw();
  bool pathExists(int, int );
  vector<int> getBFSPath(int, int);
  void printPath(vector<int>, int v1, int v2, float cost[]);
  vector<int> getDijkstraPath(int, int);
  vector<vector<int>> getDijkstraAll(int);
  string printPathString(vector<int>, int, int, float cost[]);
  int findIndex(int);
  //  string geXStBFSPath(int, int);
};


