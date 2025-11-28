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
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert in BST
node* insert(node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

int findMin(node* root) {
    if(root == NULL) {
        cout << "Tree is empty!";
        return -1;
    }

    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int main() {
    node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 2);
    root = insert(root, 7);

    cout << "Minimum element in BST = " << findMin(root);

    return 0;
}
