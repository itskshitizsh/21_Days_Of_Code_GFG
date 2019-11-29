#include <bits/stdc++.h>

using namespace std;

class Stack{
	public:
		int top;
		int arr[100];
	Stack(){
		top = -1;
	}
	void push(int data){
		if(top<99)
			arr[++top] = data;
		else
			cout << "Stack Overflow :P" << endl;
	}
	void pop(){
		if(top<0){
			cout << "Stack Underflow" << endl;
			return;
		}else{
			top--;
		}
	}
	int topElement(){
	if(!isEmpty()){
		return arr[top];
	}else{
		cout << "Empty Stack\n";
		return -1;
	}
	}
	bool isEmpty(){
		if(top<0){
			return true;
		}else{
			return false;
		}
	}
	void printStack(){
	for(int i=top;i>=0;i--){
		cout << arr[i] <<" ";
	}
	cout << endl;
	}

};

int main(){
	Stack *stk = new Stack();
	stk->push(1);
	stk->push(2);
  	stk->push(3);
  	stk->push(4);
  	stk->push(5);
	stk->pop();
	cout << stk->topElement()<<endl;
	stk->push(6);
  	stk->push(7);
	stk->printStack();
	return 0;
}