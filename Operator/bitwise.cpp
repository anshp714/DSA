#include <iostream>
using namespace std;

int main(){
    int a = 4;
    int b = 8;
    cout << "Bitwise AND: " << (a & b) << endl; // Output: 0
    cout << "Bitwise OR: " << (a | b) << endl;  // Output: 12
    cout << "Bitwise XOR: " << (a ^ b) << endl; // Output: 12
    cout << "Left Shift: " << (a<<1) << endl; // Output: 8
    cout << "Right Shift: " << (a>>1) << endl; // Output: 2
    return 0;
}