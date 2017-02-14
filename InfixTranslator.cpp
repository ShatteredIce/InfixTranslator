#include <iostream>
#include <string.h>
#include "Node.h"

using namespace std;

Node* getLastNode(Node* current);
void deleteAllNodes(Node* & head);
void display(Node* current);
void getInput(char* input);
bool isValidInput(char* input);
void deleteWhitespace(char* input);

int main(){

  Node* inputHead = NULL;
  Node* operatorHead = NULL;
  Node* outputHead = NULL;
  Node* temp;
  bool running = true;
  char input[81];

  cout << "\n-----Infix Translator v1.0-----\n";
  cout << "Converts expressions into prefix or postfix notation\n";
  cout << "C++ Project 8 - Nathan Purwosumarto\n\n";

  while(running){
    cout << "Awaiting input (infix notation): ";
    getInput(input);
    //if input = QUIT, then end the program
    if(strcmp(input, "quit") == 0){
      cout << "\nProgram Terminated." << endl;
      running = false;
    }
    else if(isValidInput(input) && strlen(input) > 0){
      if(outputHead != NULL){
        deleteAllNodes(outputHead);
      }
      inputHead = new Node(input[0]);
      temp = inputHead;
      //build the input queue
      for(int i = 1; i < strlen(input); i++){
        temp->setNext(new Node(input[i]));
        temp = temp->getNext();
      }

      //shunting yard algorithm
      temp = inputHead;
      while(temp != NULL){
        //puts value into output stack if it is a digit
        if(isdigit(temp->getValue())){
          if(outputHead == NULL){
            outputHead = new Node(temp->getValue());
          }
          else{
            getLastNode(outputHead)->setNext(new Node(temp->getValue()));
          }
        }
        temp = temp->getNext();
      }
      display(outputHead);
      cout << endl;
    }
  }
  return 0;
}

Node* getLastNode(Node* current){
  while(current->getNext() != NULL){
    current = current->getNext();
  }
  return current;
}

void deleteAllNodes(Node* & head){
  while(head->getNext() != NULL){
    Node* temp = head->getNext();
    delete head;
    head = temp;
  }
  delete head;
  head = NULL;
}

void display(Node* current){
  if(current != NULL){
    cout << current->getValue();
    display(current = current->getNext());
  }
}

//checks if the user input is valid
bool isValidInput(char* input){
  for(int i = 0; i < strlen(input); i++){
    if(!(isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')' || input[i] == '^')){
      return false;
    }
  }
  return true;
}

//stores user input into a char*
void getInput(char* input){
  fill(input, input + 81, ' ');
  cin.getline(input, 81);
  deleteWhitespace(input);
}

//deletes all whitespace from a char*
void deleteWhitespace(char* text){
  char* newText = text;
  while(*text != '\0'){
    if(!(*text == ' ')){
      *newText = *text;
      newText++;
    }
    text++;
  }
  *newText = '\0';
}
