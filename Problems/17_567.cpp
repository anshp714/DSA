#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();

        for(int i = 0; i < s2.length(); i++) {
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};

            while(windIdx < windSize && idx < s2.length()) {
                windFreq[s2[idx] - 'a']++;
                windIdx++;
                idx++;
            }
            if(isFreqSame(freq, windFreq)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string s1_1 = "ab";
    string s2_1 = "eidbaooo";
    bool result1 = sol.checkInclusion(s1_1, s2_1);
    cout << "Test Case 1:" << endl;
    cout << "s1 = \"" << s1_1 << "\", s2 = \"" << s2_1 << "\"" << endl;
    cout << "Result: " << (result1 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 2
    string s1_2 = "ab";
    string s2_2 = "eidboaoo";
    bool result2 = sol.checkInclusion(s1_2, s2_2);
    cout << "Test Case 2:" << endl;
    cout << "s1 = \"" << s1_2 << "\", s2 = \"" << s2_2 << "\"" << endl;
    cout << "Result: " << (result2 ? "true" : "false") << endl;
    cout << endl;
    
    // Test Case 3
    string s1_3 = "abc";
    string s2_3 = "ccccbbbbaaaa";
    bool result3 = sol.checkInclusion(s1_3, s2_3);
    cout << "Test Case 3:" << endl;
    cout << "s1 = \"" << s1_3 << "\", s2 = \"" << s2_3 << "\"" << endl;
    cout << "Result: " << (result3 ? "true" : "false") << endl;
    
    return 0;
}