#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int r = 0, c = n - 1;

        while(r < m && c >= 0) {
            if(target == mat[r][c]) {
                return true;
            } else if(target < mat[r][c]) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};

// Helper function to print matrix
void printMatrix(const vector<vector<int>>& mat) {
    cout << "[";
    for(int i = 0; i < mat.size(); i++) {
        cout << "[";
        for(int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j];
            if(j != mat[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i != mat.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1: Target found
    vector<vector<int>> mat1 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target1 = 5;
    bool result1 = sol.searchMatrix(mat1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Matrix: ";
    printMatrix(mat1);
    cout << endl;
    cout << "Target: " << target1 << endl;
    cout << "Result: " << (result1 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 2: Target not found
    vector<vector<int>> mat2 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target2 = 20;
    bool result2 = sol.searchMatrix(mat2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Matrix: ";
    printMatrix(mat2);
    cout << endl;
    cout << "Target: " << target2 << endl;
    cout << "Result: " << (result2 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 3: Single row matrix
    vector<vector<int>> mat3 = {
        {1, 3, 5, 7, 9}
    };
    int target3 = 7;
    bool result3 = sol.searchMatrix(mat3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Matrix: ";
    printMatrix(mat3);
    cout << endl;
    cout << "Target: " << target3 << endl;
    cout << "Result: " << (result3 ? "true" : "false") << endl;
    
    return 0;
}