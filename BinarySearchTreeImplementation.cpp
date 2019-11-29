#include <bits/stdc++.h>

using namespace std;

struct Node{
	int value;
	Node *left;
	Node *right;
	
	Node(int val){
		value = val;
		left = NULL;
		right = NULL;
	}
};
Node *root = NULL;

void insert(int val){
	Node *nd = new Node(val);
	if(root==NULL){
		root = nd;
	}else{
		Node* current = root;
		while(current->left!=NULL || current->right!=NULL){
			
			if(current->value < val){
				if(current->right==NULL){
					current->right = nd;
					return;
				}
				current = current->right;
			}
			else{
				if(current->left==NULL){
					current->left = nd;
					return;
				}
				current = current->left;
			}
		}
    if(current->value < val){
        current->right = nd;
    }else{
      current->left = nd;
    }
	}
}

void inorder(Node* hd){
  if(hd==NULL){
    return;
  }else{
    inorder(hd->left);
    cout << hd->value << " ";
    inorder(hd->right);
  }
}

void bfs(Node *r){
	queue <Node*> q;
	q.push(r);
	while(!q.empty()){
		Node *temp = q.front();
    q.pop();
    if(temp!=NULL)
	{	  
    cout << temp->value <<" ";
	  q.push(NULL);
  }else{
      cout << "\n";
      continue;
    }
  if(temp->left!=NULL)
		q.push(temp->left);
	if(temp->right!=NULL)
  	q.push(temp->right);
	}
}

int findMin(Node* r){
	if(r==NULL){
		cout << "Empty Binary Search Tree" <<endl;
		return -1;
	}else{
		while(r->left!=NULL){
			r = r->left;
		}
		return r->value;
	}
}

Node* search(int value){
	Node *current = root;
	while(current!=NULL){	
		if(current->value == value){
			return current;
		}else{
			if(current->value > value){
				current = current->left;
			}else{
				current = current->right;
			}
		}
	}
	cout << value <<" Not Present in BST" <<endl;
	return NULL;
}
/* Delete doesn't work correctly. */
void delete(int value){
	Node *current = root;
	Node *parent = root;
	while(current!=NULL){	
	if(current->value == value){
		break;
	}else{
		if(current->value > value){
			parent = current;
			current = current->left;
		}else{
			parent = current;
			current = current->right;
		}
	}
	}
	if(current==NULL){
		cout << "Value is not present in bst";
		return;
	}
	// Leaf node
	if(current->left==NULL && current->right ==NULL){
		if(parent==current){ // Single element in BST
			root = NULL;
		}
		if(parent->value < value){
			parent->right = NULL;
		}else{
			parent->left = NULL;
		}
		return;
	}
	// one child
	if(current->left==NULL){
		current = current->right->value;
		current->right = current->right->right;
	}
	if(current->right ==NULL){
		if(parent->value < value){
			parent->right = NULL;
		}else{
			parent->left = NULL;
		}
	}
}

int main() {
  insert(10);
  insert(5);
  insert(15);
  insert(7);
  
  cout << "Inorder: \n";
  inorder(root);
  
  cout << "\nBFS: \n";
  bfs(root);

  cout << "\nMinimum Number : ";
  cout << findMin(root);

	Node *temp0 = search(25);
	if(temp0!=NULL){
		cout << "Found Search";
	}
	temp0 = search(225);
	if(temp0!=NULL){
		cout << "Found Search";
	}
	
	delete(1);
	delete(25);
	delete(10);
	inorder(root);
  return 0;
}