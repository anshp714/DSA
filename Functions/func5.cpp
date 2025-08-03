// FUBONACCI SERIES
// This program prints the Fibonacci series up to n terms.

#include <iostream>
using namespace std;

void printFibonacci(int n) {
    int a = 0, b = 1;
    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    printFibonacci(10); // Output: 0 1 1 2 3 5 8 13 21 34
    return 0;
}
