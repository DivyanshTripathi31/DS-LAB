#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int val){
        data = val;
        next = prev = nullptr;
    }
};
class DoublyList{
    Node*head;
    public:
        DoublyList(){
            head = nullptr;
        }
    void insertionFirst(int num){
        Node*newNode = new Node(num);
        if(head == nullptr){
            head = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertionLast(int num){
        Node*newNode = new Node(num);
        if(head == nullptr){
           head = newNode;
        }
        else {
            Node*temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    void insertAfter(int key,int val) {
        Node*temp = head;
        while(temp && temp->data != key) {
            temp = temp->next;
        }
        if(temp == nullptr) {
            return;
        }
        Node*newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next != nullptr){
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    void insertBefore(int key,int val) {
    Node*temp = head;
    while(temp && temp->data != key) {
        temp = temp->next;
    }
    if(temp == nullptr) {
        return;
    }
    Node*newNode = new Node(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if(temp->prev != nullptr) {
        temp->prev->next = newNode;
    }
    else{
        head = newNode;
    }
    temp->prev = newNode;
    }
    void deleteNode(int val){
        Node*temp = head;
        while(temp && temp->data != val) {
            temp = temp->next;
        }
        if(temp == nullptr) {
            return;
        }
        if(temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }
        else {
            head = temp->next;
        }
        if(temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
    void search(int val){
        Node*temp = head;
        while(temp != nullptr){
            if(temp->data == val){
                cout << val;
                return;
            }
            temp = temp->next;
        }
        cout << val;
    }
    void display(){
        Node*temp = head;
        while(temp != nullptr){
            cout << temp->data;
            temp = temp->next;
        }
    }
};

class CircularList {
    Node* head;
public:
    CircularList() {
        head = nullptr;
    }
    void insertionFirst(int num) {
        Node* newNode = new Node(num);
        if(head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        }else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertionLast(int num) {
        Node* newNode = new Node(num);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }
   void insertAfter(int key, int val) {
    if (head == nullptr) return;
    Node* temp = head;
    while (true) {
        if (temp->data == key) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
        if (temp == head) break;
    }
}
void insertBefore(int key, int val) {
    if (head == nullptr) return;
    Node* temp = head;
    while (true) {
        if (temp->data == key) {
            Node* newNode = new Node(val);
            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;
            if (temp == head)
                head = newNode;
            return;
        }
        temp = temp->next;
        if (temp == head) break;
    }
}
void deleteNode(int val) {
    if (head == nullptr) return;
    Node* temp = head;
    while (true) {
        if (temp->data == val) {
            if (temp->next == temp && temp->prev == temp) {
                head = nullptr;
                delete temp;
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == head)
                head = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
        if (temp == head) break;
    }
}
void search(int val) {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    while (true) {
        if (temp->data == val) {
            cout << val << " found";
            return;
        }
        temp = temp->next;
        if (temp == head) break;
    }
    cout << val << " not found";
}
void display() {
    if (head == nullptr) {
        cout << "List is empty";
        return;
    }
    Node* temp = head;
    while (true) {
        cout << temp->data << " ";
        temp = temp->next;
        if (temp == head) break;
    }
}
};
int main() {
    DoublyList d;
    CircularList c;
    int choice, val, key;
    while (true) {
        cout << "\n1.Insert First(DLL)\n2.Insert Last(DLL)\n3.Insert After(DLL)\n4.Insert Before(DLL)\n5.Delete(DLL)\n6.Search(DLL)\n7.Display(DLL)";
        cout << "\n8.Insert First(CLL)\n9.Insert Last(CLL)\n10.Insert After(CLL)\n11.Insert Before(CLL)\n12.Delete(CLL)\n13.Search(CLL)\n14.Display(CLL)\n15.Exit\nEnter: ";
        cin >> choice;
        if (choice == 15) break;
        switch (choice) {
            case 1: cin >> val; d.insertionFirst(val); break;
            case 2: cin >> val; d.insertionLast(val); break;
            case 3: cin >> key >> val; d.insertAfter(key, val); break;
            case 4: cin >> key >> val; d.insertBefore(key, val); break;
            case 5: cin >> val; d.deleteNode(val); break;
            case 6: cin >> val; d.search(val); break;
            case 7: d.display(); break;
            case 8: cin >> val; c.insertionFirst(val); break;
            case 9: cin >> val; c.insertionLast(val); break;
            case 10: cin >> key >> val; c.insertAfter(key, val); break;
            case 11: cin >> key >> val; c.insertBefore(key, val); break;
            case 12: cin >> val; c.deleteNode(val); break;
            case 13: cin >> val; c.search(val); break;
            case 14: c.display(); break;
        }
    }
}