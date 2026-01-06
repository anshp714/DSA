#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;  // Last index of nums1
        int i = m - 1;        // Last element of nums1's valid portion
        int j = n - 1;        // Last element of nums2

        // Merge from the end to avoid overwriting elements
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx] = nums1[i];
                idx--;
                i--;
            } else {
                nums1[idx] = nums2[j];
                idx--;
                j--;
            }
        }
        
        // If there are remaining elements in nums2
        while (j >= 0) {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
        // Note: No need for while(i >= 0) because those elements are already in place
    }
};

// Helper function to print vector
void printVector(const vector<int>& nums, int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << nums[i];
        if (i != size - 1) cout << ", ";
    }
    cout << "]";
}

// Test function
void testMerge(Solution& sol, vector<int> nums1, int m, vector<int> nums2, int n) {
    // Create a copy of nums1 for display
    vector<int> original_nums1 = nums1;
    
    cout << "nums1 = ";
    printVector(nums1, m);
    cout << " (m = " << m << ")" << endl;
    
    cout << "nums2 = ";
    printVector(nums2, n);
    cout << " (n = " << n << ")" << endl;
    
    // Merge the arrays
    sol.merge(nums1, m, nums2, n);
    
    cout << "After merge: ";
    printVector(nums1, m + n);
    
    // Verify if sorted correctly
    bool correct = true;
    for (int i = 1; i < m + n; i++) {
        if (nums1[i] < nums1[i - 1]) {
            correct = false;
            break;
        }
    }
    
    if (correct) {
        cout << " ✓ (Correctly merged and sorted)" << endl;
    } else {
        cout << " ✗ (Incorrect merging)" << endl;
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Test Case 1: Standard case
    {
        vector<int> nums1 = {1, 2, 3, 0, 0, 0};
        vector<int> nums2 = {2, 5, 6};
        testMerge(sol, nums1, 3, nums2, 3);
    }
    
    // Test Case 2: nums1 is empty
    {
        vector<int> nums1 = {0};
        vector<int> nums2 = {1};
        testMerge(sol, nums1, 0, nums2, 1);
    }
    
    // Test Case 3: nums2 is empty
    {
        vector<int> nums1 = {1, 2, 3, 0, 0, 0};
        vector<int> nums2 = {};
        testMerge(sol, nums1, 3, nums2, 0);
    }
    
    // Test Case 4: nums1 has larger elements
    {
        vector<int> nums1 = {4, 5, 6, 0, 0, 0};
        vector<int> nums2 = {1, 2, 3};
        testMerge(sol, nums1, 3, nums2, 3);
    }
    
    // Test Case 5: nums2 has larger elements
    {
        vector<int> nums1 = {1, 2, 3, 0, 0, 0};
        vector<int> nums2 = {4, 5, 6};
        testMerge(sol, nums1, 3, nums2, 3);
    }
    
    // Test Case 6: All elements equal
    {
        vector<int> nums1 = {2, 2, 2, 0, 0, 0};
        vector<int> nums2 = {2, 2, 2};
        testMerge(sol, nums1, 3, nums2, 3);
    }
    
    // Test Case 7: Single element each
    {
        vector<int> nums1 = {5, 0};
        vector<int> nums2 = {2};
        testMerge(sol, nums1, 1, nums2, 1);
    }
    
    // Test Case 8: Large numbers
    {
        vector<int> nums1 = {1, 3, 5, 7, 0, 0, 0, 0};
        vector<int> nums2 = {2, 4, 6, 8};
        testMerge(sol, nums1, 4, nums2, 4);
    }
    
    // Test Case 9: Duplicate elements
    {
        vector<int> nums1 = {1, 1, 3, 0, 0, 0};
        vector<int> nums2 = {1, 2, 2};
        testMerge(sol, nums1, 3, nums2, 3);
    }
    
    // Test Case 10: Negative numbers
    {
        vector<int> nums1 = {-5, -3, -1, 0, 0, 0};
        vector<int> nums2 = {-4, -2, 0};
        testMerge(sol, nums1, 3, nums2, 3);
    }
    
    return 0;
}