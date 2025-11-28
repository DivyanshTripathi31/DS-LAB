#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int value){
        data = value;
        next = nullptr;
    }
};
class LinkedList{
    Node*head;
public:
    LinkedList(){
        head = nullptr;
    }
void insertEnd(int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
void reverse(){
    Node*prev = nullptr, *temp = head, *next = nullptr;
    while(temp != nullptr){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}
void display(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data;
        if(temp->next != nullptr) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << "->NULL";
}
};

int main(){
    LinkedList list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.reverse();
    list.display();

    return 0;
}