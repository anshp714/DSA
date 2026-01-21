#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) {
                    j++;
                } else if(sum > 0) {
                    k--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                }
            }
        }
        return ans;
    }
};

// Helper function to print vector of vectors
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << "[";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if(j != result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i != result.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = sol.threeSum(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [-1, 0, 1, 2, -1, -4]" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 1, 1};
    vector<vector<int>> result2 = sol.threeSum(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [0, 1, 1]" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> result3 = sol.threeSum(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [0, 0, 0]" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << endl;
    
    return 0;
}