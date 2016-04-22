//Tianyang He, th4xa, September 17, stack.h

#ifndef STACK_H
#define STACK_H
#include "List.h"

using namespace std;

class Stack {

 public:
  Stack();

  void push(int e);
  int top();
  void pop();
  bool empty();

 private:
  List* stack;

};

#endif 
  
