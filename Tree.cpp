#include<iostream>
using namespace std;
class Node{
	public :
	int number;
	Node *  right;
	Node * left;
	
	Node (int key){
		number=key;
		right=NULL;
		left=NULL;
	}
};
class Queuewitharray
{
private:
  int front;
  int rear;
  int size=5;
  Node *Q[5];
public:
  Queuewitharray()
{
  front = -1;
  rear = -1;
}
 void EnQueue(Node * x)
  {
    if (Isfull())
    {
      cout << "Queue is full:";
    }
    if (front == -1) 
    {
          front++;
          rear++;
          Q[front]=x;
    }
    else  
    Q[++rear] = x;
  }
  void deQueue()
  { 
  
    if (IsEmtpy()) 
    {
      cout << "Queue is empty." << endl;
      return ;
    }
    else 
    {
        for (int i = front; i < rear; ++i) {
            Q[i] = Q[i + 1];
        }
        rear--;
        if (rear < front) {
            front = rear = -1; 
        }
    }
  }
  bool Isfull()
  {
  return rear == size - 1;
  }
  bool IsEmtpy()
  {
    if(rear == -1 && front == -1)
    
	{
	return true;}
	else {
		return false;
	}
  }
  Node* getFront() {
    if (IsEmtpy()) {
      cout << "Queue is empty." << endl;
      return NULL;
    }
    else {
      return Q[front];
      
    }
  }
  
};

class BinaryTree{
	public :
	Node *root;
	BinaryTree(){
		root=NULL;
	}
    void inOrder(Node * root){
    	
    	if(root!=NULL){
    		inOrder(root->left);
    		cout<<root->number<<" ";
    		inOrder(root->right);
		}
		
	}
	 void postOrder(Node * root){
    	
    	if(root!=NULL){
    		postOrder(root->left);
    		postOrder(root->right);
    		cout<<root->number<<" ";
    		
		}
		
	}
	void preOrder(Node * root){
    	
    	if(root!=NULL){
    		cout<<root->number<<" ";
    		preOrder(root->left);
    		preOrder(root->right);
    		
    		
		}
	
	}
	/*void assignvalues(Node * curr){
		if(root->left!=NULL){
			curr->left=root->left;
		}
		if(root->right!=NULL){
			curr->right=root->right;
		}
	}*/
	void levelwise(Node * root){
		if(root==NULL){
			cout<<"Nothing in Tree "<<endl;
			return;
		}
		 Queuewitharray q;
	     q.EnQueue(root);
		while(q.IsEmtpy()==false){
			Node* curr = q.getFront();
			q.deQueue();
			
			cout<<curr->number<<" ";
			/*assignvalues(curr);*/
			if(curr->left!=NULL){
				q.EnQueue(curr->left);
			}
			if(curr->right!=NULL){
				q.EnQueue(curr->right);
			}
		}
	}
};

int main (){
	BinaryTree bt;
	bt.root = new Node(10);
	bt.root->left = new Node(20);
	bt.root->right=new Node(30);
		bt.root->left->left = new Node(40);
		bt.root->left->right=new Node(50);
		cout<<"In Order of tree ";
	bt.inOrder(bt.root);
	cout<<endl;
	cout<<"Pre Order of tree ";
	bt.preOrder(bt.root);
	cout<<endl;
	cout<<"Post Order of tree ";
	bt.postOrder(bt.root);
	cout<<endl;
	cout<<"Level wise ";
	bt.levelwise(bt.root);
	return 0;
}
