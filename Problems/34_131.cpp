#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool ispalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    void getAll(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if(s.size() == 0) {
            ans.push_back(partition);
            return;
        }
        
        for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if(ispalindrome(part)) {
                partition.push_back(part);
                getAll(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        getAll(s, partition, ans);
        return ans;
    }
};

// Helper function to print result
void printResult(const vector<vector<string>>& result) {
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << "[";
        for(int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\"";
            if(j != result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i != result.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "aab";
    vector<vector<string>> result1 = sol.partition(s1);
    cout << "Test Case 1:" << endl;
    cout << "Input: s = \"aab\"" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << endl;
    cout << "Expected: [[\"a\",\"a\",\"b\"], [\"aa\",\"b\"]]" << endl << endl;
    
    // Test Case 2
    string s2 = "a";
    vector<vector<string>> result2 = sol.partition(s2);
    cout << "Test Case 2:" << endl;
    cout << "Input: s = \"a\"" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << endl;
    cout << "Expected: [[\"a\"]]" << endl << endl;
    
    // Test Case 3
    string s3 = "ababa";
    vector<vector<string>> result3 = sol.partition(s3);
    cout << "Test Case 3:" << endl;
    cout << "Input: s = \"ababa\"" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << endl;
    cout << "Expected various partitions including [[\"a\",\"b\",\"a\",\"b\",\"a\"], [\"a\",\"bab\",\"a\"], [\"aba\",\"ba\"], [\"ababa\"]] etc." << endl;
    
    return 0;
}