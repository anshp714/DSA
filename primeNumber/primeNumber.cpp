#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool isPrime = true;

    /*for(int i= 2;i<= n-1; i++){
        if(n % i == 0){
            isPrime = false;
            break;
        }*/
    for(int i= 2;i*i<= n; i++){        //here we are checking only up to the square root of n
        if(n % i == 0){
            isPrime = false;
            break;
        }
    
    }

    if(isPrime){
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}