//Node class for InfixTranslator.cpp

#include <iostream>
#include "Node.h"

using namespace std;

//Constructor: stores a char, sets next to NULL
Node::Node(char newToken){
  token = newToken;
  next = NULL;
}

char Node::getValue(){
  return token;
}

void Node::setNext(Node* newNode){
  next = newNode;
}

Node* Node::getNext(){
  return next;
}
