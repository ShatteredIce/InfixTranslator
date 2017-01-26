//Node class for InfixTranslator.cpp

#include <iostream>
#include "Node.h"

using namespace std;

//Constructor: stores a char, sets next to NULL
Node::Node(char newToken){
  token = newToken;
  next = NULL;
}

void Node::setNext(Node* newNode){
  next = newNode;
}

Node* Node::getNext(){
  return next;
}

void Node::setLeftChild(Node* newNode){
  leftChild = newNode;
}

Node* Node::getLeftChild(){
  return leftChild;
}

void Node::setRightChild(Node* newNode){
  rightChild = newNode;
}

Node* Node::getRightChild(){
  return rightChild;
}
