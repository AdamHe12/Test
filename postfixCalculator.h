//Tianyang He, th4xa, September 17, postfixCalculator.h
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "stack.h"

using namespace std;

class PostfixCalculator {

 public:
  PostfixCalculator();
 
  void pushNum(int e);
  void add();
  void minus();
  void multiply();
  void divide();
  void negate();
  int getTopValue();

 private:
  Stack calculator;
  
};

#endif 
  

