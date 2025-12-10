#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        // Dutch National Flag Algorithm
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap 0 to the beginning
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // 1 is already in the correct position (middle)
                mid++;
            } else { // nums[mid] == 2
                // Swap 2 to the end
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Helper function to print vector
void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Test function
void testSortColors(Solution& sol, vector<int> nums) {
    cout << "Original array: ";
    printVector(nums);
    
    sol.sortColors(nums);
    
    cout << " -> Sorted array: ";
    printVector(nums);
    
    // Verify if sorted correctly
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    if (nums == sorted) {
        cout << " ✓ (Correctly sorted)" << endl;
    } else {
        cout << " ✗ (Incorrect sorting)" << endl;
    }
}

int main() {
    Solution sol;
    
    // Test Case 1: Basic example
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    testSortColors(sol, nums1);
    
    // Test Case 2: Already sorted
    vector<int> nums2 = {0, 0, 1, 1, 2, 2};
    testSortColors(sol, nums2);
    
    // Test Case 3: Reverse sorted
    vector<int> nums3 = {2, 2, 1, 1, 0, 0};
    testSortColors(sol, nums3);
    
    // Test Case 4: All zeros
    vector<int> nums4 = {0, 0, 0, 0};
    testSortColors(sol, nums4);
    
    // Test Case 5: All ones
    vector<int> nums5 = {1, 1, 1, 1};
    testSortColors(sol, nums5);
    
    // Test Case 6: All twos
    vector<int> nums6 = {2, 2, 2, 2};
    testSortColors(sol, nums6);
    
    // Test Case 7: Single element
    vector<int> nums7 = {1};
    testSortColors(sol, nums7);
    
    // Test Case 8: Mixed with missing elements
    vector<int> nums8 = {2, 0, 1};
    testSortColors(sol, nums8);
    
    // Test Case 9: Empty array
    vector<int> nums9 = {};
    testSortColors(sol, nums9);
    
    // Test Case 10: Complex case
    vector<int> nums10 = {1, 0, 2, 1, 0, 2, 1, 0};
    testSortColors(sol, nums10);
    
    return 0;
}