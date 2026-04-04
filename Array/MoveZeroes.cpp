#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
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
    
    // Test Case 1: Standard case with zeros at different positions
    {
        cout << "Test Case 1: [0, 1, 0, 3, 12]" << endl;
        vector<int> nums = {0, 1, 0, 3, 12};
        cout << "Original: ";
        printVector(nums);
        cout << endl;
        
        sol.moveZeroes(nums);
        
        cout << "After moving zeros: ";
        printVector(nums);
        cout << endl;
        cout << "Expected: [1, 3, 12, 0, 0]" << endl << endl;
    }
    
    // Test Case 2: All zeros
    {
        cout << "Test Case 2: [0, 0, 0, 0, 0]" << endl;
        vector<int> nums = {0, 0, 0, 0, 0};
        cout << "Original: ";
        printVector(nums);
        cout << endl;
        
        sol.moveZeroes(nums);
        
        cout << "After moving zeros: ";
        printVector(nums);
        cout << endl;
        cout << "Expected: [0, 0, 0, 0, 0]" << endl << endl;
    }
    
    // Test Case 3: No zeros
    {
        cout << "Test Case 3: [1, 2, 3, 4, 5]" << endl;
        vector<int> nums = {1, 2, 3, 4, 5};
        cout << "Original: ";
        printVector(nums);
        cout << endl;
        
        sol.moveZeroes(nums);
        
        cout << "After moving zeros: ";
        printVector(nums);
        cout << endl;
        cout << "Expected: [1, 2, 3, 4, 5]" << endl;
    }
    
    return 0;
}