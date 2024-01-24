// You are using GCC
#include<iostream>
using namespace std;
class node
{
    public:
    node *left;
    int data;
    node *right;
};
node* root;
class BST
{
    public:
    //node* root;
    BST()
    {
        root=NULL;
    }
    void insert_Node(int);
    void inorder(node*);
    void preorder(node*);
    void postorder(node*);
};
void BST::preorder(node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
void BST::postorder(node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->data<<" ";
        
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
void BST::insert_Node(int d)
{
    node *temp=new node;
    temp->left=NULL;
    temp->right=NULL;
    temp->data=d;
    if(root==NULL)
    {
        root=temp;
        cout<<"Root: "<<root->data<<endl;
    }
    else
    {
        //cout<<"It is child node"<<temp->data<<endl;
        node * cur=root;
        node *pre=NULL;
        while(cur!=NULL)
        {
            pre=cur;
            if(d < cur->data)
                cur=cur->left;
            else
                cur=cur->right;
            
        }
        if(d<pre->data)
        {
            pre->left=temp;
            cout<<d<<" inserted at left of "<<pre->data<<endl;
        }
        else
        {
            pre->right=temp;
            cout<<d<<" inserted at right of "<<pre->data<<endl;
        }
    }
}
int main()
{
    BST b;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        b.insert_Node(d);
    }
    // cout<<"         inorder         "<<endl;
    // b.inorder(root);
    // cout<<"\n         preorder         "<<endl;
    // b.preorder(root);
    // cout<<"\n        postorder         "<<endl;
    // b.postorder(root);
    
}

