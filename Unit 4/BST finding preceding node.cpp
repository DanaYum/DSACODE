#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* findPrecedingNode(Node* root, int target, Node* &precedingNode) {
    if (root == nullptr)
        return nullptr;

    // Traverse the left subtree
    Node* leftResult = findPrecedingNode(root->left, target, precedingNode);
    if (leftResult != nullptr)
        return leftResult;

    // Check the current node
    if (root->data == target)
        return precedingNode;

    // Update the precedingNode if the current node is less than the target
    if (root->data < target)
        precedingNode = root;

    // Traverse the right subtree
    return findPrecedingNode(root->right, target, precedingNode);
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->data) {
        node->left = insert(node->left, key);
    } else if (key > node->data) {
        node->right = insert(node->right, key);
    }

    return node;
}

int main() {
    Node* root = nullptr;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        cout << "Enter node value: ";
        cin >> d;
        root = insert(root, d);
    }

    int target;
    cout << "Enter the target number: ";
    cin >> target;

    Node* precedingNode = nullptr;
    Node* resultNode = findPrecedingNode(root, target, precedingNode);

    if (resultNode == nullptr) {
        cout << "Target number not found in the tree." << endl;
    } else {
        cout << "The preceding node before " << target << " in inorder traversal is: " << resultNode->data << endl;
    }

    return 0;
}
