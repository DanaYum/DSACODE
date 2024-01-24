#include<iostream>
using namespace std;

class node
{
    public:
    node *left;
    int data;
    node *right;
};

node *root;
class BST
{
    public:
     
     BST()
     {
         root=NULL;
     }
     void insert_Node(int );
     void inorder(node *);
     void postorder(node *);
     void preorder(node *);
     node* search(int k);
     node* search_rec(node *,int k);
};
node* BST::search_rec(node *t,int k){
    if(t==NULL||t->data==k){
        return t;
    }
    else{
        if(t->data<k){
            search_rec(t->right,k);
        }
        else{
            search_rec(t->left,k);
        }
    }
}
node* BST::search(int k){
    node *t=root;
    while(t){
        if(t->data==k){
            return t;
        }
        else{
            if(k<t->data){
                t=t->left;
            }
            else{
                t=t->right;
            }
        }
    }
    return t;
}
void BST::preorder(node *tra){
    if(tra!=NULL){
        cout<<tra->data<<" ";
        preorder(tra->left);
        preorder(tra->right);
    }
}
void BST::postorder(node *tra){
    if(tra!=NULL){
        postorder(tra->left);
        postorder(tra->right);
        cout<<tra->data<<" ";
    }
}
void BST::inorder(node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
void BST ::insert_Node(int d)
{
    node *temp=new node;
    
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        node *cur=root;
        node *pre=NULL;
        while(cur!=NULL)
        {
            pre=cur;
            if( d < cur->data)
                cur=cur->left;
             else
                cur=cur->right;
        }
       if( d < pre->data)
          {
              pre->left=temp;
          }
          else
          {
              pre->right=temp;
          }
        
    }
}
int main()
{
   BST b;
   node *p=NULL;
   int n;
   cin>>n;
   
   for(int i=0;i<n;i++)
   {  int d;
        cin>>d;
        b.insert_Node(d);
   }
//    b.inorder(root);
//    cout<<endl;
//    b.preorder(root);
//    cout<<endl;
//    b.postorder(root);
   int key;
   cin>>key;
//   p=b.search(key);
   p=b.search_rec(root,key);
   if(p==NULL){
       cout<<"\nData Not Found\n";
   }
   else{
       cout<<"\nData Found\n";
   }
}