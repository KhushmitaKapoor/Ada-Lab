#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <chrono>  

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int kthSmallest(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex - low == k - 1)
            return arr[pivotIndex];

        if (pivotIndex - low > k - 1)
            return kthSmallest(arr, low, pivotIndex - 1, k);

        return kthSmallest(arr, pivotIndex + 1, high, k - pivotIndex + low - 1);
    }

    return -1;
}

int main() {
    srand(time(NULL));
    const int SIZE = 100000;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; 
    }
    cout << "Generated array:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k = 3;
    auto start = chrono::steady_clock::now(); 
    int kthSmallestElement = kthSmallest(arr, 0, SIZE - 1, k);
    auto end = chrono::steady_clock::now();   
    cout << "K'th smallest element is " << kthSmallestElement << endl;
    cout << "Time taken: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;

    return 0;
}