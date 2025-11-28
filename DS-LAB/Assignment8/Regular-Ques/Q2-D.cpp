#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if(root == NULL) return createNode(value);

    if(value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

Node* findMin(Node* root) {
    while(root && root->left != NULL)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, int key) {
    Node* successor = NULL;
    Node* current = root;

    while(current != NULL) {
        if(key < current->data) {
            successor = current;     // Potential successor
            current = current->left;
        }
        else if(key > current->data) {
            current = current->right;
        }
        else {
            // Node found
            if(current->right != NULL) {
                return findMin(current->right);   // Case 1
            }
            break;   // Case 2 → successor already stored
        }
    }

    return successor;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 20);
    root = insertNode(root, 8);
    root = insertNode(root, 22);
    root = insertNode(root, 4);
    root = insertNode(root, 12);
    root = insertNode(root, 10);
    root = insertNode(root, 14);

    int key = 10;
    Node* ans = inorderSuccessor(root, key);

    if(ans != NULL)
        cout << "Inorder Successor of " << key << " is " << ans->data;
    else
        cout << "No Inorder Successor exists for " << key;

    return 0;
}
