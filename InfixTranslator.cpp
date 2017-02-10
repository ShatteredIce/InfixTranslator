#include <iostream>
#include <string.h>
#include "Node.h"

using namespace std;

void getInput(char* input);
bool isValidInput(char* input);
void deleteWhitespace(char* input);

int main(){

  Node* inputHead = NULL;
  Node* operatorHead = NULL;
  Node* outputHead
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
    else if(isValidInput(input)){
      head = new Node(input[0]);
      temp = head;
      for(int i = 1; i < strlen(input); i++){
        temp.setNext(new Node(input[i]));
        temp = temp.getNext();
      }

  }

  return 0;
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
