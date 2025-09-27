#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long binForm = n;
        if(n < 0){
            x = 1/x;
            binForm = -binForm;
        }

        double ans = 1;
        while(binForm > 0){
            if(binForm % 2 == 1){
                ans *= x;
            }
            x *= x;
            binForm /= 2;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    double x1 = 2.0;
    int n1 = 10;
    cout << fixed << setprecision(5);
    cout << x1 << " raised to the power " << n1 << " = " << solution.myPow(x1, n1) << endl;
    
    double x2 = 2.1;
    int n2 = 3;
    cout << x2 << " raised to the power " << n2 << " = " << solution.myPow(x2, n2) << endl;
    
    double x3 = 2.0;
    int n3 = -2;
    cout << x3 << " raised to the power " << n3 << " = " << solution.myPow(x3, n3) << endl;
    
    double x4 = 5.0;
    int n4 = 0;
    cout << x4 << " raised to the power " << n4 << " = " << solution.myPow(x4, n4) << endl;
    
    double x5 = 0.0;
    int n5 = 5;
    cout << x5 << " raised to the power " << n5 << " = " << solution.myPow(x5, n5) << endl;
    
    double x6 = 1.0;
    int n6 = 100;
    cout << x6 << " raised to the power " << n6 << " = " << solution.myPow(x6, n6) << endl;
    
    // Edge case: large exponent
    double x7 = 2.0;
    int n7 = -10;
    cout << x7 << " raised to the power " << n7 << " = " << solution.myPow(x7, n7) << endl;
    
    return 0;
}