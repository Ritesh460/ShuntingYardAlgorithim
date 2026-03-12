#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
//compared to other projects, doing 1 file to see if this a system I can do otherwise by next project I'll revert back to working on multiple files
// Node class
class Node {
public:
  char data;
  Node* next;
  Node* left;
  Node* right;

  Node(char d) {
    data = d;
    next = NULL;
    left = NULL;
    right = NULL;
  }
};
//STACK FUNCTIONS
void push(Node* &top, Node* n);
Node* pop(Node* &top);
Node* peek(Node* top);
//QUEUE FUNCTIONS
void enqueue(Node* &front, Node* &rear, Node* n);
Node* dequeue(Node* &front, Node* &rear);

int precedence(char op);
bool isOperator(char c);

int main () {
  return 0;
}

void push(Node* &top, Node* n) {
  n->next = top;
  top = n;
}

Node* pop(Node* &top) {
  if (top == NULL) {
    return NULL;
  }
  Node* temp = top;
  top = top->next;
  temp->next = NULL;
  return temp;
}

Node* peek(Node* top) {
  return top;
}

void enqueue(Node* &front, Node* &rear, Node* n) {
  if (rear == NULL) {
    front = rear = n;
  } 
  else {
    rear->next = n;
    rear = n;
  }
}

Node* dequeue(Node* &front, Node* &rear) {
  if (front == NULL) {
    return NULL;
  }

  Node* temp = front;
  front = front->next;

  if (front == NULL) {
    rear = NULL;
  }

  temp->next = NULL;
  return temp;
}

int precedence(char op) {
  if (op == '^') {
    return 3;
  }
  if (op == '*' || op == '/') {
    return 2;
  }
  if (op == '+' || op == '-') {
    return 1;
  }
  return 0;
}

bool isOperator(char c) {
  return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

Node* shuntingYard(char input[]) {
  Node* stack = NULL;
  Node* front = NULL;
  Node* rear = NULL;

  for (int i = 0; i < strlen(input); i++) {
    char c = input[i];
    if (c == ' ') {
      continue;
    }
    //if digit
    if (isdigit(c)) {
      enqueue(front, rear, new Node(c));
    }
    //if operator
    else if (isOperator(c)) {
      while (stack != NULL && precedence(peek(stack)->data) >= precedence(c)) {
        enqueue(front, rear, pop(stack));
      }
      push(stack, new Node(c));
    }
    //left parenthesis
    else if (c == '(') {
      push(stack, new Node(c));
    }
    //right parenthesis
    else if (c == ')') {
      while (peek(stack)->data != '(') {
        enqueue(front, rear, pop(stack));
      }
      pop(stack); 
    }


  //movves remaining operators
  while (stack != NULL) {
    enqueue(front, rear, pop(stack));
  }
  return front;
}

Node* buildTree(Node* postfix) {
  Node* stack = NULL;
  while (postfix != NULL) {
    Node* current = postfix;
    postfix = postfix->next;
    current->next = NULL;
    //if number push to stack
    if (isdigit(current->data)) {
      push(stack, current);
    }
    //if operator create subtree
    else if (isOperator(current->data)) {
      Node* right = pop(stack);
      Node* left = pop(stack);
      current->left = left;
      current->right = right;
      push(stack, current);
      }
  }
  return pop(stack); 
}

//Goal: finish infix, prefix, and postfix before FRIDAY

//void printPrefix(Node* root)
//void printInfix(Node* root)
//void printPostfix(Node* root)
//Steps to complete project:
//1.BUILD A STACK USING A LINKED LIST. You don't need a separate class for this, but you DO need the push(), pop(), and peek() functions.
//2.BUILD A QUEUE USING A LINKED LIST. You don't need a separate class for this, but you DO need the enqueue() and dequeue() functions.
//3.1 and 2 will both be in main.cpp
//4.BUILD A BINARY TREE NODE CLASS WITH A LEFT AND RIGHT POINTER. (This is very similar to the Node class for linked list, except it has a data value, left pointer, and right pointer. If you want to combine the linked list node into the binary tree node, meaning it has a left, right, AND next, you may.)
//5.most likely will do remaining tree in other classes for organization
//6.make sure all 3 contain the instructions of overview with mathematical notation, and output infix, prefix, and postfix notation
//7. MAJOR NOTE: we need to output the entire expression tree for infix, postfix, and prefix -> :( 
//8. Comments!
