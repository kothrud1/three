#include<iostream>
using namespace std;

template<class T>
class BinaryTree
{
	struct node
	{
		node *left,*right;
		T data;
	};
	struct node *root;
	struct node* newroot;
	int depthcl,depthcr;
	public:
	BinaryTree()
	{
		root = NULL;
		depthcl = 0;
		depthcr = 0;
		newroot = NULL;
	}
	
	void copyTree()
	{
		newroot = new node;
		newroot = copyTree(root,newroot);
		displayCopy();
	}
	
	bool isEmpty()
	{
		if(root==NULL)
		{
			return true;
		}
		return false;
	}

	void create(T data)
	{
		if(root==NULL)
		{
			root = new node;
			root->data = data;
			root->left = NULL;
			root->right = NULL;
		}
	}
	void insert(T data,T key)
	{

		if(root!=NULL)
		{
			node* temp = search(root,key);
			if(temp!=NULL)
			{
				node* n = new node;
				n->data = data;
				n->left = NULL;
				n->right = NULL;
				cout<<"Select the location you want to insert the data l for left and r for right"<<endl;
				char ch;
				cin>>ch;
				if(temp->left==NULL && ch=='l')
				{
					temp->left = n;
				}
				else if(temp->right==NULL && ch=='r')
				{
					temp->right = n;
				}
				else
				{
					cout<<"\nLocation Full"<<endl;
				}
			}
			else
			{
				cout<<"\nKey does not exist"<<endl;
			}
		}
	}

	void display()
	{
		cout<<endl;
		preorder(root);
		cout<<endl;
	}

	void displayLeaf()
	{
		cout<<endl;
		leaf(root);
		cout<<endl;
	}
	void depth()
	{
		depthl(root);
		depthr(root);
		if(depthcl>depthcr)
		{
			cout<<"\nDepth = "<<depthcl<<endl;
		}
		else
		{
			cout<<"\nDepth = "<<depthcr<<endl;
		}
	}

	private:
	void displayCopy()
	{
		cout<<endl;
		preorder(newroot);
		cout<<endl;
	}

	
	node* search(node *root,T key)
	{
		if(root!=NULL)
		{
			if(root->data==key)
			{
				return root;
			}
			else
			{
				node *tempA = search(root->left,key);
				node *tempB = search(root->right,key);
				if(tempA!=NULL)
				{
					return tempA;
				}
				else
				{
					return tempB;
				}

			}
		}
		else
		{
			return NULL;
		}

	}
	
	void preorder(node* root)
	{
		if(root!=NULL)
		{
			cout<<root->data<<",";
			preorder(root->left);
			preorder(root->right);
		}
	}
	
	node* copyTree(node* root,node* nroot)
	{
		if(root!=NULL)
		{
			node* tempA = new node;
			node* tempB = new node;
			nroot->data = root->data;
			nroot->left = copyTree(root->left,tempA);
			nroot->right = copyTree(root->right,tempB);
		}
		else
		{
			nroot = NULL;
		}
		return nroot;
	}
	
	void leaf(node* root)
	{
		if(root!=NULL)
		{
			if(root->left==NULL&&root->right==NULL)
			{
				cout<<root->data<<",";
			}
			else
			{
				leaf(root->left);
				leaf(root->right);
			}
		}
	}
	
	void depthl(node* root)
	{
		if(root!=NULL)
		{
			depthcl++;
			depthl(root->left);
		}
	}
	void depthr(node* root)
	{
		if(root!=NULL)
		{
			depthcr++;
			depthr(root->right);
		}
	}
};

int main()
{
	BinaryTree<int> b;
	int ch;
	int el;
	do
	{
		cout<<"1 - To create Binary Tree\n2 - To Insert Data in the tree\n3 - To copy the tree and display"<<endl;
		cout<<"4 - To calculate the depth of the tree\n5 - Display tree\n6 - To Display leaf nodes\n7 - Exit"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1: cout<<"Enter the first element of the tree = ";
				cin>>el;
				b.create(el);
				cout<<"Tree created successfuly\n"<<endl;
				break;
				
			case 2: if(!b.isEmpty())
				{
					cout<<"Enter the element of the tree = ";
					cin>>el;
					cout<<"Enter the key where you want to enter the element"<<endl;
					int key;
					cin>>key;
					b.insert(el,key);
					cout<<"Entered successfuly\n"<<endl;
				}
				else
				{
					cout<<"First create the tree\n"<<endl;
				}
				break;
				
			case 3: if(!b.isEmpty())
				{
					b.copyTree();
					cout<<"Tree copied successfuly\n"<<endl;
				}
				else
				{
					cout<<"First create the tree\n"<<endl;
				}
				break;
				
			case 4: if(!b.isEmpty())
				{
					b.depth();
				}
				else
				{
					cout<<"First create the tree\n"<<endl;
				}
				break;
				
			case 5: if(!b.isEmpty())
				{
					cout<<"\nBinary Tree\n"<<endl;
					b.display();
				}
				else
				{
					cout<<"First create the tree\n"<<endl;
				}
				break;
				
			case 6: if(!b.isEmpty())
				{
					cout<<"\nLeaf nodes\n"<<endl;
					b.displayLeaf();
				}
				else
				{
					cout<<"First create the tree\n"<<endl;
				}
				break;
				
			case 7: cout<<"\n\nThanks\n"<<endl;
				break;
				
			default: cout<<"\nWrong Option\n"<<endl;
		}
	}while(ch!=7);
}

