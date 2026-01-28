#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int lar = INT_MIN;
        int sec = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > lar) {
                sec = lar;
                lar = nums[i];  // Fixed: changed arr[i] to nums[i]
            } else if(nums[i] > sec && nums[i] != lar) {
                sec = nums[i];  // Fixed: changed nums[i] = sec to sec = nums[i]
            }
        }
        
        if(sec == INT_MIN) {
            return -1;
        }
        return sec;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {12, 35, 1, 10, 34, 1};
    int result1 = sol.secondLargestElement(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [12, 35, 1, 10, 34, 1]" << endl;
    cout << "Second largest element: " << result1 << endl;
    cout << "Expected: 34" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {10, 10, 10};
    int result2 = sol.secondLargestElement(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [10, 10, 10]" << endl;
    cout << "Second largest element: " << result2 << endl;
    cout << "Expected: -1 (no second largest)" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {5};
    int result3 = sol.secondLargestElement(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [5]" << endl;
    cout << "Second largest element: " << result3 << endl;
    cout << "Expected: -1 (no second largest)" << endl;
    
    return 0;
}