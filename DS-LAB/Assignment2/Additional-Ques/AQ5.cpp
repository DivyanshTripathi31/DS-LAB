#include <iostream>
using namespace std;

void duplicateTwo(int arr[], int n) {
    int i = 0;
    while (i < n) {
        if (arr[i] == 2) {
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            if (i + 1 < n) {
                arr[i + 1] = 2;
            }
            i += 2;
        } else {
            i++;
        }
    }
}

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    duplicateTwo(arr, n);

    cout << "modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}