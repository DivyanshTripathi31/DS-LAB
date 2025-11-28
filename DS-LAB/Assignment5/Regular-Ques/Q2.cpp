#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
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
void insertEnd(int value) {
        Node* newNode = new Node(value);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node*temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void countAndDelete(int key) {
        int c = 0;
        while (head != nullptr && head->data == key) {
            Node*temp = head;
            head = head->next;
            delete temp;
            c++;
        }
        Node* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->data == key) {
                Node* t = cur->next;
                cur->next = cur->next->next;
                delete t;
                c++;
            } else cur = cur->next;
        }
        cout << "Count: " << c << endl;
    }

    void display() {
        Node* t = head;
        while (t != nullptr) {
            cout << t->data;
            if (t->next != nullptr) cout << "->";
            t = t->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList l;
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(1);
    l.insertEnd(2);
    l.insertEnd(1);
    l.insertEnd(3);
    l.insertEnd(1);

    cout << "Original List: ";
    l.display();

    l.countAndDelete(1);

    cout << "Updated List: ";
    l.display();

    return 0;
}