#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for(int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            while(i < n && ch == chars[i]) {
                count++;
                i++;
            }

            if(count == 1) {
                chars[idx++] = ch;
            } else {
                chars[idx++] = ch;
                string str = to_string(count);
                for(char dig : str) {
                    chars[idx++] = dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};

// Helper function to print vector
void printVector(const vector<char>& chars) {
    cout << "[";
    for (size_t i = 0; i < chars.size(); ++i) {
        cout << "'" << chars[i] << "'";
        if (i != chars.size() - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;
    
    // Test Case 1
    vector<char> chars1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    vector<char> original1 = chars1;
    int result1 = sol.compress(chars1);
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(original1);
    cout << endl;
    cout << "Compressed: ";
    printVector(chars1);
    cout << endl;
    cout << "New length: " << result1 << endl;
    cout << endl;
    
    // Test Case 2
    vector<char> chars2 = {'a'};
    vector<char> original2 = chars2;
    int result2 = sol.compress(chars2);
    cout << "Test Case 2:" << endl;
    cout << "Input: ";
    printVector(original2);
    cout << endl;
    cout << "Compressed: ";
    printVector(chars2);
    cout << endl;
    cout << "New length: " << result2 << endl;
    cout << endl;
    
    // Test Case 3
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    vector<char> original3 = chars3;
    int result3 = sol.compress(chars3);
    cout << "Test Case 3:" << endl;
    cout << "Input: ";
    printVector(original3);
    cout << endl;
    cout << "Compressed: ";
    printVector(chars3);
    cout << endl;
    cout << "New length: " << result3 << endl;
    
    return 0;
}