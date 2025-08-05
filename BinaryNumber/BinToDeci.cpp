#include <iostream>
using namespace std;

int binToDeci(int binNum){

    int ans = 0;
    int pow = 1;
    while(binNum > 0){
        int rem = binNum % 10;
        binNum /= 10;
        ans += rem * pow;
        pow *= 2;
    }
    return ans;
}

int main(){
    cout<<binToDeci(101010);
    return 0;
}
