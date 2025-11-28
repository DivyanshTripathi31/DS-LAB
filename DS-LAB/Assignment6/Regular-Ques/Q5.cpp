#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
bool isCircular(Node* head) {
    if (head == nullptr)
        return false;
    Node* temp = head->next;
    while(temp != nullptr && temp != head)
        temp = temp->next;
    return (temp == head);
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    head->next = second;
    second->next = third;
    third->next = head;
    if(isCircular(head))
        cout << "linked list is circular";
    else
        cout << "linked list is not circular";
    return 0;
}