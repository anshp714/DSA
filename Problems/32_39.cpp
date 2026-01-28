#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    set<vector<int>> s;

    void comSum(vector<int>& arr, int i, vector<int>& comb, vector<vector<int>>& ans, int tar) {
        if(tar == 0) {
            if(s.find(comb) == s.end()) {
                ans.push_back(comb);
                s.insert(comb);
            }
            return;
        }

        if(i == arr.size() || tar < 0) return;

        comb.push_back(arr[i]);
        comSum(arr, i + 1, comb, ans, tar - arr[i]);
        comSum(arr, i, comb, ans, tar - arr[i]);
        comb.pop_back();
        comSum(arr, i + 1, comb, ans, tar);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> comb;
        comSum(arr, 0, comb, ans, tar);
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
    vector<int> arr1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = sol.combinationSum(arr1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Input: candidates = [2, 3, 6, 7], target = " << target1 << endl;
    cout << "Output: ";
    printResult(result1);
    cout << endl;
    cout << "Expected: [[2, 2, 3], [7]]" << endl << endl;
    
    // Test Case 2
    vector<int> arr2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> result2 = sol.combinationSum(arr2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Input: candidates = [2, 3, 5], target = " << target2 << endl;
    cout << "Output: ";
    printResult(result2);
    cout << endl;
    cout << "Expected: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]" << endl << endl;
    
    // Test Case 3
    vector<int> arr3 = {2};
    int target3 = 1;
    vector<vector<int>> result3 = sol.combinationSum(arr3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Input: candidates = [2], target = " << target3 << endl;
    cout << "Output: ";
    printResult(result3);
    cout << endl;
    cout << "Expected: []" << endl;
    
    return 0;
}