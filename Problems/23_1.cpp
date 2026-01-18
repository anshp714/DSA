#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int sec = tar - first;

            if(m.find(sec) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[sec]);
                break;
            }
            m[first] = i;
        }
        return ans;
    }
};

// Helper function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i != vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = ";
    printVector(nums1);
    cout << ", target = " << target1 << endl;
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    
    // Sort result for consistent output order
    sort(result1.begin(), result1.end());
    cout << "Sorted indices: ";
    printVector(result1);
    cout << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = ";
    printVector(nums2);
    cout << ", target = " << target2 << endl;
    cout << "Output: ";
    printVector(result2);
    cout << endl;
    
    // Sort result for consistent output order
    sort(result2.begin(), result2.end());
    cout << "Sorted indices: ";
    printVector(result2);
    cout << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = ";
    printVector(nums3);
    cout << ", target = " << target3 << endl;
    cout << "Output: ";
    printVector(result3);
    cout << endl;
    
    // Sort result for consistent output order
    sort(result3.begin(), result3.end());
    cout << "Sorted indices: ";
    printVector(result3);
    cout << endl;
    
    return 0;
}