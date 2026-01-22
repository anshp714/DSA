#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            // Skip duplicates for i
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < n; j++) {
                // Skip duplicates for j (Ensure j > i+1 to avoid checking i against j)
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int p = j + 1;
                int q = n - 1;

                while(p < q) {
                    long long sum = (long long)nums[i] + (long long)nums[j] + 
                                    (long long)nums[p] + (long long)nums[q];

                    if(sum < target) {
                        p++;
                    } else if(sum > target) {
                        q--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // Skip duplicates for p
                        while(p < q && nums[p] == nums[p-1]) p++;
                        // Skip duplicates for q
                        while(p < q && nums[q] == nums[q+1]) q--;
                    }
                }
            }
        }
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
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = sol.fourSum(nums1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1, 0, -1, 0, -2, 2], target = " << target1 << endl;
    cout << "Output: ";
    printResult(result1);
    cout << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    vector<vector<int>> result2 = sol.fourSum(nums2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [2, 2, 2, 2, 2], target = " << target2 << endl;
    cout << "Output: ";
    printResult(result2);
    cout << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {1000000000, 1000000000, 1000000000, 1000000000};
    int target3 = 0;
    vector<vector<int>> result3 = sol.fourSum(nums3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = [1000000000, 1000000000, 1000000000, 1000000000], target = " << target3 << endl;
    cout << "Output: ";
    printResult(result3);
    cout << endl;
    
    return 0;
}