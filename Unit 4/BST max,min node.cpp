#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
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
int findMax(Node* root) {

    while (root->right != nullptr) {
        root = root->right;
    }

    return root->data;
}
int findMin(Node* root)
{
    while(root->left!=nullptr)
    {
        root=root->left;
    }
    return root->data;
}
Node* kthSmallest(Node* root, int& counter, int k)
{
    if (root == nullptr)
        return nullptr;
    Node* leftResult = kthSmallest(root->left, counter, k);
    if (leftResult != nullptr)
        return leftResult;
    counter++;
    if (counter == k)
        return root;

    return kthSmallest(root->right, counter, k);
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
     int maxNodeValue = findMax(root);
     cout << "Maximum node value: " << maxNodeValue << endl;
    // int minNodeValue=findMin(root);
    // cout<<"Minimum node value: "<<minNodeValue<<endl;
    // int k;
    // cout << "Enter the value of k: ";
    // cin >> k;

    // int counter = 0;
    // Node* kthSmallestNode = kthSmallest(root, counter, k);

    // if (kthSmallestNode != nullptr)
    //     cout << "The " << k << "th smallest node is: " << kthSmallestNode->data << endl;
    // else
    //     cout << "No " << k << "th smallest node found." << endl;

    return 0;
}
