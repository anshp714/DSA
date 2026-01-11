#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "daabcbaabcbc";
    string part1 = "abc";
    string result1 = sol.removeOccurrences(s1, part1);
    cout << "Test Case 1:" << endl;
    cout << "s = \"" << s1 << "\", part = \"" << part1 << "\"" << endl;
    cout << "Result: \"" << result1 << "\"" << endl;
    cout << endl;
    
    // Test Case 2
    string s2 = "axxxxyyyyb";
    string part2 = "xy";
    string result2 = sol.removeOccurrences(s2, part2);
    cout << "Test Case 2:" << endl;
    cout << "s = \"" << s2 << "\", part = \"" << part2 << "\"" << endl;
    cout << "Result: \"" << result2 << "\"" << endl;
    cout << endl;
    
    // Test Case 3
    string s3 = "aabababa";
    string part3 = "aba";
    string result3 = sol.removeOccurrences(s3, part3);
    cout << "Test Case 3:" << endl;
    cout << "s = \"" << s3 << "\", part = \"" << part3 << "\"" << endl;
    cout << "Result: \"" << result3 << "\"" << endl;
    
    return 0;
}