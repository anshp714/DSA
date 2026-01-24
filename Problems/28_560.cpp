#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        unordered_map<int, int> m;
        for(int j = 0; j < n; j++) {
            if(prefixSum[j] == k) count++;
            
            int val = prefixSum[j] - k;
            if(m.find(val) != m.end()) {
                count += m[val];
            }
            
            m[prefixSum[j]]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    int result1 = sol.subarraySum(nums1, k1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1, 1, 1], k = " << k1 << endl;
    cout << "Output: " << result1 << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    int result2 = sol.subarraySum(nums2, k2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [1, 2, 3], k = " << k2 << endl;
    cout << "Output: " << result2 << endl;
    cout << "Expected: 2" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, -1, 0};
    int k3 = 0;
    int result3 = sol.subarraySum(nums3, k3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [1, -1, 0], k = " << k3 << endl;
    cout << "Output: " << result3 << endl;
    cout << "Expected: 3" << endl;
    
    return 0;
}