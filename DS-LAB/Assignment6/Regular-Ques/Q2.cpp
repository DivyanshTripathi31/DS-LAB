#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node*next;
    Node*prev;
    Node(int val){
        data = val;
        next = prev = nullptr;
    }
};
class CircularList {
    Node* head;
public:
    CircularList() {
        head = nullptr;
    }
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node*temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    void display() {
        if(head == nullptr) return;
        Node* temp = head;
        while(true){
            cout << temp->data << " ";
            temp = temp->next;
            if(temp == head) break;
        }
        cout << head->data << endl;
    }
};

int main() {
    CircularList cl;
    cl.insertEnd(20);
    cl.insertEnd(100);
    cl.insertEnd(40);
    cl.insertEnd(80);
    cl.insertEnd(60);
    cl.display();
    return 0;
}