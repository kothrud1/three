#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
class BST
 {
   public:
   void insert(node*,node*);
   void remove(node*,int);
   void search(node*,int);
   void minimum(node*);
   void maximum(node*);
   void display(node*);
 };
void BST::insert(struct node *root,struct node *nn)
 {
  if(root->data>nn->data)
   {
	if(root->left!=NULL)
          insert(root->left,nn);
        else 
          root->left=nn;
   }   
  else
   if(root->right!=NULL)
          insert(root->right,nn);
        else 
          root->right=nn;
 }
 void BST::display(struct node *root)
 {
   if(root!=NULL)
    {
      display(root->left);
      cout<<root->data<<",";
      display(root->right);
 
    }
}
 void BST::search(struct node *root,int key)
 {
   struct node *temp=root;
   while(temp!=NULL)
   {
      if(temp->data>key)
        temp=temp->left;
      else 
        if(temp->data<key)
          temp=temp->right;
        else
         {
           cout<<"\nKey found\n";
           break;
        }

 }
  if(temp==NULL)
  cout<<"\tKey not found\t";
}

 void BST::minimum(struct node *root)
 { 
   if(root->left!=NULL)
   minimum(root->left);
    else
   cout<<root->data;
 
 }

 void BST::maximum(struct node *root)
 { 
   if(root->right!=NULL)
   maximum(root->right);
    else
   cout<<root->data;
 }

 void BST::remove(struct node *root,int key)
 {
  struct node *temp=root;
  struct node *temp1,*del;
  int flag=1;
  char ch;
  while(temp!=NULL)
 {
   if(temp->data>key)
   {
 	temp1=temp;
	temp=temp->left;
	ch='1';
   }
  else
    if(temp->data<key)
     {  
        temp1=temp;
        temp=temp->right;
        ch='r';
     }
  else
    if(temp->data==key)
     {
       if(ch=='1')
       {
          if(temp->left==NULL&&temp->right==NULL)
           temp1->left=NULL;
          else if(temp->left==NULL)
            temp1->left=temp->right;
           else if(temp->right==NULL)
             temp1->left==temp->left;
            else
              {
		temp1->left=temp->left;
                 insert(root,temp->right);

              }
       }
   else 
     { 
        if(temp->left==NULL&&temp->right==NULL)  
          temp1->right=NULL;
        else if(temp->right==NULL)
          temp1->right=temp->right;
        else if(temp->right==NULL)
           temp->right==temp->left;
            else
             {
                temp1->right=temp->left;
                insert(root,temp->right);

             }     
      } 
     delete(temp);
     flag=0;
     display(root);
    }
 }
 if(flag==1)
 cout<<"\nKey not found.\n";
}
 int main()
  {
    int ch,a,key;
    struct node *root=NULL,*nn;
     BST tree; 
    do
     {
        cout<<"\n1) Insert key\t 2) delete key \t 3) Display tree \t4) Search key\t 5) Minimum key \t 6) Maximum key\t 7) Exit:\n";
        cout<<"\nEnter ur choice:\n";
        cin>>ch;
       switch(ch)
       {
	case 1:
	  nn=new node;
          cout<<"\nEnter key\t";
          cin>>nn->data;
          nn->left=nn->right=NULL;
           if(root==NULL) 
              root=nn;
           else
            tree.insert(root,nn);
        break;

         case 2:
		cout<<"\nEnter Key:\t";
                 cin>>key;
                tree.remove(root,key);

         break;
         case 3:
		cout<<"\nBinary search tree:\n";
		tree.display(root);
	 break;

          break;
          case 4:
		cout<<"\nEnter Key:\t";
		cin>>key;        
		if(root!=NULL)
 		 {
			tree.search(root,key);
		  }
		else
 		  cout<<"\nTree is empty.\n";
          break;
          case 5:
		if(root!=NULL)
 		 {
		  cout<<"\nMinimum key is:\n";
		   tree.minimum(root);
		 }
		else 
 		  cout<<"\nTree is empty.\n";
           break;
           case 6:
                if(root!=NULL)
 		  {
		  cout<<"\nMaximum key is:\n";
		   tree.maximum(root);
		 }
		else 
 		  cout<<"\nTree is empty.\n";		  

	   break;
	   case 7:
              
  	   break;
             default:
                cout<<"\nWrong choice entered. Try again....\n";
             break;
          }
     }while(ch!=7);
  return 0;
}

