#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to find the element with maximum frequency
int maxFreq(int arr[], int n) {
    
    // Create a hash map to store frequency of each element
    unordered_map<int, int> count;
    
    int maxFreq = 0;
    int maxAns = 0;

    for(int i = 0; i < n; i++) {
        // Increment the frequency of the current element
        count[arr[i]]++;

        // If current element's frequency is greater than the max frequency seen so far
        if(count[arr[i]] > maxFreq) {
            maxFreq = count[arr[i]];
            maxAns = arr[i];
        }
    }
    
    return maxAns;
}

int main() {
    // Example 1: Standard case
    int arr1[] = {1, 2, 2, 3, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Example 1 Array: {1, 2, 2, 3, 1, 2}" << endl;
    cout << "Most Frequent Element: " << maxFreq(arr1, n1) << endl;

    cout << "-------------------------" << endl;

    // Example 2: Tie case (Usually returns the one that reached the max count first)
    int arr2[] = {10, 20, 10, 20, 30};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "Example 2 Array: {10, 20, 10, 20, 30}" << endl;
    cout << "Most Frequent Element: " << maxFreq(arr2, n2) << endl;

    return 0;
}