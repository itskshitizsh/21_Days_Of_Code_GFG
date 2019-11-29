#include <bits/stdc++.h>

using namespace std;

// Implementing Stack using LinkedList

struct Node {
	int data;
	Node* next;
};

Node* stackTop = NULL;

Node* newStack(int data){
	Node* node = new Node();
	node-> data = data;
	node->next = NULL;
	return node;
}

void push(int data){
	Node *node = newStack(data);
	if(stackTop==NULL){
		stackTop = node;
	}else{
		node->next = stackTop;
		stackTop = node;
	}
}

bool pop(){
	if(stackTop!=NULL){
		stackTop = stackTop->next;
    return true;
	}else{
    cout << "Empty Stack" << "\n";
    return false;
  }
}

int top(){
	return stackTop->data;
}

void printStack(){
  Node* current = stackTop;
  while(current!=NULL){
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int main(){
	
	stackTop = newStack(1);
	push(2);
	push(3);
	pop();
	cout << top() << "\n";
  printStack();
	return 0;
}