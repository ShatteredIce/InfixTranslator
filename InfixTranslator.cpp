#include <iostream>
#include <string.h>
#include "Node.h"

using namespace std;

void getInput(char* input);
bool isInfix(char* input);
void deleteWhitespace(char* input);

int main(){

  Node* head = NULL;
  bool running = true;
  char input[81];
  char validChars[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*', '/', '(', ')'};

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
    else if(isInfix(input)){
      cout << "valid\n";
    }
    else{
      cout << "invalid\n";
    }
  }
  
  return 0;
}

//checks if the user input is valid
bool isInfix(char* input){
  for(int i = 0; i < strlen(input); i++){
    if(!(isdigit(input[i]) || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')')){
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

