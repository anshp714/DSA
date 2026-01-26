#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Recursive binary search helper function
    int bs(vector<int>& nums, int tar, int st, int end) {
        if(st <= end) {
            int mid = st + (end - st) / 2;
            if(tar == nums[mid]) {
                return mid;
            } else if(tar < nums[mid]) {  // Fixed: should be < not <=
                return bs(nums, tar, st, mid - 1);
            } else {
                return bs(nums, tar, mid + 1, end);
            }
        }
        return -1;
    }
    
    // Public interface for binary search
    int search(vector<int>& nums, int tar) {
        return bs(nums, tar, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Target found
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int result1 = sol.search(nums1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [-1, 0, 3, 5, 9, 12], target = " << target1 << endl;
    cout << "Output: " << result1 << " (Index where target found)" << endl;
    cout << "Expected: 4" << endl << endl;
    
    // Test Case 2: Target not found
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    int result2 = sol.search(nums2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [-1, 0, 3, 5, 9, 12], target = " << target2 << endl;
    cout << "Output: " << result2 << " (-1 means target not found)" << endl;
    cout << "Expected: -1" << endl << endl;
    
    // Test Case 3: Empty array
    vector<int> nums3 = {};
    int target3 = 5;
    int result3 = sol.search(nums3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [], target = " << target3 << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: -1" << endl;
    
    return 0;
}