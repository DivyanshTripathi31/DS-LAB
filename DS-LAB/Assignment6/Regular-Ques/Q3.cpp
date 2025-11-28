#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) {
        data = val;
        next = nullptr;
    }
};

class DoublyList {
    DNode* head;
public:
    DoublyList() {
        head = nullptr;
    }
    void insertEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    int size() {
        int count = 0;
        DNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CircularList {
    CNode* head;
public:
    CircularList() {
        head = nullptr;
    }
    void insertEnd(int val) {
        CNode* newNode = new CNode(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }
        CNode* temp = head;
        while (temp->next != head)
            temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
    }
    int size() {
        if (head == nullptr) return 0;
        int count = 0;
        CNode* temp = head;
        while (true) {
            count++;
            temp = temp->next;
            if (temp == head)
                break;
        }
        return count;
    }
};

int main() {
    DoublyList dlist;
    CircularList clist;

    dlist.insertEnd(10);
    dlist.insertEnd(20);
    dlist.insertEnd(30);
    clist.insertEnd(5);
    clist.insertEnd(15);
    clist.insertEnd(25);
    clist.insertEnd(35);

    cout << "size of doubly linked list: " << dlist.size() << endl;
    cout << "size of circular linked list: " << clist.size() << endl;

    return 0;
}