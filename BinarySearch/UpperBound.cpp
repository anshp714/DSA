#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int upperBound(vector<int> &nums, int x) {
        int st = 0, end = nums.size() - 1;
        int ans = nums.size(); // Default answer if all elements are <= x
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            if (nums[mid] > x) {
                ans = mid;
                end = mid - 1;  // Move left to find first occurrence
            } else {
                st = mid + 1;   // Move right
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {1, 2, 2, 2, 3, 4, 5};
    int x1 = 2;
    cout << "Array: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nUpper bound of " << x1 << " is at index: " << sol.upperBound(nums1, x1);
    cout << " (Value: " << (sol.upperBound(nums1, x1) < nums1.size() ? nums1[sol.upperBound(nums1, x1)] : -1) << ")\n";
    
    // Test case 2: Element not present
    int x2 = 6;
    cout << "\nUpper bound of " << x2 << " is at index: " << sol.upperBound(nums1, x2);
    cout << " (out of bounds - not found)\n";
    
    // Test case 3: Element smaller than all
    int x3 = 0;
    cout << "Upper bound of " << x3 << " is at index: " << sol.upperBound(nums1, x3);
    cout << " (Value: " << nums1[sol.upperBound(nums1, x3)] << ")\n";
    
    // Test case 4: Duplicates
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int x4 = 2;
    cout << "\nArray: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nUpper bound of " << x4 << " is at index: " << sol.upperBound(nums2, x4);
    cout << " (out of bounds)\n";
    
    // Test case 5: Mixed values
    vector<int> nums3 = {1, 3, 5, 7, 9};
    int x5 = 5;
    cout << "\nArray: ";
    for (int num : nums3) cout << num << " ";
    cout << "\nUpper bound of " << x5 << " is at index: " << sol.upperBound(nums3, x5);
    cout << " (Value: " << nums3[sol.upperBound(nums3, x5)] << ")\n";
    
    // Test case 6: Empty array
    vector<int> nums4 = {};
    int x6 = 5;
    cout << "\nEmpty array\n";
    cout << "Upper bound of " << x6 << " is at index: " << sol.upperBound(nums4, x6) << "\n";
    
    return 0;
}