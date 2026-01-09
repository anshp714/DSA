#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0, end = s.size()-1;
        while(st < end){
            swap(s[st],s[end]);
            st++;
            end--;
        }
        
    }
};

// Helper function to print vector
void printVector(const vector<char>& s) {
    cout << "[";
    for (size_t i = 0; i < s.size(); ++i) {
        cout << "'" << s[i] << "'";
        if (i != s.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(s1);
    sol.reverseString(s1);
    cout << " -> Output: ";
    printVector(s1);
    cout << endl;
    
    // Test Case 2
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    cout << "\nTest Case 2:" << endl;
    cout << "Input: ";
    printVector(s2);
    sol.reverseString(s2);
    cout << " -> Output: ";
    printVector(s2);
    cout << endl;
    
    // Test Case 3
    vector<char> s3 = {'a', 'b', 'c', 'd'};
    cout << "\nTest Case 3:" << endl;
    cout << "Input: ";
    printVector(s3);
    sol.reverseString(s3);
    cout << " -> Output: ";
    printVector(s3);
    cout << endl;
    
    return 0;
}