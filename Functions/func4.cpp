//BINOMIAL COEFFICIENTS
// This program calculates the binomial coefficient nCr using factorials.

#include <iostream>
using namespace std;

int factR(int r){
     int fact = 1;
     for(int i = 1; i <= r; i++){
         fact *= i;
     }
     return fact;
}

int factN(int n){
     int fact = 1;
     for(int i = 1; i <= n; i++){
         fact *= i;
     }
     return fact;
}

int nCr(int n, int r){
    if (r > n) {
        return 0; // nCr is not defined for r > n
    }
    return factN(n) / (factN(r) * factN(n - r));
}


int main(){
    cout << nCr(5, 2) << endl; // Output: 10
    return 0;
}
