#include <iostream>
#include <chrono>
#include <iomanip>
#include <random>
#include <string>
#include <algorithm>
#include <functional>
#include <cstring>

typedef std::chrono::high_resolution_clock Clock;

// Bubble sort implementation
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Manual swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion sort implementation
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge sort implementation
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free allocated memory
    delete[] L;
    delete[] R;
}

void mergeSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

// Quicksort implementation
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Manual swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Manual swap
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSortHelper(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
}

// Counting sort implementation
void countingSort(int arr[], int n) {
    if (n <= 1) return;

    // Find the maximum element to determine the count array size
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a count array and initialize with zeros
    int* count = new int[max + 1]();

    // Store the count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the count array to store the position of each element
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary output array
    int* output = new int[n];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free allocated memory
    delete[] count;
    delete[] output;
}

// Radix sort implementation
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = { 0 };

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] contains
    // actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Free allocated memory
    delete[] output;
}

void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);

    // Do counting sort for every digit
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

// Modified std::sort wrapper to avoid using std::sort which may use swap internally
void stdSort(int arr[], int n) {
    // Using a custom implementation since we can't use std::sort which likely uses swap
    // This is a simple insertion sort implementation for demonstration
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to generate random integers
void generateRandomArray(int arr[], int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2 * size);

    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
}

// Function to verify if array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

// Helper function to format time in milliseconds
std::string formatTime(double nanoseconds) {
    return std::to_string(nanoseconds / 1000000.0) + " ms";
}

// Function to benchmark a sorting algorithm
double benchmark(void (*sortFunction)(int[], int), int arr[], int size) {
    auto t1 = Clock::now();
    sortFunction(arr, size);
    auto t2 = Clock::now();

    // Verify that the array is sorted
    if (!isSorted(arr, size)) {
        std::cerr << "Sort verification failed!" << std::endl;
        return -1.0;
    }

    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}

int main() {
    // Array sizes to test
    int sizes[] = { 10, 100, 500, 5000, 25000, 100000 };
    int sizesCount = sizeof(sizes) / sizeof(sizes[0]);

    // Number of trials for each size
    const int trials = 10;

    // Initialize result storage
    const int sortCount = 6; // Removed "Custom Sort"
    std::string sortNames[sortCount] = {
        "Bubble Sort",
        "Insertion Sort",
        "Merge Sort",
        "Quick Sort",
        "Counting Sort",
        "Radix Sort"
    };

    double results[sortCount][6] = { 0 }; // Assuming 6 different sizes

    // Function pointers for sorting algorithms
    void (*sortFunctions[sortCount])(int[], int) = {
        bubbleSort,
        insertionSort,
        mergeSort,
        quickSort,
        countingSort,
        radixSort
    };

    // Run benchmarks for each size
    for (int s = 0; s < sizesCount; s++) {
        int size = sizes[s];
        std::cout << "Testing array size: " << size << std::endl;

        for (int t = 0; t < trials; t++) {
            // Generate a random array
            int* original = new int[size];
            generateRandomArray(original, size);

            for (int i = 0; i < sortCount; i++) {
                // Skip bubble and insertion sort for large arrays
                if ((i == 0 || i == 1) && size > 25000) {
                    results[i][s] = -1.0;  // Marker for skipped tests
                    continue;
                }

                // Create a copy of the original array for this sort
                int* arr = new int[size];
                std::memcpy(arr, original, size * sizeof(int));

                double time = benchmark(sortFunctions[i], arr, size);

                // Add time to results (will be averaged later)
                if (results[i][s] >= 0) {
                    results[i][s] += time;
                }

                // Free the copied array
                delete[] arr;
            }

            // Free the original array
            delete[] original;
        }

        // Calculate the average time for each algorithm
        for (int i = 0; i < sortCount; i++) {
            if (results[i][s] > 0) {
                results[i][s] /= trials;
            }
        }
    }

    // Print results in tabular form (milliseconds)
    std::cout << "\n=== RESULTS (Average time in milliseconds over " << trials << " trials) ===" << std::endl;

    // Print header with sizes
    std::cout << std::left << std::setw(18) << "Algorithm";
    for (int s = 0; s < sizesCount; s++) {
        std::cout << std::right << std::setw(15) << sizes[s];
    }
    std::cout << std::endl;

    // Print separator
    std::cout << std::string(18 + 15 * sizesCount, '-') << std::endl;

    // Print results for each algorithm
    for (int i = 0; i < sortCount; i++) {
        std::cout << std::left << std::setw(18) << sortNames[i];
        for (int s = 0; s < sizesCount; s++) {
            if (results[i][s] < 0) {
                std::cout << std::right << std::setw(15) << "N/A";
            }
            else {
                // Convert to milliseconds and display with 2 decimal places
                double ms = results[i][s] / 1000000.0;
                std::cout << std::right << std::setw(15) << std::fixed << std::setprecision(2) << ms;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
