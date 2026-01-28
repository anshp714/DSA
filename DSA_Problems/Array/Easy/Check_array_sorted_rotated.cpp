#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            if(count > 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Sorted and rotated array
    vector<int> nums1 = {3, 4, 5, 1, 2};
    bool result1 = sol.check(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [3, 4, 5, 1, 2]" << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: true (Array is sorted and rotated)" << endl << endl;
    
    // Test Case 2: Not sorted and rotated
    vector<int> nums2 = {2, 1, 3, 4};
    bool result2 = sol.check(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [2, 1, 3, 4]" << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: false (Array is not sorted and rotated)" << endl << endl;
    
    // Test Case 3: Already sorted array
    vector<int> nums3 = {1, 2, 3, 4, 5};
    bool result3 = sol.check(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [1, 2, 3, 4, 5]" << endl;
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: true (Array is sorted, rotation count = 0)" << endl;
    
    return 0;
}