#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

void merge_sorted_arrays(int arr1[], int s1, int arr2[], int s2, int merged_array[]) {
    int i = 0, j = 0, k = 0;
    while (i < s1 && j < s2) {
        if (arr1[i] < arr2[j]) {
            merged_array[k++] = arr1[i++];
        } else {
            merged_array[k++] = arr2[j++];
        }
    }
    while (i < s1) {
        merged_array[k++] = arr1[i++];
    }
    while (j < s2) {
        merged_array[k++] = arr2[j++];
    }
}
int main() {
    srand(time(0));
    int n;
    std::cout << "Enter the size of the arrays: ";
    std::cin >> n;
    int array1[n];
    int array2[n];
    for (int i = 0; i < n; ++i) {
        array1[i] = rand() % 100; 
        array2[i] = rand() % 100;
    }
    int resultant_array[2 * n];

    auto start = std::chrono::high_resolution_clock::now();
    
    merge_sorted_arrays(array1, n, array2, n, resultant_array);
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::nano> elapsed_nanoseconds = end - start;
    std::cout << "Time taken for merging: " << elapsed_nanoseconds.count() << " nanoseconds" << std::endl;

    std::cout << "Merged sorted array: ";
    for (int i = 0; i < 2 * n; ++i) {
        std::cout << resultant_array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
