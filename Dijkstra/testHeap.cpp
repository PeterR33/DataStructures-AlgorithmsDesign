include<iostream>
#include"minmaxHeap_rooney.hpp"
#include<string>
using namespace std;

int main(void)
{
  MinHeap<int> a = MinHeap<int>(10);
  a.enqueue(6);
  a.enqueue(5);
  a.enqueue(9);
  a.enqueue(7);
  a.enqueue(17);
  a.enqueue(10);
  a.enqueue(2);
  a.enqueue(3);
  a.enqueue(11);
  a.printHeap();
  cout<< " ___" << endl;
  a.dequeue();
  a.printHeap();
  a.peek();
  cout<< "the size of this heap is " <<a.getSize()<< endl;
  cout<< "the total capacity of this heap is " << a.getCapacity() <<endl;
  MinHeap<string> b = MinHeap<string>(15);
  b.enqueue("hello");
  b.enqueue("abc");
  a.dequeue();
  cout<<"string heap" << endl;
  b.printHeap();
  MaxHeap<int> max = MaxHeap<int>(15);
  max.enqueue(15);
  max.enqueue(17);
  max.enqueue(14);
  max.enqueue(25);
  max.printHeap();
}
