#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* createNode(int value) {
    node* newNode = new node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

int maxDepth(node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth  = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}

int main() {
    
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Maximum depth of tree: " << maxDepth(root) << endl;
    return 0;
}
