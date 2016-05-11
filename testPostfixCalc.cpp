//Tianyang He, th4xa, September 17, testPostfixCalc.cpp
#include "postfixCalculator.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stddef.h>
using namespace std; 

int main() {
  
    PostfixCalculator p3;

    while (cin.good()) {
      string s;
      cin >> s;	
      char s1[s.length() + 1];
      strcpy(s1, s.c_str());

      if(isdigit(s1[0])){
	p3.pushNum(atoi(s1));
      }
      if(s.compare("+") == 0){
	p3.add();
      }
      if(s.compare("*") == 0){
	p3.multiply();
      }
      if(s.compare("/") == 0){
	p3.divide();
      }
      if(s.compare("~") == 0){
	p3.negate();
      }
      if(s1[0] == '-') {
       if(isdigit(s1[1])){
        p3.pushNum(atoi(s1));
       } else {
       	p3.minus();
       }
      }
      
      if(s == "") {
           break;
      }
    }
    cout << "Result is: " << p3.getTopValue() << endl;
    return 0;   
}
