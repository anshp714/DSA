#include <iostream>
using namespace std;

int main(){

    signed int a = 10;
    unsigned int b = -20;
    signed int c = -10;
    unsigned int d = 20;
    cout<< sizeof(int) << " bytes" << endl; // Output: 4 bytes
    cout<< sizeof(long int) << " bytes" << endl;
    cout<< sizeof(short int) << " bytes" << endl;
    cout<< sizeof(long long int) << " bytes" << endl;
    cout<< a<< " is signed integer" << endl; // Output: 10 is signed integer
    cout<< b<< " is unsigned integer" << endl; 
    cout<< c<< " is signed integer" << endl; // Output: -10 is signed integer
    cout<< d<< " is unsigned integer" << endl; // Output: 20 is
    return 0;
}