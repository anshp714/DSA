#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

// Brute Force

int maxArea1(vector<int>& height) {
    int maxWater = 0;

    for (size_t i = 0; i < height.size(); i++) {
        for (size_t j = i + 1; j < height.size(); j++) {
            int w = j - i;
            int ht = std::min(height[i], height[j]);
            int currWater = w * ht; 

            maxWater = max(maxWater, currWater);
        }
    }
    return maxWater;
}

// Optimal Approach - Two Pointer Approach

int maxArea(vector<int>& height) {
    int maxWater = 0;
    int lp = 0;
    int rp = height.size()-1;

    while(lp<rp){
        int w = rp-lp;
        int ht = min(height[rp],height[lp]);
        int currWater = w*ht;
        maxWater = max(maxWater,currWater);
            
        height[lp]<height[rp]?lp++:rp--;
    }
    return maxWater;

}

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = maxArea(height);
    cout << "The maximum area is: " << result << std::endl; 
    return 0;
}