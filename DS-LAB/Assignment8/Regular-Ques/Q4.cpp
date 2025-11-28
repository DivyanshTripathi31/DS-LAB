#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool isBST(Node* root, int min, int max) {
    if (root == NULL) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "BST";
    else
        cout << "Not BST";
}