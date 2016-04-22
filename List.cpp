//Tianyang He, th4xa, September 17, List.cpp
#include "List.h"
using namespace std;
#include <stddef.h>

List::List(){
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  tail->previous=head;
  count = 0;
}

List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}


List::~List(){
  
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if(count == 0){
    return true;
  } else {
    return false;
  }
}

void List::makeEmpty(){
  if(isEmpty()){
  } else {
  head->next = tail;
  tail->previous = head;
  count = 0;
  }
}

ListItr List::first(){
  ListItr *l = new ListItr();
  l->current->value = head->next->value;
  l->current->previous = head;
  l->current->next = head->next->next;
  return *l;
}

ListItr List::last(){
  ListItr *l = new ListItr();
  l->current->value = tail->previous->value;
  l->current->next = tail;
  l->current->previous = tail->previous->previous;
  return *l;
}

void List::insertAfter(int x, ListItr position){
  ListNode *l = new ListNode();
  l->value = x;
  l->previous = position.current;
  l->next = position.current->next;
  position.current->next = l;
  l->next->previous = l;
  count++;
}

void List::insertBefore(int x, ListItr position){
  ListNode *l = new ListNode();
  l->value = x;
  l->next = position.current;
  l->previous = position.current->previous;
  position.current->previous = l;
  l->previous->next = l;
  count++;

}

void List::insertAtTail(int x) {
  ListNode *l = new ListNode();
  l->value = x;
  l->next = tail;
  l->previous = tail->previous;
  tail->previous = l;
  l->previous->next = l;
  count++;
}

void List::remove(int x){
  ListItr l = find(x);
  if(!l.isPastEnd()&&!l.isPastBeginning()){
  l.current->previous->next = l.current->next;
  l.current->next->previous = l.current->previous;
  count--;
  }
 
}

ListItr List::find(int x) {
  ListItr l = first();
  while(l.current->value!=x){
    l.moveForward();
    if(l.isPastEnd()){
      break;
    }
  }
  return l;
}
int List::size() const{
  return count;
}
