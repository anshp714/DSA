// This program calculates the factorial of a number using a loop.

#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = 1; i<=n ; i++){
        fact *=i;
    }
    return fact;
}
int main(){
    cout << factorial(5) << endl; // Output: 120
    cout << factorial(6) << endl; // Output: 720
    cout << factorial(7) << endl; // Output: 5040
    return 0;
}