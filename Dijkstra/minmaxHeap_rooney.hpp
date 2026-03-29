/* 
Author: Peter Rooney 
Date: 03/15/2024
Description: 
    creates a min and max heap abstract data structure 
*/

#ifndef MINMAXHEAP_ROONEY_HPP
#define MINMAXHEAP_ROONEY_HPP
#include<stdlib.h>
#include<iostream> 
#include <concepts>

using namespace std; 

/********************
MIN HEAP
 *****************/
template<std::totally_ordered T> class MinHeap 
{
private:
  T* heap; 
  int size;  // the total size of the heap
  int index; //the index of the last element 
public: 
  //constructor; 
  MinHeap();
  MinHeap(int size);
  ~MinHeap();  //deconstructor 
  void enqueue(T data);  //adds item to the queue 
  void printHeap();
  void dequeue();  // removes item from the queue 
  T peek();  //returns the smalles value from the min heap 
  int getSize(); // return the number of items in the min heap 
  int getCapacity(); // returns the capacity min heap 
  bool isEmpty() ; // returns if the queue is empty 

private:
  void swap(int i , int j);
 
};

//constructor for min heap - sets size 10 0
template<std::totally_ordered T> MinHeap<T> :: MinHeap()
{
  heap = new T[10];
  index = 0; 
  size = 10;

}
//deconstructor - deletes the head array 
template<std::totally_ordered T> MinHeap<T> :: ~MinHeap()
{
  delete [] heap; 
}

//constructor - sets the min heap array to a certain size
template<std::totally_ordered T> MinHeap<T> :: MinHeap(int size)
{
  this->size = size; 
  heap = new T[size];
  index = 0; 
}

//adds an item to the min heap and makes sure it satisfies min heap property 
template<std::totally_ordered T> void MinHeap<T> :: enqueue(T data)
{
                                                                                                                                                                                            
  if(index == size) // if there is no more space in the heap                                                                                                                                
    {                                                                                                                                                                                       
      throw "heap is full";                                                                                                                                                                
    }    
  int i =index; 
  heap[index] = data;
  index++;
  while(i > 0 && heap[i] < heap[(i - 1) / 2]) 
    {
    swap(i, (i - 1) / 2);
    i = (i - 1) / 2;
    }
  /*

  if(index == size) // if there is no more space in the heap 
    {
      throw "heap is full";
    }

  int i = index;
  heap[index] = data;
  index++; 
  while(i> 0 && heap[i] < heap[i-1])  // while the elements is not the min 
      {
	swap(i, i-1); //swap it 
	i --;
      }
  */
}

//method to swap two values in the heap array 
template<std::totally_ordered T> void MinHeap<T> :: swap(int i, int j)
{
  T temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp; 
}

//method to print out the heap - used for testing 
template<std::totally_ordered T> void MinHeap<T> :: printHeap()
{
  for(int i =0; i<size; i++)
    {
      cout <<heap[i] << " "; 
    }
}

//method to remove the smalles item from the array 
template<std::totally_ordered T> void MinHeap<T> :: dequeue()
{
  /*
  if(this->isEmpty())  // if there is no items in the array throw an exception 
    {
      throw std:: out_of_range("Empty heap");
    }
  //swap the first and last elements in the array
  swap(0, index-1);
  //delete the last element
  index--;
  //adjust the array so this satisfie the min heap property 
  int i =0; 
  while((heap[i] > heap[i+1])&& i < index-1)
    {
      swap(i, i+1);
      i++;
    }
  */
  if (this->isEmpty()) {
    throw std::out_of_range("Heap is empty");
  }
  swap(0, index - 1);
  index--;
  int i = 0;
  int leftChild, rightChild, minChild;
  while (i < index) {
    leftChild = 2 * i + 1;
    rightChild = 2 * i + 2;
    minChild = i;

    if (leftChild < index && heap[leftChild] < heap[minChild]) {
      minChild = leftChild;
    }
    if (rightChild < index && heap[rightChild] < heap[minChild]) {
      minChild = rightChild;
    }

    if (minChild != i) {
      swap(i, minChild);
      i = minChild;
    } else {
      break;
    } 
  }
}

//returns the first elements - which will be the smallest
template<std::totally_ordered T> T MinHeap<T> :: peek()
{
  if(this->isEmpty())
    {
      throw "heap is empty";
    }
  return heap[0];
}

//gets the amounf of items currently in the heap 
template<std::totally_ordered T> int  MinHeap<T> :: getSize()
{
  return index; 
}

//gets the size the heap can hold 
template<std::totally_ordered T> int MinHeap<T>:: getCapacity()
{
  return size; 
}

//chekc if the heap is empty 
template<std::totally_ordered T> bool MinHeap<T> :: isEmpty()
{
  bool isEmpty = true; 
  if (index >0)
    {
      isEmpty = false;
    }
  return isEmpty; 
}


/**********************
MAX HEAP 
 *********************/
template<std::totally_ordered T> class MaxHeap
{
private:
  T* heap;
  int size;  // the total size of the heap                                                                                                                              
  int index; //the index of the last element                                                                                                                            
public:
  //constructor;                                                                                                                                                        
  MaxHeap();
  MaxHeap(int size);
  ~MaxHeap();  //deconstructor                                                                                                                                         
  void enqueue(T data);  //adds item to the queue                                                                                                                      
  void printHeap();
  void dequeue();  // removes item from the queue                                                                                                                      
  T peek();  //returns the largest  value from the max heap                                                                                                            
  int getSize(); // return the number of items in the max heap                                                                                                         
  int getCapacity(); // returns the capacity max heap                                                                                                                  
  bool isEmpty() ; // returns if the queue is empty                                                                                                                    
private:
  void swap(int i , int j);

};

//construct max heap 
template<std::totally_ordered T> MaxHeap<T> :: MaxHeap()
{
  heap = new T[10];
  index = 0; 
  size =10; 

}
//deconstructor
template<std::totally_ordered T> MaxHeap<T> :: ~MaxHeap()
{
  delete [] heap;
}

//construct max heap with a certain size
template<std::totally_ordered T> MaxHeap<T> :: MaxHeap(int size)
{
  this->size = size;
  heap = new T[size];
  index = 0;
}

//add an item to the max heap - makes sure it satisfies max heap property 
template<std::totally_ordered T> void MaxHeap<T> :: enqueue(T data)
{
  if(index == size)
    {
      throw "heap is full";
    }
  int i = index;
  heap[index] = data;
  index++;
  while(i> 0 && heap[i] > heap[i-1]) // if the current index is samller than the parent 
    {
      swap(i, i-1); //then we need to swap to make it larger
      i --;
    }
}
//swap two elements 
template<std::totally_ordered T> void MaxHeap<T> :: swap(int i, int j) 
{
  T temp = heap[i];
  heap[i] = heap[j];
  heap[j] = temp;
}

//print out the heap 
template<std::totally_ordered T> void MaxHeap<T> :: printHeap()
{
  for(int i =0; i<size; i++)
    {
      cout <<heap[i] << " ";
    }
}
//remove the largest element from the heap 
template<std::totally_ordered T> void MaxHeap<T> :: dequeue()
{
  if(this->isEmpty())
    {
      throw std:: out_of_range("Empty heap");
    }
  //swap the first and last elements in the array                                                                                                                       
  swap(0, index-1);
  //delete the last element                                                                                                                                             
  index--;
  //adjust the array so this satisfie the min heap property                                                                                                             
  int i =0;
  while((heap[i] < heap[i+1])&& i < index-1)
    {
      swap(i, i+1);
      i++;
    }
}

//return the largest element in the heap 
template<std::totally_ordered T> T MaxHeap<T> :: peek()
{
  if(this->isEmpty())
    {
      throw "heap is empty";
    }
  return heap[0];
}

//get the amount of items in the heap 
template<std::totally_ordered T> int  MaxHeap<T> :: getSize()
{
  return index;
}

//get the size the heap can hold 
template<std::totally_ordered T> int MaxHeap<T>:: getCapacity()
{
  return size;
}

//checks if the heap is empty 
template<std::totally_ordered T> bool MaxHeap<T> :: isEmpty()
{
  bool isEmpty = true;
  if (index >0)
    {
      isEmpty = false;
    }
  return isEmpty;
}

#endif
