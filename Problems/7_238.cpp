#include <iostream>
#include <vector>
#include <numeric>

// FIX: Declare the use of the std namespace globally here
using namespace std; 

class Solution {
public:
    // Now 'vector' is recognized
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }
        
        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

// Now 'vector' and 'cout' are recognized
void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

int main() {
    // The previous 'using namespace std;' was here, which was too late.
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    
    // The productExceptSelf function is now a recognized member of Solution
    vector<int> result = sol.productExceptSelf(nums);

    cout << "Input Array: ";
    // printVector now takes the correct type: const vector<int>&
    printVector(nums);
    
    cout << "Product Except Self: ";
    printVector(result); 

    return 0;
}