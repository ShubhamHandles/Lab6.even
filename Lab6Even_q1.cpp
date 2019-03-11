/*
Implement Binary Search Tree
1. insert()
2. display()
3. search()
*/

#include<iostream>
using namespace std;

class Node{
	
public:	
	//components
	int data;
	Node* left;
	Node* right;
	
	//default constructor
	Node(int value){
		left=NULL;
		right=NULL;
		data=value;
	}
};

class BiST{
	
public:	
	//component
	Node* root;
	//default const
	BiST(){
		root=NULL;
	}
	//Rules of structure:
	//insert()
	void insert(int value){
		insert2(root,value);
	}
	void insert2(Node* curr, int value){
		//base case if root is NULL
		if(root==NULL){
			root = new Node(value);
		}
		//Else compare the curr data with value
		else if(value<curr->data){
			//If left is null, insert it.
			if(curr->left==NULL) curr->left = new Node(value); 
			//else move left by calling insert2
			else insert2(curr->left, value);
		}
		else{
			//If right is null, insert it.
			if(curr->right==NULL) curr->right = new Node(value); 
			//else move right by calling insert2
			else insert2(curr->right, value);
		}
	}
	
	//display()
	void display(){
		display2(root);
	}
	void display2(Node* curr){
		//Base condition
		if(curr==NULL) return;
		//display left
		display2(curr->left);
		//Display current
		cout << curr->data <<",";
		//display right
		display2(curr->right);
	}
	//search()
	Node* search(int value){
		search2(value, root);
	}
	Node* search2(int value, Node* curr){
		//match
		if(value==curr->data) return curr;
		//smaller
		else if(value<curr->data) return search2(value,curr->left);
		//greater
		else if(value>curr->data) return search2(value,curr->right);
		//not found
		else{
			return NULL;
		}
	}

};

int main(){
	BiST t1;
	
	t1.insert(10);
	t1.insert(13);
	t1.insert(5);
	t1.insert(3);
	t1.insert(9);
	t1.insert(12);
	t1.insert(14);
	t1.insert(3);
	
	t1.display();
	
	if(t1.search(3) != NULL){
        cout << endl << t1.search(3)->data << " is present in the tree." << endl;
    }
    
	return 0;
}
