#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot =-1,n = nums.size();

        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        if(pivot== -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i= n-1;n>pivot;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        int i = pivot+1, j = n-1;
        while(i<= j){
            swap(nums[i++],nums[j--]);
        }

   
    }
};

// Helper function to print vector
void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(nums1);
    sol.nextPermutation(nums1);
    cout << " -> Output: ";
    printVector(nums1);
    cout << endl;
    
    // Test Case 2
    vector<int> nums2 = {3, 2, 1};
    cout << "\nTest Case 2:" << endl;
    cout << "Input: ";
    printVector(nums2);
    sol.nextPermutation(nums2);
    cout << " -> Output: ";
    printVector(nums2);
    cout << endl;
    
    // Test Case 3
    vector<int> nums3 = {1, 1, 5};
    cout << "\nTest Case 3:" << endl;
    cout << "Input: ";
    printVector(nums3);
    sol.nextPermutation(nums3);
    cout << " -> Output: ";
    printVector(nums3);
    cout << endl;
    
    return 0;
}