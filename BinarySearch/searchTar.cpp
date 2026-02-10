#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int st = 0, end = nums.size() - 1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {  // Fixed: was nums[mid<x]
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Element exists
    vector<int> nums1 = {1, 3, 5, 7, 9, 11, 13};
    int target1 = 7;
    cout << "Test 1 - Searching for " << target1 << " in array: ";
    for (int num : nums1) cout << num << " ";
    int result1 = sol.search(nums1, target1);
    cout << "\nResult: Index " << result1 << " (Value: " << (result1 != -1 ? nums1[result1] : -1) << ")\n";
    
    // Test case 2: Element doesn't exist
    int target2 = 8;
    cout << "\nTest 2 - Searching for " << target2 << " in array: ";
    for (int num : nums1) cout << num << " ";
    int result2 = sol.search(nums1, target2);
    cout << "\nResult: " << result2 << " (not found)\n";
    
    // Test case 3: Empty array
    vector<int> nums2 = {};
    int target3 = 5;
    cout << "\nTest 3 - Searching for " << target3 << " in empty array\n";
    int result3 = sol.search(nums2, target3);
    cout << "Result: " << result3 << "\n";
    
    // Test case 4: Single element
    vector<int> nums3 = {10};
    int target4 = 10;
    cout << "\nTest 4 - Searching for " << target4 << " in array: ";
    for (int num : nums3) cout << num << " ";
    int result4 = sol.search(nums3, target4);
    cout << "\nResult: Index " << result4 << "\n";
    
    return 0;
}