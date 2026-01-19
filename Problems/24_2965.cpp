#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> s;
        int n = grid.size();
        int a, b;

        int expSum = 0, actualSum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expSum = (n * n) * (n * n + 1) / 2;
        b = expSum + a - actualSum;
        ans.push_back(b);

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
    vector<vector<int>> grid1 = {
        {1, 3},
        {2, 2}
    };
    vector<int> result1 = sol.findMissingAndRepeatedValues(grid1);
    cout << "Test Case 1:" << endl;
    cout << "Input grid:" << endl;
    for(auto& row : grid1) {
        cout << "  ";
        printVector(row);
        cout << endl;
    }
    cout << "Output: ";
    printVector(result1);
    cout << " (Expected: [2, 4] or [repeated, missing])" << endl << endl;
    
    // Test Case 2
    vector<vector<int>> grid2 = {
        {9, 1, 7},
        {8, 9, 4},
        {3, 2, 6}
    };
    vector<int> result2 = sol.findMissingAndRepeatedValues(grid2);
    cout << "Test Case 2:" << endl;
    cout << "Input grid:" << endl;
    for(auto& row : grid2) {
        cout << "  ";
        printVector(row);
        cout << endl;
    }
    cout << "Output: ";
    printVector(result2);
    cout << " (Expected: [9, 5] or [repeated, missing])" << endl << endl;
    
    // Test Case 3
    vector<vector<int>> grid3 = {
        {1, 2},
        {3, 4}
    };
    vector<int> result3 = sol.findMissingAndRepeatedValues(grid3);
    cout << "Test Case 3:" << endl;
    cout << "Input grid:" << endl;
    for(auto& row : grid3) {
        cout << "  ";
        printVector(row);
        cout << endl;
    }
    cout << "Output: ";
    printVector(result3);
    cout << " (No repeated value - may cause issues)" << endl;
    
    return 0;
}