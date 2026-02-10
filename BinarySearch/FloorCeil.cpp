#include <iostream>
#include <vector>
#include <utility>  // For pair
using namespace std;

class Solution {
public:
    pair<int, int> getFloorAndCeil(vector<int> &nums, int x) {
        int st = 0, end = nums.size() - 1;
        int floor = -1, ceil = -1;
        
        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == x) {
                return {x, x};
            } else if (nums[mid] < x) {  // Fixed syntax error
                floor = nums[mid];
                st = mid + 1;
            } else {
                ceil = nums[mid];
                end = mid - 1;
            }
        }
        return {floor, ceil};
    }
};

int main() {
    Solution sol;
    
    // Test case 1: Element exists in middle
    vector<int> nums1 = {1, 2, 8, 10, 10, 12, 19};
    int x1 = 10;
    pair<int, int> result1 = sol.getFloorAndCeil(nums1, x1);
    cout << "Array: ";
    for (int num : nums1) cout << num << " ";
    cout << "\nFloor and Ceil of " << x1 << ": ";
    cout << "Floor = " << result1.first << ", Ceil = " << result1.second << endl;
    
    // Test case 2: Element doesn't exist
    int x2 = 5;
    pair<int, int> result2 = sol.getFloorAndCeil(nums1, x2);
    cout << "\nFloor and Ceil of " << x2 << ": ";
    cout << "Floor = " << result2.first << ", Ceil = " << result2.second << endl;
    
    // Test case 3: Element smaller than all
    int x3 = 0;
    pair<int, int> result3 = sol.getFloorAndCeil(nums1, x3);
    cout << "\nFloor and Ceil of " << x3 << ": ";
    cout << "Floor = " << result3.first << ", Ceil = " << result3.second << endl;
    
    // Test case 4: Element larger than all
    int x4 = 25;
    pair<int, int> result4 = sol.getFloorAndCeil(nums1, x4);
    cout << "\nFloor and Ceil of " << x4 << ": ";
    cout << "Floor = " << result4.first << ", Ceil = " << result4.second << endl;
    
    // Test case 5: Single element
    vector<int> nums2 = {5};
    int x5 = 5;
    pair<int, int> result5 = sol.getFloorAndCeil(nums2, x5);
    cout << "\nArray: ";
    for (int num : nums2) cout << num << " ";
    cout << "\nFloor and Ceil of " << x5 << ": ";
    cout << "Floor = " << result5.first << ", Ceil = " << result5.second << endl;
    
    // Test case 6: Empty array
    vector<int> nums3 = {};
    int x6 = 5;
    pair<int, int> result6 = sol.getFloorAndCeil(nums3, x6);
    cout << "\nEmpty array - Floor and Ceil of " << x6 << ": ";
    cout << "Floor = " << result6.first << ", Ceil = " << result6.second << endl;
    
    return 0;
}