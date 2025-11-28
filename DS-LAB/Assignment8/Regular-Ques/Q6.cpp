//Implementing priority queue using heaps...

#include<iostream>
using namespace std;
#define MAX 100

class PriorityQueue {
    int heap[MAX];
    int size;

    void maxHeapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < size && heap[left] > heap[largest])
            largest = left;

        if(right < size && heap[right] > heap[largest])
            largest = right;

        if(largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    PriorityQueue() {
        size = 0;
    }

    void insert(int value) {
        if(size == MAX) {
            cout << "Priority Queue is full\n";
            return;
        }

        int i = size;
        heap[i] = value;
        size++;

        // Fix max heap property (bubble up)
        while(i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMax() {
        if(size == 0) {
            cout << "Priority Queue is empty\n";
            return -1;
        }

        int maxElement = heap[0];
        heap[0] = heap[size - 1];
        size--;

        maxHeapify(0);
        return maxElement;
    }

    void display() {
        for(int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(30);
    pq.insert(50);
    pq.insert(20);
    pq.insert(60);
    pq.insert(10);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Max element removed: " << pq.extractMax() << endl;

    cout << "After removal: ";
    pq.display();
}
