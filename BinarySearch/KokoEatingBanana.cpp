#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int maxi(vector<int>& piles) {
        int maxi = INT_MIN;
        for(int x : piles) {
            maxi = max(maxi, x);
        }
        return maxi;
    }

    long long thrs(vector<int>& piles, int speed) {
        long long hrs = 0;

        for(int x : piles) {
            hrs += (x + speed - 1) / speed;  // integer ceiling
        }

        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxi(piles);

        while(low <= high) {
            int mid = low + (high - low) / 2;

            long long totalhrs = thrs(piles, mid);

            if(totalhrs <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    {
        cout << "Test Case 1:" << endl;
        vector<int> piles = {3, 6, 7, 11};
        int h = 8;
        
        cout << "Piles: [3, 6, 7, 11], h = " << h << endl;
        int result = sol.minEatingSpeed(piles, h);
        cout << "Minimum eating speed: " << result << endl;
        cout << "Expected: 4" << endl << endl;
    }
    
    // Test Case 2
    {
        cout << "Test Case 2:" << endl;
        vector<int> piles = {30, 11, 23, 4, 20};
        int h = 5;
        
        cout << "Piles: [30, 11, 23, 4, 20], h = " << h << endl;
        int result = sol.minEatingSpeed(piles, h);
        cout << "Minimum eating speed: " << result << endl;
        cout << "Expected: 30" << endl << endl;
    }
    
    // Test Case 3
    {
        cout << "Test Case 3:" << endl;
        vector<int> piles = {30, 11, 23, 4, 20};
        int h = 6;
        
        cout << "Piles: [30, 11, 23, 4, 20], h = " << h << endl;
        int result = sol.minEatingSpeed(piles, h);
        cout << "Minimum eating speed: " << result << endl;
        cout << "Expected: 23" << endl;
    }
    
    return 0;
}