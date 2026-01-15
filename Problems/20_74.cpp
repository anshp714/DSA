#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchInrow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[0].size();
        int st = 0, end = n - 1;
        
        while(st <= end) {
            int mid = st + (end - st) / 2;
            if(target == mat[row][mid]) {
                return true;
            } else if(target > mat[row][mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int stR = 0, endR = m - 1;
        while(stR <= endR) {
            int midR = stR + (endR - stR) / 2;
            if(target >= mat[midR][0] && target <= mat[midR][n - 1]) {
                return searchInrow(mat, target, midR);
            } else if(target >= mat[midR][n - 1]) {
                stR = midR + 1;
            } else {
                endR = midR - 1;
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
    
    // Test Case 1
    vector<vector<int>> mat1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target1 = 3;
    bool result1 = sol.searchMatrix(mat1, target1);
    cout << "Test Case 1:" << endl;
    cout << "Matrix: ";
    printMatrix(mat1);
    cout << endl;
    cout << "Target: " << target1 << endl;
    cout << "Result: " << (result1 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 2
    vector<vector<int>> mat2 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target2 = 13;
    bool result2 = sol.searchMatrix(mat2, target2);
    cout << "Test Case 2:" << endl;
    cout << "Matrix: ";
    printMatrix(mat2);
    cout << endl;
    cout << "Target: " << target2 << endl;
    cout << "Result: " << (result2 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 3
    vector<vector<int>> mat3 = {
        {1, 3}
    };
    int target3 = 3;
    bool result3 = sol.searchMatrix(mat3, target3);
    cout << "Test Case 3:" << endl;
    cout << "Matrix: ";
    printMatrix(mat3);
    cout << endl;
    cout << "Target: " << target3 << endl;
    cout << "Result: " << (result3 ? "true" : "false") << endl;
    
    return 0;
}