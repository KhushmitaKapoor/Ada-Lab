#include<iostream>
#include<chrono>
#include<cstdlib>

using namespace std;
using namespace std::chrono;

bool search(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return true;
        }
    }
    return false;
}

void generateRandomInputs(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100000; // Generating random numbers between 0 and 99999
    }
}

int main() {
    srand(time(0)); 
    int arr[10];
    generateRandomInputs(arr, 10);

    cout << "Enter the element to search for" << endl;
    int key;
    cin >> key;

    auto start = high_resolution_clock::now(); // Start time
    bool found = search(arr, 10, key);
    auto stop = high_resolution_clock::now(); // Stop time

    auto duration = duration_cast<nanoseconds>(stop - start); // Calculating duration in nanoseconds

    if(found) {
        cout << "Key present" << endl;
    } else {
        cout << "Key absent" << endl;
    }

    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}

