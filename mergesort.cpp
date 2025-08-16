#include <iostream>

using std::endl;
using std::cout;

void mergesort(int a[], int n);


int main() {
    int arr[] = {5, 3, 4, 7};
    int n = 4;
    mergesort(arr, n);

    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


void mergesort(int arr[], int n) {
    if (n == 1) return;
    int mid = n / 2;

    int lSize = mid;
    int left[lSize];
    for (int i = 0; i < mid; ++i) {
        left[i] = arr[i];
    }

    int rSize = n - mid;
    int right[rSize];
    for (int i = 0; i < rSize; ++i) {
        right[i] = arr[mid + i + 1];
    }

    mergesort(left, lSize);
    mergesort(right, rSize);

    int newArr[n];

    int i = 0;
    int l = 0, r = 0;
    
    while (l < lSize && r < rSize) {
        if (left[l] < right[r]) {
            newArr[i++] = left[l++];
        }
        else if (right[r] > left[l]) {
            newArr[i++] = right[r++];
        }
        else {
            newArr[i++] = left[l++];
            newArr[i++] = right[r++];
        }
    }
    while (l < lSize) {
        newArr[i++] = left[l++];
    }
    while (r < rSize) {
        newArr[i++] = right[r++];
    }
}