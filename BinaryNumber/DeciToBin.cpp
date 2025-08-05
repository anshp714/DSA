#include <iostream>
using namespace std;

int DeciToBin(int deciNum){
    int ans= 0;
    int pow = 1;
    while(deciNum > 0){
        int rem = deciNum % 2;
        deciNum /= 2;
        ans += rem * pow;
        pow *= 10;
    }
    return ans;
}

int main(){
    for(int i = 0; i < 10; i++){
    cout<< DeciToBin(i) <<", "; // Output: 0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001,
    }
    return 0;
}

