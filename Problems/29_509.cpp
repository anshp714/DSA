#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 2;
    int result1 = sol.fib(n1);
    cout << "Test Case 1:" << endl;
    cout << "fib(" << n1 << ") = " << result1 << endl;
    cout << "Expected: 1" << endl << endl;
    
    // Test Case 2
    int n2 = 5;
    int result2 = sol.fib(n2);
    cout << "Test Case 2:" << endl;
    cout << "fib(" << n2 << ") = " << result2 << endl;
    cout << "Expected: 5" << endl << endl;
    
    // Test Case 3
    int n3 = 8;
    int result3 = sol.fib(n3);
    cout << "Test Case 3:" << endl;
    cout << "fib(" << n3 << ") = " << result3 << endl;
    cout << "Expected: 21" << endl;
    
    return 0;
}