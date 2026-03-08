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
void push(Node*& top, Node* n);
Node* pop(Node*& top);
Node* peek(Node* top);
//QUEUE FUNCTIONS
void enqueue(Node*& front, Node*& rear, Node* n);
Node* dequeue(Node*& front, Node*& rear);

int precedence(char op);
bool isOperator(char c);

int main () {
  return 0;
}

void push(Node*& top, Node* n) {
  n->next = top;
  top = n;
}

Node* pop(Node*& top) {
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

void enqueue(Node*& front, Node*& rear, Node* n) {
  if (rear == NULL) {
    front = rear = n;
  } 
  else {
    rear->next = n;
    rear = n;
  }
}

Node* dequeue(Node*& front, Node*& rear) {
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

//Steps to complete project:
//1.BUILD A STACK USING A LINKED LIST. You don't need a separate class for this, but you DO need the push(), pop(), and peek() functions.
//2.BUILD A QUEUE USING A LINKED LIST. You don't need a separate class for this, but you DO need the enqueue() and dequeue() functions.
//3.1 and 2 will both be in main.cpp
//4.BUILD A BINARY TREE NODE CLASS WITH A LEFT AND RIGHT POINTER. (This is very similar to the Node class for linked list, except it has a data value, left pointer, and right pointer. If you want to combine the linked list node into the binary tree node, meaning it has a left, right, AND next, you may.)
//5.most likely will do remaining tree in other classes for organization
//6.make sure all 3 contain the instructions of overview with mathematical notation, and output infix, prefix, and postfix notation
//7. MAJOR NOTE: we need to output the entire expression tree for infix, postfix, and prefix -> :( 
//8. Comments!
