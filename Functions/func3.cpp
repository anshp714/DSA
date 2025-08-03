// This program calculates the sum of digits of a number.

#include <iostream>
using namespace std;

int sumOfDigit(int num){
    int digitSum = 0;
    while(num>0){
        int lastDigit = num%10;
        num = num/10;
        digitSum += lastDigit;
    }
    return digitSum;
}

int main(){
    cout << sumOfDigit(4523) << endl; // Output: 14
    cout << sumOfDigit(909) << endl; // Output: 18
    cout << sumOfDigit(111) << endl; // Output: 3
    return 0;
}
