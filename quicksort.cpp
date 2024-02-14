#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0)); 

    const int numInputs = 10;
    int arraySizes[numInputs];
    long long result[numInputs]; 

    for (int i = 0; i < numInputs; ++i) {
        arraySizes[i] = (i + 1) * 500; 
    }

    for (int i = 0; i < numInputs; ++i) {
        int arraySize = arraySizes[i];
        int arr[arraySize];

        for (int j = 0; j < arraySize; ++j) {
            arr[j] = rand() % 100000; 
        }

        auto start = high_resolution_clock::now();
        quickSort(arr, 0, arraySize - 1);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        result[i] = duration.count();
    }

    cout << "Input Size\tTime Taken (microseconds)\n";
    for (int i = 0; i < numInputs; ++i) {
        cout << arraySizes[i] << "\t\t" << result[i] << endl;
    }

    return 0;
}