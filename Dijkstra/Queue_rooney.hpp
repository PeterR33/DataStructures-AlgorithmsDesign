/*
Author: Peter Rooney 
Date: 01/05/2024
Description: This creates a queue data structure that will keep track of
the availabel "blocks" of a simulated hard drice 
*/
#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include<string>
#include<iostream>
using namespace std; 
/************
NODE CLASS
***************/
template <typename T> class Node
{
private: 
  T data; 
  Node<T>* next; 
public: 
  Node();
  Node(T data);

  T getData(); 
  void setData(T data);
  Node<T>* getNext();
  void setNext(Node<T>* next);

};
template <typename T> Node<T> :: Node()
{
  this->next = nullptr; 
}
template <typename T> Node<T> :: Node(T data)
{
  this->data = data; 
  this->next = nullptr; 

}
template <typename T> T Node<T> :: getData()
{
  return data; 
}
template <typename T> void Node<T> :: setData(T data)
{
  this->data = data;
}
template <typename T> Node<T>* Node<T> :: getNext()
{
  return next; 
}
template <typename T> void Node<T> :: setNext(Node<T>* next)
{
  this-> next = next; 
}

/***********
 QUEUE CLASS
***************/
template <typename T> class Queue
{
  //private data 
private: 
  Node<T>* head; 
  Node<T>* tail; 
  int size; 
  //public data 
public: 
  //constructors 
  Queue();
  ~Queue();

  // getter setter methods 
  void enqueue(T item);  //always add to the head of the queue
  void dequeue();

  T front(); 
  int getSize();
  void empty();
  bool isEmpty();
  void printQueue();
};

template <typename T> Queue<T> :: Queue()
{
  tail  = nullptr;
  head = nullptr;
  size = 0; 
}
template <typename T> Queue<T> :: ~Queue()
{
  empty();
}
template <typename T> void Queue<T> :: enqueue(T item)
{
  Node<T>* newNode = new Node<T>(item); 
  if(head == nullptr)
    {
      head = newNode;
      tail  = newNode; 
      size++;
      return ;
    }
  tail->setNext(newNode);
  tail = newNode; 
  size++;
  /*
    Node<T>* newNode = new Node<T>(item);
    newNode->setNext(head);
    head = newNode;
    size++;
  */
}
template <typename T> void Queue<T> :: dequeue() // removes the head item of the queue
{
  if(head == nullptr)
    {
      throw std::out_of_range("can't delete from an empty list");
    }
  // are we deleting the last LinkedNode
  if (head == tail )
    {
      delete head; 
      head = nullptr; 
      tail = nullptr; 
    }
  else
    {
      Node<T>* temp = head; 
      head = head->getNext();  // more head forward one
      temp->setNext(nullptr);
      delete temp; 
    }
  size-- ; 
   
}
template <typename T> T Queue<T> :: front()
{
  return head->getData();
}
template <typename T> int Queue<T> :: getSize()
{
  return size;
}
template <typename T> void Queue<T> :: empty()
{
  Node<T>* temp = head; 
  while(head != nullptr)
    {
      head = head ->getNext();  // head will eventually be null 
      delete temp; 
      temp = head;
    }
  size = 0; 
}
template <typename T> void Queue<T> :: printQueue()
{
  Node<T>* walk = head; 
  while(walk != nullptr)
    {
      cout<<"[ " ; 
      cout << walk->getData();
      cout<< "]" <<endl;
      walk = walk->getNext();
    }
}

template <typename T> bool Queue<T> :: isEmpty()
{
  bool isEmpty = false; 
  if(size ==0 )
    {
      isEmpty =  true; 
    }
  return isEmpty;
}
#endif
