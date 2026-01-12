#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++) {
            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if(word.length() > 0) {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "the sky is blue";
    string result1 = sol.reverseWords(s1);
    cout << "Test Case 1:" << endl;
    cout << "Input: \"" << s1 << "\"" << endl;
    cout << "Output: \"" << result1 << "\"" << endl;
    cout << endl;
    
    // Test Case 2
    string s2 = "  hello world  ";
    string result2 = sol.reverseWords(s2);
    cout << "Test Case 2:" << endl;
    cout << "Input: \"" << s2 << "\"" << endl;
    cout << "Output: \"" << result2 << "\"" << endl;
    cout << endl;
    
    // Test Case 3
    string s3 = "a good   example";
    string result3 = sol.reverseWords(s3);
    cout << "Test Case 3:" << endl;
    cout << "Input: \"" << s3 << "\"" << endl;
    cout << "Output: \"" << result3 << "\"" << endl;
    
    return 0;
}