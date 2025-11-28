#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*next;
        
        Node(int value){
            data=value;
            next=nullptr;
    }   
};
class LinkedList{
    Node*head;
        public:
        LinkedList(){
            head=nullptr;
}
void insertEnd(int value){
    Node*newNode=new Node(value);
    if(head==nullptr){
        head=newNode;
    }
    else{
        Node*temp=head;
        while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
void findMiddle(){
    Node*slow=head;
    Node*fast=head;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
        cout<<slow->data;
    }
};

int main(){
    LinkedList list;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        list.insertEnd(x);
    }
    list.findMiddle();
}