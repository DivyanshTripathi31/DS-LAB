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
    if (root == nullptr) {
        return createnode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}
//byRecursion
node* searchRecursive(node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

//byIterations
node* searchIterative(node* root, int key) {
    while (root != nullptr) {
        if (root->data == key)
            return root;

        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
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

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    // Test Recursive Search
    node* res1 = searchRecursive(root, key);
    if (res1 != nullptr)
        cout << "Found (Recursive)" << endl;
    else
        cout << "Not Found (Recursive)" << endl;

    // Test Iterative Search
    node* res2 = searchIterative(root, key);
    if (res2 != nullptr)
        cout << "Found (Iterative)" << endl;
    else
        cout << "Not Found (Iterative)" << endl;

    return 0;
}
