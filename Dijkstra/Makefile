exe: MatrixGraph_rooney.o rooney_TestGraph.o
	g++ -g -Wall -std=c++20 MatrixGraph_rooney.o rooney_TestGraph.o -o adjacencymatrix
rooney_TestGraph.o: rooney_TestGraph.cpp MatrixGraph_rooney.h minmaxHeap_rooneyCopy.hpp MatrixGraph_rooney.cpp Queue_rooney.hpp
	g++ -g -Wall -std=c++20 -c rooney_TestGraph.cpp MatrixGraph_rooney.cpp
MatrixGraph_rooney.o: MatrixGraph_rooney.cpp MatrixGraph_rooney.h
	g++ -g -Wall -std=c++20 -c MatrixGraph_rooney.cpp
