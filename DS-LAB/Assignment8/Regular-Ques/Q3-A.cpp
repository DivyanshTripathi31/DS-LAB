#include<iostream>
using namespace std;

struct node
{
int data;
node*left;
node*right;
};

node*createnode(int value)
{
    node *newnode=new node();
    newnode->data=value;
    newnode->left=newnode->right=nullptr;
    return newnode;
}

node* insert(node* root,int value)
{
    if(root==nullptr)
    {
        return createnode(value);

    }
    if(value==root->data)
    {
        cout<<"Duplicate : "<<value;
        return root;
    }
    if(value<root->data)
    {
        root->left=insert(root->left,value);
    }
    else{
        root->right=insert(root->right,value);
    }
    return root;

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

int main()
{
    node* root=nullptr;
    int n, value;

    cout<<"Enter no of element:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Value "<<i+ 1<<":\n";
        root=insert(root,value);
    }
    cout<<"\nInorder traversal of BST: ";
    inorder(root);
    cout<<endl;

    return 0;
   
}