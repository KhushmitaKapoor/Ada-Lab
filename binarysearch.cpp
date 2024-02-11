#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main() {
    int size = 1000; 
    int key = 7;    
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
    auto start = high_resolution_clock::now();
    int index = binarySearch(arr, size, key);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    if (index != -1) {
        cout << "Key found at index " << index << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }
    cout << "Time taken for binary search: " << duration.count() << " nanoseconds" << endl;

    return 0;
}


