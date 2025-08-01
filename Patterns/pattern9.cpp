#include <iostream>
using namespace std;

int main(){

    int n = 4;

    for(int i=0; i<n; i++){

        //Spaces
        for(int j=0; j<n-i-1; j++){
            cout << " "; 
        }

        //left half of the pattern
        for(int k=1; k<=i+1; k++){
            cout << k;
        }

        //right half of the pattern
        for(int k=i; k>0; k--){
            cout << k;
        }
        cout << endl; // Move to the next line after each row
    }

    return 0;
}
// Output:
//    1
//   121
//  12321
// 1234321