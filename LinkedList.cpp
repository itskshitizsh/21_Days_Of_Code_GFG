#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* newNode(int value){
	Node* node = new Node();
	node->data = value;
	node->next = null;
	return node;
}

Node* insert(Node* start, int value){
	if(start==NULL){
		start = newNode(value);
	}else{
		Node *temp = newNode(value);
		Node * head = start;
		while(head->next!=null){
			head = head->next;
		}
		head->next = temp;
	}
	return start;
}

void printLL(Node* start){
	Node* current = start;
	while(current!=NULL){
		cout << " " << current->data;
		current = current->next;	
	}
}

bool findDataInLL(Node* start,int value){
	Node* current = start;
	while(current!=NULL){
		if(current->next == value){
			return true;
		}
		current = current->next;	
	}
	return false;
}

Node* deleteFromLL(Node* start, int value){
	if(start==NULL){
		return start;
	}else{
		if(start->data==value){
			return start->next;
		}else{
		Node* current = start;
		Node* previous = current;
		while(current!=NULL){
			if(current->data==value){
				// if(previous!=current)
				previous->next = current->next;
				current->next = NULL;
				free(current);
				return start;
			}
			previous = current;
			current = current->next;
		}
		}
	}
}

int main(){
	
	return 0;
}