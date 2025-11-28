#include<iostream>
using namespace std;

struct node{
    int data;
    node*left;
    node*right;
};

node* createnode(int value)
{
    node* newnode=new node();
    newnode->data=value;
    newnode->left=newnode->right=nullptr;
    return newnode;
}

void preorder(node* root)
{
    if(root!=nullptr)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root)
{
    if(root!=nullptr)
    {
        
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(node* root)
{
    if(root!=nullptr)
    {
        
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    node* root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->left=createnode(4);
    root->left->right=createnode(5);

    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;

    cout<<"postorder traversal: ";
    postorder(root);
    cout<<endl;
}
