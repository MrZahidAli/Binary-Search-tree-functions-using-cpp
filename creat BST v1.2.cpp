//(BST) Binary search tree using linked list

#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *left, *right, *previous;
};
class linkList{
	public:
		node *root;
	public:
		linkList(){
			root = NULL;
		}
//creating BST
		void creatList(int value){
			node *temp = new node;
			node *copyRoot = root;
			temp -> data = value;
			temp -> left = NULL;
			temp -> right = NULL;
			if(root == NULL){
				root = temp;
				copyRoot = temp;
			}
			else{
				while(copyRoot != NULL ){
					if(temp -> data < copyRoot -> data){
						if(copyRoot -> left == NULL){
							copyRoot -> left = temp;
							temp -> previous = copyRoot;
							return;
						}else{
							copyRoot = copyRoot -> left;
						}
					}else{
						if(copyRoot -> right == NULL){
							copyRoot -> right = temp;
							temp -> previous = copyRoot;
							return;
						}else{
							copyRoot = copyRoot -> right;
						}
					}
				}
			}
			
		}
//printing BST in inorder
		void printInorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				cout << temp -> data;
				printInorder(temp -> right);
			}
		}
//printing BST in postorder
		void printPostorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				printInorder(temp -> right);
				cout << temp -> data;
			}
		}
//printing BST in preorder
		void printPreorder(node *temp){
			if(temp != NULL){
				cout << temp -> data;
				printInorder(temp -> left);
				printInorder(temp -> right);
			}
		}
//finding minimum in BST
		node *minimum(node *temp){
			if(temp == NULL){
				return 0;
			}else if(temp -> left == NULL){
				cout << endl << "minimum in BST: " << temp -> data;
				return temp;
			}else{
				minimum(temp -> left);
			}
			
		}
//finding maximum in BST
		node *maximum(node* temp){
			if(temp == NULL){
				return 0;
			}else if(temp -> right == NULL){
				cout << endl << "maximum in BST: " << temp -> data;
				return temp;
			}else{
				maximum(temp -> right);
			}
		}
//search in BST
		int search(int value, node *temp){
			if(temp == NULL){
				cout << endl << "Value is not found in BST!";
				return 0;
			}else if(value == temp -> data){
				cout << endl << "value is found that is: " << temp -> data;
				return 0;
			}else{
				if(value < temp -> data){
					search(value, temp -> left);
				}else{
					search(value, temp -> right);
				}
			}
			
		}
//successor of an element in BST

void inordersuccessor(node* temp) 
{
    // Case1: If right child is not NULL 
    if (temp->right != NULL) 
    { 
        node *inorderSucc = minimum(temp->right); 
        cout<<"Inorder Successor of "<<temp->data<<" is "; 
        cout<<inorderSucc->data<<"\n"; 
    } 
  
    // Case2: If right child is NULL 
    if (temp->right == NULL){
		while( temp -> previous -> data < temp -> data){
			temp = temp -> previous;
		}
		cout << "successor is: "<<temp -> data;
    }
}

		int successor(int value, node* temp){
			if(temp == NULL){
				cout << endl << "Value is not found in BST!";
				return 0;
			}else if(value == temp -> data){
				inordersuccessor(temp);
			}else{
				if(value < temp -> data){
					successor(value, temp -> left);
				}else{
					successor(value, temp -> right);
				}
			}
		}
};
int main(){
	linkList B;
	B.creatList(1);
	B.creatList(2);
	B.creatList(3);
	B.creatList(4);
	B.creatList(5);
	B.creatList(6);
	B.creatList(7);
	B.creatList(8);
	cout << endl << "inorder list: ";
	B.printInorder(B.root);
	cout << endl << "postorder list: ";
	B.printPostorder(B.root);
	cout << endl << "preorder list: ";
	B.printPreorder(B.root);
//	B.minimum(B.root);
//	B.maximum(B.root);
//	B.search(1, B.root);
//	B.successor(3, B.root);
//	B.test();
	return 0;
}
