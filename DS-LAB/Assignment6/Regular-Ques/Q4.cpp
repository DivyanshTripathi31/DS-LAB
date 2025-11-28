
#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyList {
    Node* head;
public:
    DoublyList() {
        head = nullptr;
    }
    void insertEnd(char val) {
        Node*newNode = new Node(val);
        if(head == nullptr) {
            head = newNode;
            return;
        }
        Node*temp = head;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    bool isPalindrome() {
        if(head == nullptr) return true;
        Node*left = head;
        Node*right = head;
        while(right->next != nullptr)
            right = right->next;
        while(left != right && left->prev != right) {
            if(left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main() {
    DoublyList list;
    string s;
    cin >> s;
    for (char c : s)
        list.insertEnd(c);
    if(list.isPalindrome())
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}
