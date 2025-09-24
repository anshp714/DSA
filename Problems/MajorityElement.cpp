#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach O(n^2)
int majorityElement(vector<int>& nums){
    for(int val : nums){
        int freq = 0;
        for(int ele : nums){
            if(ele == val){
                freq++;
            }
        }
        if(freq > nums.size()/2){
            return val;
        }
    }
    return -1; 
}

// Optimal Approach O(n) using Moore's Voting Algorithm
int majorityElementOptimal(vector<int>& nums){
    int freq = 0;
    int ans = 0;
    for(int val : nums){
        if(freq == 0){
           ans = val;
        }
        if(ans == val){
           freq++;
        } else {
            freq--;
    }
}
return ans;
}
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    int result = majorityElement(nums);
    cout << "Majority element: " << result << endl;

    int optimalResult = majorityElementOptimal(nums);
    cout << "Majority element (Optimal): " << optimalResult << endl;

    return 0;
}
