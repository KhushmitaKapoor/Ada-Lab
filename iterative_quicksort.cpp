#include <iostream> 
#include <cstdlib>
#include <ctime>
using namespace std; 

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void iterative_quickSort(int arr[], int l, int h) 
{ 
    int stack[h - l + 1]; 
    int top = -1; 
    stack[++top] = l; 
    stack[++top] = h; 

    while (top >= 0) { 
        h = stack[top--]; 
        l = stack[top--]; 
        int p = partition(arr, l, h); 

        if (p - l > 1) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    } 
} 

void recursive_quickSort(int arr[], int l, int h, int& count) 
{ 
    if (l < h) { 
        int p = partition(arr, l, h); 
        recursive_quickSort(arr, l, p - 1, count); 
        recursive_quickSort(arr, p + 1, h, count); 
        count++;
    }
} 

int main() 
{ 
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    // Seed the random number generator
    srand(time(nullptr));

    // Generate random numbers for the array
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }

    int count = 0; // Variable to count recursive calls
    recursive_quickSort(arr, 0, size - 1, count); 

    cout << "Elements after sorting:"; 
    for (int i = 0; i < size; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << "\nNumber of recursive calls: " << count << endl;
    return 0; 
}

