#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newnode = new Node();
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node* insert(Node* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* findMax(Node* root) {
    while(root->right != NULL)
        root = root->right;
    return root;
}

Node* inorderPredecessor(Node* root, int key) {
    Node* predecessor = NULL;
    Node* current = root;

    while(current != NULL) {
        if(key > current->data) {
            predecessor = current;  // potential predecessor
            current = current->right;
        }
        else if(key < current->data) {
            current = current->left;
        }
        else {
            // Node found
            if(current->left != NULL) {
                return findMax(current->left);  
            }
            break; 
        }
    }
    return predecessor;
}

int main() {
    Node* root = NULL;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    int key;
    cout << "Enter key to find inorder predecessor: ";
    cin >> key;

    Node* pred = inorderPredecessor(root, key);
    if(pred != NULL)
        cout << "Inorder Predecessor of " << key << " is: " << pred->data << endl;
    else
        cout << "No inorder predecessor found for " << key << endl;
}
