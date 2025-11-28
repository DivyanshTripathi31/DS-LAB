#include <bits/stdc++.h>
using namespace std;

class Node{
    public :
        int data;
        Node*next;

        Node(int value){
            data = value;
            next = nullptr;
    }
};
class LinkedList{
    private:
        Node*head;
    
    public:
        LinkedList(){
            head = nullptr;
        }
void insertBeginning(int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void insertEnd(int value){
    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node*temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void insertBetween(int value,int pos) {
    if(pos < 0) {
        cout << "invalid";
        return;
    }
    if(pos == 0) {
        insertBeginning(value);
        return;
    }
    Node* temp = head;
    for(int i=0; i<pos-1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if(temp == nullptr) {
        cout << "invalid";
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning(){
    if(head == nullptr){
        return;
    }
    Node*temp = head;
    head = head->next;
    delete temp;
}
void deleteEnd(){
    if(head == nullptr) {
        cout << "list is empty";
        return;
    }
    if(head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteNode(int value) {
    if(head == nullptr) {
        cout << "empty";
        return;
    }
    if(head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == nullptr) {
        cout << "not found";
        return;
    }
    prev->next = temp->next;
    delete temp;
}

void searchNode(int key){
    Node*temp = head;
    int key = 0;
    while(temp!=nullptr){
        if(temp->data == key){
            cout << key;
        }
        temp = temp->next;
        key++;
    }
}
void displayNode(){
    Node*temp = head;
    while(temp!=nullptr){
        cout << temp->data;
        temp = temp->next;
    }
}
};

int main() {
    LinkedList list;
    int select, value, key;

    while(true){
        cout << "SINGLY LINKED LIST MENU" << endl;
        cout << "1.INSERTION AT THE BEGINNING" << endl;
        cout << "2.INSERTION AT THE END" << endl;
        cout << "3.INSERTION IN BETWEEN" << endl;
        cout << "4.DELETION AT THE BEGINNING" << endl;
        cout << "5.DELETION AT THE END" << endl;
        cout << "6.DELETE SPECIFIC NODE" << endl;
        cout << "7.SEARCH" << endl;
        cout << "8.DISPLAY" << endl;

        cout << "enter your choice";
        cin >> select;

        switch(select){
            case 1:
                cout << "enter value:";
                cin >> value;
                list.insertBeginning(value);
                break;
            case 2:
                cout << "enter value:";
                cin >> value;
                list.insertEnd(value);
                break;
            case 3:
                cout << "enter key:";
                cin >> key;
                cout << "enter new node value:";
                cin >> value;
                list.insertBetween(key,value);
                break;
            case 4:
                list.deleteBeginning();
                break;
            case 5:
                list.deleteEnd();
                break;
            case 6:
                cout << "enter key:";
                cin >> key;
                list.deleteNode(key);
                break;
            case 7:
                cout << "enter key:";
                cin >> key;
                list.searchNode(key);
                break;
            case 8:
                list.displayNode();
                break;
        }
    }
    return 0;
}