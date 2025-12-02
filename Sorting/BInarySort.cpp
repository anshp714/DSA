#include<iostream>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int st = 0;
    int end
     = size - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2; // To avoid potential overflow

        if (arr[mid] == target) {
            return mid; // Target found
        }
        else if (arr[mid] < target) {
            st = mid + 1; // Search in the right half
        }
        else {
            end = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, size, target);
    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }

    return 0;
}