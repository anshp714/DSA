#include <iostream>
using namespace std;

int sumN(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    return sum;
}

int main(){
    cout << sumN(6) << endl; // Output: 21
    cout << sumN(10) << endl; // Output: 55
    cout << sumN(100) << endl; // Output: 5050
    return 0;
}