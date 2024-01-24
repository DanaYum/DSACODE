#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr){}
};
void traversal(Node* ptr)
{
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
    }
};
void preorder(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int preorderSum(Node* root)
{
    if (root != NULL)
    {
        int sum=root->data;
        sum+=preorderSum(root->left);
        sum+=preorderSum(root->right);
        return sum;
    }
}
void postorder(Node* root)//
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node*  insert(Node* node, int key)
{
    if (node == NULL)
        return new Node(key);

    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }

    return node;
}
Node* search(Node* root, int target)
{
    if (root == NULL || root->data == target)
    {
        return root;
    }
    
    if (target < root->data)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

int main()
{
    Node* root = NULL;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int d;
        cout << "Enter node value: ";
        cin >> d;
        root=insert(root, d);
    }
     cout << "Inorder traversal: ";
    inorder(root);
    // cout << endl;
    // cout<<"preorder traversal: ";
    // preorder(root);
    //  cout<<endl;
    //  cout<<"postorder traversal: ";
    // postorder(root);
    // cout<<endl;
    // int sum=preorderSum(root);
    // cout<<"sum of preorder is: "<<sum;
    // int target;
    // cout<<"Enter the value to search: ";
    // cin>>target;
    
    // Node* searchTarget = search(root,target);
    
    // if(searchTarget == NULL) 
    //     cout<<"Value not found in the tree";
    //  else 
    //     cout<<"Value found in the tree";
    
    // return 0;

    // return 0;
}
