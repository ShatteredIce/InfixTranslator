#ifndef NODE_H
#define NODE_H

//Header file for Node.cpp
//Node for a linkedlist, stores a char token, next node, left and right childs with respective accessors and mutators.

#include <iostream>

using namespace std;

class Node {
 public:
  Node(char);
  char getValue();
  void setNext(Node*);
  Node* getNext();
  void setLeftChild(Node*);
  Node* getLeftChild();
  void setRightChild(Node*);
  Node* getRightChild();
 protected:
  char token;
  Node* leftChild;
  Node* rightChild;
  Node* next;
};
#endif
