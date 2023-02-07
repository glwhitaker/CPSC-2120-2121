/*
 * Name: Grayson Whitaker
 * Date Submitted: 1/30/2023
 * Lab Section: 002
 * Assignment Name: Lab 1 Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
  mySize = 0;
  start = nullptr;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  while(start != nullptr){
    removeStart();
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  if(mySize == 0){
    return true;
  }
  else{
    return false;
  }
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  // new node with data value
  Node<T> * temp = new Node(value);
  // point new node to old start
  temp->next = start;
  // point start to new node
  start = temp;
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    insertStart(value);
  }
  else{
    // iterate to end of list
    while(iterator->next != nullptr){
      iterator = iterator->next;
    }
    // create new node
    Node<T> * temp = new Node(value);
    // point last node to new node
    iterator->next = temp;
    mySize++;
  }

}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    insertStart(value);
  }
  // if position is 0
  else if(j == 0){
    insertStart(value);
  }
  else{
    // iterate to node before position j
    for(int i = 0; i < j - 1; i++){
      iterator = iterator->next;
    }
    // create new node
    Node<T> * temp = new Node(value);
    // point new node to next node
    temp->next = iterator->next;
    // point previous node to new node
    iterator->next = temp;
    mySize++;
  }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    return;
  }
  else{
    // point start to next node
    start = iterator->next;
    // delete old start
    delete iterator;
    mySize--;
  }
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    return;
  }
  // if list has one node
  else if(iterator->next == nullptr){
    removeStart();
  }
  // if list has more than one node
  else{
    // iterate to second to last node
    while(iterator->next->next != nullptr){
      iterator = iterator->next;
    }
    // delete last node
    delete iterator->next;
    // point second to last node to null
    iterator->next = nullptr;
    mySize--;
  }
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    return;
  }
  // if list has one node
  else if(iterator->next == nullptr){
    removeStart();
  }
  // if list has more than one node
  else{
    // iterate to node before position j
    for(int i = 0; i < j - 1; i++){
      iterator = iterator->next;
    }
    // create temp node to delete at position j
    Node <T> * temp = iterator->next;
    // point node before position j to node after position j
    iterator->next = iterator->next->next;
    // delete node at position j
    delete temp;
    mySize--;
  }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    return T();
  }
  else{
    return iterator->value;
  }
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    return T();
  }
  else{
    // iterate to last node
    while(iterator->next != nullptr){
      iterator = iterator->next;
    }
    return iterator->value;
  }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    return T();
  }
  else{
    // iterate to node at position j
    for(int i = 0; i < j; i++){
      iterator = iterator->next;
    }
    return iterator->value;
  }
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  // create iterator
  Node<T> * iterator = start;
  // if list is empty
  if(iterator == nullptr){
    return -1;
  }
  else{
    // iterate through list
    for(int i = 0; i < mySize; i++){
      // if value is found
      if(iterator->value == key){
        return i;
      }
      iterator = iterator->next;
    }
    return -1;
  }
}
