#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        vector<int> ans;
        
        while(srow <= erow && scol <= ecol) {
            // top
            for(int j = scol; j <= ecol; j++) {
                ans.push_back(mat[srow][j]);
            }
            // right
            for(int i = srow + 1; i <= erow; i++) {
                ans.push_back(mat[i][ecol]);
            }
            // bottom
            for(int j = ecol - 1; j >= scol; j--) {
                if(erow == srow) {
                    break;
                }
                ans.push_back(mat[erow][j]);
            }
            // left
            for(int i = erow - 1; i >= srow + 1; i--) {
                if(ecol == scol) {
                    break;
                }
                ans.push_back(mat[i][scol]);
            }
            srow++; erow--; scol++; ecol--;
        }
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
    
    // Test Case 1: 3x3 matrix
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> result1 = sol.spiralOrder(mat1);
    cout << "Test Case 1:" << endl;
    cout << "Matrix:" << endl;
    for(auto& row : mat1) {
        cout << "  ";
        printVector(row);
        cout << endl;
    }
    cout << "Spiral order: ";
    printVector(result1);
    cout << endl << endl;
    
    // Test Case 2: 3x4 matrix
    vector<vector<int>> mat2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result2 = sol.spiralOrder(mat2);
    cout << "Test Case 2:" << endl;
    cout << "Matrix:" << endl;
    for(auto& row : mat2) {
        cout << "  ";
        printVector(row);
        cout << endl;
    }
    cout << "Spiral order: ";
    printVector(result2);
    cout << endl << endl;
    
    // Test Case 3: 1x5 matrix
    vector<vector<int>> mat3 = {
        {1, 2, 3, 4, 5}
    };
    vector<int> result3 = sol.spiralOrder(mat3);
    cout << "Test Case 3:" << endl;
    cout << "Matrix:" << endl;
    for(auto& row : mat3) {
        cout << "  ";
        printVector(row);
        cout << endl;
    }
    cout << "Spiral order: ";
    printVector(result3);
    cout << endl;
    
    return 0;
}