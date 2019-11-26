//(BST) Binary search tree using linked list

// 1- creating BST
// 2- printing BST -inorder, preorder, postorder
// 3- maximum in BST
// 4- minimum in BST
// 5- search in BST
// 6- successor in BST
// 7- predeccessor in BST
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
// 1- creating BST
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
// 2- printing BST in inorder
		void printInorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				cout << temp -> data;
				printInorder(temp -> right);
			}
		}
// 2- printing BST in postorder
		void printPostorder(node *temp){
			if(temp != NULL){
				printInorder(temp -> left);
				printInorder(temp -> right);
				cout << temp -> data;
			}
		}
// 2- printing BST in preorder
		void printPreorder(node *temp){
			if(temp != NULL){
				cout << temp -> data;
				printInorder(temp -> left);
				printInorder(temp -> right);
			}
		}
// 3- finding minimum in BST
		node *minimum(node *temp){
			if(temp == NULL){
				return 0;
			}else if(temp -> left == NULL){
				//cout << endl << "minimum in BST: " << temp -> data;
				return temp;
			}else{
				minimum(temp -> left);
			}
			
		}
// 4- finding maximum in BST
		node *maximum(node* temp){
			if(temp == NULL){
				return 0;
			}else if(temp -> right == NULL){
				//cout << endl << "maximum in BST: " << temp -> data << endl;
				return temp;
			}else{
				maximum(temp -> right);
			}
		}
// 5- search in BST
		int search(int value, node *temp){
			if(temp == NULL){
				cout << endl << "Value is not found in BST!";
				return 0;
			}else if(value == temp -> data){
				cout << endl << "value is found that is: " << temp -> data << endl;
				return 0;
			}else{
				if(value < temp -> data){
					search(value, temp -> left);
				}else{
					search(value, temp -> right);
				}
			}
			
		}
// 6- successor of an element in BST

	void inordersuccessor(node* temp) {
		if (temp->right != NULL){ 
			node *inorderSucc = minimum(temp->right); 
     	   	cout<<"Inorder Successor of "<<temp->data<<" is "; 
       		cout<<inorderSucc->data<<"\n"; 
    	} 
    	if (temp->right == NULL){
			while( temp -> previous -> data < temp -> data){
				temp = temp -> previous;
			}
			cout << endl << "successor is: " << temp -> previous -> data;
   		}
	}

	int successor(int value, node* temp){
		node *max = maximum(root);
		if(max -> data == value){
			cout << endl << "! Value is maximum so successor does not exist" << endl;
			return 0;
		}
		if(temp == NULL){
			cout << endl << "Value is not found in BST!" << endl;
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
	
// 7- Predessor of an element in BST

	void inorderPredessor(node *temp){
		if(temp -> left != NULL){
			node *pre = maximum(temp -> left);
			cout << endl << "Predessor is:.. " << pre -> data << endl;
		}else{
			while(temp -> previous -> data > temp -> data){
				temp = temp -> previous;
			}
			cout << endl << "Predessor is: " << temp -> previous -> data << endl;
		}
	}
	
	int predessor(int value, node *temp){
		node *min = minimum(root);
		if(min -> data == value){
			cout << endl << endl << "Value is minimum so predecessor does not exist" << endl;
			return 0;
		}
		if(temp == NULL){
			cout << "endl" << "value is not found" << endl;
			return 0;
		}else if(temp -> data == value){
			inorderPredessor(temp);
		}else{
			if(value < temp -> data){
				predessor(value, temp -> left);
			}else{
				predessor(value, temp -> right);
			}
		}
	}
};
int main(){
	linkList B;
	B.creatList(5);
	B.creatList(3);
	B.creatList(7);
	B.creatList(1);
	B.creatList(4);
	B.creatList(0);
//	B.creatList(7);
//	B.creatList(8);
	cout << endl << "inorder list: ";
	B.printInorder(B.root);
	cout << endl << "postorder list: ";
	B.printPostorder(B.root);
	cout << endl << "preorder list: ";
	B.printPreorder(B.root);
//	B.minimum(B.root);
//	B.maximum(B.root);
//	B.search(1, B.root);
//	B.successor(0, B.root);
//	B.test();
	B.predessor(7, B.root);
	return 0;
}
