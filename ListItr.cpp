//Tianyang He, th4xa, September 17, ListItr.cpp
#include "List.h"
#include "ListNode.h" 
using namespace std;
#include <stddef.h>

ListItr::ListItr(){
  current = new ListNode();

}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if(current->next == NULL){
  return true;
  } else {
    return false;
  }
}

bool ListItr::isPastBeginning() const {
  if(current->previous == NULL){
  return true;
  } else {
    return false;
  }
}

void ListItr::moveForward() {
  if(!isPastEnd()){
    current = current->next;
  }

}

void ListItr::moveBackward() {
  if(!isPastBeginning()){
    current = current->previous;
  }
 
}

int ListItr::retrieve() const {
  return current->value;
}

void printList(List& theList, bool forward){
  if(forward){
  ListItr l = theList.first();
  while(!l.isPastEnd()){
    cout<<l.retrieve()<<endl;
    l.moveForward();
  }
  } else {
  ListItr l = theList.last();
  while(!l.isPastBeginning()){
    cout<<l.retrieve()<<endl;
    l.moveBackward();
  }
  }
}
