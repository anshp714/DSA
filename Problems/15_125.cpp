#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isAlphaNum(char ch){
        if(ch >= '0' && ch<= '9' ||
        tolower(ch) >= 'a' && tolower(ch) <= 'z' ){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int st = 0, end = s.length()-1;

        while(st<end){
            if(!isAlphaNum(s[st])){
                st++; continue;
            }
            if(!isAlphaNum(s[end])){
                end--; continue;
            }

            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++;
            end--;
        } 
        return true;  
    }
};

int main() {
    Solution sol;
    
    // Test Case 1: Valid palindrome with spaces and punctuation
    string test1 = "A man, a plan, a canal: Panama";
    bool result1 = sol.isPalindrome(test1);
    cout << "Test Case 1: \"" << test1 << "\"" << endl;
    cout << "Is palindrome? " << (result1 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 2: Not a palindrome
    string test2 = "race a car";
    bool result2 = sol.isPalindrome(test2);
    cout << "Test Case 2: \"" << test2 << "\"" << endl;
    cout << "Is palindrome? " << (result2 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 3: Empty string
    string test3 = "";
    bool result3 = sol.isPalindrome(test3);
    cout << "Test Case 3: \"" << test3 << "\"" << endl;
    cout << "Is palindrome? " << (result3 ? "true" : "false") << endl;
    
    return 0;
}