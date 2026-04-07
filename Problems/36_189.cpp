#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Helper function to print vector
void printVector(const vector<int>& nums) {
    cout << "[";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i != nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1: Rotate by 3 positions
    {
        cout << "Test Case 1: Rotate [1, 2, 3, 4, 5, 6, 7] by 3" << endl;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        
        cout << "Original: ";
        printVector(nums);
        cout << endl;
        
        sol.rotate(nums, k);
        
        cout << "Rotated:  ";
        printVector(nums);
        cout << endl;
        cout << "Expected: [5, 6, 7, 1, 2, 3, 4]" << endl << endl;
    }
    
    // Test Case 2: Rotate by 2 positions
    {
        cout << "Test Case 2: Rotate [-1, -100, 3, 99] by 2" << endl;
        vector<int> nums = {-1, -100, 3, 99};
        int k = 2;
        
        cout << "Original: ";
        printVector(nums);
        cout << endl;
        
        sol.rotate(nums, k);
        
        cout << "Rotated:  ";
        printVector(nums);
        cout << endl;
        cout << "Expected: [3, 99, -1, -100]" << endl << endl;
    }
    
    // Test Case 3: Rotate when k > n
    {
        cout << "Test Case 3: Rotate [1, 2, 3, 4, 5] by 7 (k > n)" << endl;
        vector<int> nums = {1, 2, 3, 4, 5};
        int k = 7;
        
        cout << "Original: ";
        printVector(nums);
        cout << endl;
        
        sol.rotate(nums, k);
        
        cout << "Rotated:  ";
        printVector(nums);
        cout << endl;
        cout << "Expected: [4, 5, 1, 2, 3] (since 7 % 5 = 2)" << endl;
    }
    
    return 0;
}