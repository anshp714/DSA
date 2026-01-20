#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Phase 1: Find intersection point
        do {
            slow = nums[slow];       // move 1 step
            fast = nums[nums[fast]]; // move 2 steps
        } while (slow != fast);

        // Phase 2: Find entrance to cycle (duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow]; // move 1 step
            fast = nums[fast]; // move 1 step
        }
        return slow;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 3, 4, 2, 2};
    int result1 = sol.findDuplicate(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1, 3, 4, 2, 2]" << endl;
    cout << "Output: " << result1 << " (Duplicate number)" << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {3, 1, 3, 4, 2};
    int result2 = sol.findDuplicate(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [3, 1, 3, 4, 2]" << endl;
    cout << "Output: " << result2 << " (Duplicate number)" << endl;
    cout << "Expected: 3" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {2, 2, 2, 2, 2};
    int result3 = sol.findDuplicate(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [2, 2, 2, 2, 2]" << endl;
    cout << "Output: " << result3 << " (Duplicate number)" << endl;
    cout << "Expected: 2" << endl;
    
    return 0;
}
