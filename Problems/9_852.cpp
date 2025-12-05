#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the index of the peak element in a Mountain Array.
     * * @param arr The input Mountain Array.
     * @return int The index of the peak element.
     */
    int peakIndexInMountainArray(vector<int>& arr) {
        // Start the search range from index 1 to size - 2, 
        // as the peak cannot be the first or last element in a valid mountain array.
        int st = 1; 
        int end = arr.size() - 2;

        while (st <= end) {
            // Calculate mid index safely
            int mid = st + (end - st) / 2;
            
            // Check for the peak condition: arr[mid] is greater than both its neighbors.
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid; // Found the peak!
            }

            // If the element is on the ascending slope (left side of the peak)
            if (arr[mid - 1] < arr[mid]) {
                // The peak must be at mid or to the right of mid.
                // Since mid is on the ascending side, we eliminate the left side (st to mid).
                st = mid + 1;
            } 
            // If the element is on the descending slope (right side of the peak)
            else { // arr[mid] > arr[mid+1]
                // The peak must be at mid or to the left of mid.
                // Since mid is on the descending side, we eliminate the right side (mid to end).
                // We keep mid in the potential range by setting end = mid - 1.
                end = mid - 1;
            }
        }
        
        // Should not be reached for a valid Mountain Array, but included for completeness.
        return -1; 
    }
};

// Helper function to print execution results
void testPeakIndex(Solution& sol, vector<int> arr) {
    int index = sol.peakIndexInMountainArray(arr);
    cout << "Array: [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "], Peak Index: " << index << endl;
}

int main() {
    Solution sol;

    // Example 1: Peak at index 2
    vector<int> arr1 = {0, 1, 2, 1, 0};
    testPeakIndex(sol, arr1); // Expected: 2

    // Example 2: Peak at index 1
    vector<int> arr2 = {0, 2, 1, 0};
    testPeakIndex(sol, arr2); // Expected: 1

    // Example 3: Peak at index 3
    vector<int> arr3 = {0, 10, 50, 5, 2, 1};
    testPeakIndex(sol, arr3); // Expected: 3

    return 0;
}