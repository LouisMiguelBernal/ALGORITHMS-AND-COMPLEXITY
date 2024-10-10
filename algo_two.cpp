#include <iostream>
#include <vector>
#include <chrono> // For measuring time

// Bubble Sort implementation
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Merge function for Merge Sort
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort implementation
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    // Example input of delivery times
    std::vector<int> deliveryTimes = {30, 20, 50, 10, 40}; // Modify this for testing different sizes

    // Bubble Sort
    auto startBubble = std::chrono::high_resolution_clock::now();
    bubbleSort(deliveryTimes);
    auto endBubble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationBubble = endBubble - startBubble;

    std::cout << "Sorted delivery times using Bubble Sort: ";
    for (int time : deliveryTimes) {
        std::cout << time << " ";
    }
    std::cout << "\nBubble Sort took: " << durationBubble.count() << " seconds\n";

    // Resetting delivery times for Merge Sort
    deliveryTimes = {30, 20, 50, 10, 40}; // Reset to original for fair comparison

    // Merge Sort
    auto startMerge = std::chrono::high_resolution_clock::now();
    mergeSort(deliveryTimes, 0, deliveryTimes.size() - 1);
    auto endMerge = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationMerge = endMerge - startMerge;

    std::cout << "Sorted delivery times using Merge Sort: ";
    for (int time : deliveryTimes) {
        std::cout << time << " ";
    }
    std::cout << "\nMerge Sort took: " << durationMerge.count() << " seconds\n";

    // Time complexity analysis
    std::cout << "\nTime Complexity Analysis:\n";
    std::cout << "Bubble Sort: O(N^2) - Inefficient for large datasets.\n";
    std::cout << "Merge Sort: O(N log N) - More efficient for larger datasets.\n";

    return 0;
}
