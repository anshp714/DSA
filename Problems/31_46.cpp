#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void perm(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            perm(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);  // backtrack
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(nums, 0, ans);
        return ans;
    }
};

// Helper function to print result
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
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = sol.permute(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1, 2, 3]" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << endl;
    cout << "Number of permutations: " << result1.size() << endl;
    cout << "Expected: 6 permutations" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 1};
    vector<vector<int>> result2 = sol.permute(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [0, 1]" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << endl;
    cout << "Number of permutations: " << result2.size() << endl;
    cout << "Expected: 2 permutations" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1};
    vector<vector<int>> result3 = sol.permute(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [1]" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << endl;
    cout << "Number of permutations: " << result3.size() << endl;
    cout << "Expected: 1 permutation" << endl;
    
    return 0;
}