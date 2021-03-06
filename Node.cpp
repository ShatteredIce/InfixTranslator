//Node class for InfixTranslator.cpp

#include <iostream>
#include "Node.h"

using namespace std;

//Constructor: stores a char, sets next to NULL
Node::Node(char newToken){
  token = newToken;
  next = NULL;
}

//returns the value stored in the node
char Node::getValue(){
  return token;
}

 //sets the pointer to the next node in the linked lists
void Node::setNext(Node* newNode){
  next = newNode;
}

//gets the pointer to the next node, may return null
Node* Node::getNext(){
  return next;
}
