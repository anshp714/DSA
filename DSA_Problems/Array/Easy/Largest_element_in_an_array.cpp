#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int lar = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > lar) {
                lar = nums[i];  // Fixed: changed arr[i] to nums[i]
            }
        }
        return lar;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {3, 5, 2, 8, 1};
    int result1 = sol.largestElement(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [3, 5, 2, 8, 1]" << endl;
    cout << "Largest element: " << result1 << endl;
    cout << "Expected: 8" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {-5, -2, -8, -1};
    int result2 = sol.largestElement(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [-5, -2, -8, -1]" << endl;
    cout << "Largest element: " << result2 << endl;
    cout << "Expected: -1" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {7};
    int result3 = sol.largestElement(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [7]" << endl;
    cout << "Largest element: " << result3 << endl;
    cout << "Expected: 7" << endl;
    
    return 0;
}