#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int repeat = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                repeat = 1;
                break;
            }
        }
        if (repeat == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    int arr[100];

    cout << "enter size of array: ";
    cin >> n;

    cout << "enter " << n << "elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int totalDistinct = countDistinct(arr, n);
    cout << "total distinct elements = " << totalDistinct;

    return 0;
}