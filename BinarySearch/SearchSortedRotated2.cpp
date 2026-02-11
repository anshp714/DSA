#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;
            
            if(nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates: if all three are equal, we can't determine which side is sorted
            if(nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
                continue;
            }

            // Left half is sorted
            if(nums[st] <= nums[mid]) {
                if(nums[st] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if(nums[mid] <= target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Target found in rotated array with duplicates
    vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    int target1 = 0;
    bool result1 = sol.search(nums1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [2, 5, 6, 0, 0, 1, 2], target = " << target1 << endl;
    cout << "Output: " << (result1 ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;
    
    // Test Case 2: Target not found in rotated array with duplicates
    vector<int> nums2 = {2, 5, 6, 0, 0, 1, 2};
    int target2 = 3;
    bool result2 = sol.search(nums2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [2, 5, 6, 0, 0, 1, 2], target = " << target2 << endl;
    cout << "Output: " << (result2 ? "true" : "false") << endl;
    cout << "Expected: false" << endl << endl;
    
    // Test Case 3: Array with all duplicates
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1};
    int target3 = 1;
    bool result3 = sol.search(nums3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [1, 1, 1, 1, 1, 1, 1], target = " << target3 << endl;
    cout << "Output: " << (result3 ? "true" : "false") << endl;
    cout << "Expected: true" << endl;
    
    return 0;
}