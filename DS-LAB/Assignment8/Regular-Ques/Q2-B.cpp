#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};
node* createnode(int value) {
    node* newnode = new node();
    newnode->data = value;
    newnode->left = newnode->right = nullptr;
    return newnode;
}
node* insert(node* root, int value) {
    if (root == nullptr)
        return createnode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
//byIteration
node* findMaxIterative(node* root) {
    if (root == nullptr) return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;   // rightmost node
}

//byRecursion
node* findMaxRecursive(node* root) {
    if (root == nullptr) return nullptr;

    if (root->right == nullptr)
        return root;   // this is the max node

    return findMaxRecursive(root->right);
}

int main() {
    node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    node* maxNode1 = findMaxIterative(root);
    if (maxNode1)
        cout << "Maximum (Iterative): " << maxNode1->data << endl;

    node* maxNode2 = findMaxRecursive(root);
    if (maxNode2)
        cout << "Maximum (Recursive): " << maxNode2->data << endl;

    return 0;
}
