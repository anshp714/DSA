#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1, high = n-2;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
                return mid;
            } else if(nums[mid] > nums[mid-1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Peak in the middle
    vector<int> nums1 = {1, 2, 3, 1};
    int result1 = sol.findPeakElement(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1, 2, 3, 1]" << endl;
    cout << "Output: " << result1 << " (Index of peak element)" << endl;
    cout << "Expected: 2 (value 3 is peak)" << endl << endl;
    
    // Test Case 2: Multiple peaks, return any
    vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    int result2 = sol.findPeakElement(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [1, 2, 1, 3, 5, 6, 4]" << endl;
    cout << "Output: " << result2 << " (Index of peak element)" << endl;
    cout << "Expected: Either 1 (value 2) or 5 (value 6) is acceptable" << endl << endl;
    
    // Test Case 3: Increasing then decreasing
    vector<int> nums3 = {1, 2, 3, 4, 5, 3, 2, 1};
    int result3 = sol.findPeakElement(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [1, 2, 3, 4, 5, 3, 2, 1]" << endl;
    cout << "Output: " << result3 << " (Index of peak element)" << endl;
    cout << "Expected: 4 (value 5 is peak)" << endl;
    
    return 0;
}