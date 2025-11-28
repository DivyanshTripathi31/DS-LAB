#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node* createnode(int value) {
    node* newnode = new node();
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert
node* insert(node* root, int value) {
    if(root == NULL)
        return createnode(value);
    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Find minimum (used for deletion → inorder successor)
node* findMin(node* root) {
    while(root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete function
node* deleteNode(node* root, int key) {
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else { // Found the node to delete
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if(root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            node* successor = findMin(root->right);
            root->data = successor->data;           // Replace data
            root->right = deleteNode(root->right, successor->data);  // Delete successor
        }
    }
    return root;
}

// Inorder print (for checking)
void inorder(node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);   // delete 50

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
