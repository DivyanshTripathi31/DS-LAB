#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* createNode(int value) {
    node* newnode = new node();
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

node* insert(node* root, int value) {
    if(root == NULL) return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

int minDepth(node* root) {
    if(root == NULL)
        return 0;

    if(root->left == NULL)
        return 1 + minDepth(root->right);

    if(root->right == NULL)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
    node* root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 15);
    insert(root, 18);

    cout << "Minimum Depth of BST: " << minDepth(root) << endl;
    return 0;
}
