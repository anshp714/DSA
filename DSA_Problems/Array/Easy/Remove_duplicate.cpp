#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {      //slow - fast pointer approach
        if(nums.size() == 0) return 0;
        
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        } 
        return i + 1;  
    }
};

// Helper function to print vector
void printVector(const vector<int>& nums, int size) {
    cout << "[";
    for(int i = 0; i < size; i++) {
        cout << nums[i];
        if(i != size - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 1, 2};
    vector<int> original1 = nums1;
    int result1 = sol.removeDuplicates(nums1);
    cout << "Test Case 1:" << endl;
    cout << "Input: nums = [1, 1, 2]" << endl;
    cout << "Output: " << result1 << ", nums = ";
    printVector(nums1, result1);
    cout << endl;
    cout << "Expected: 2, nums = [1, 2]" << endl << endl;
    
    // Test Case 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> original2 = nums2;
    int result2 = sol.removeDuplicates(nums2);
    cout << "Test Case 2:" << endl;
    cout << "Input: nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]" << endl;
    cout << "Output: " << result2 << ", nums = ";
    printVector(nums2, result2);
    cout << endl;
    cout << "Expected: 5, nums = [0, 1, 2, 3, 4]" << endl << endl;
    
    // Test Case 3
    vector<int> nums3 = {};
    vector<int> original3 = nums3;
    int result3 = sol.removeDuplicates(nums3);
    cout << "Test Case 3:" << endl;
    cout << "Input: nums = []" << endl;
    cout << "Output: " << result3 << ", nums = ";
    printVector(nums3, result3);
    cout << endl;
    cout << "Expected: 0, nums = []" << endl;
    
    return 0;
}