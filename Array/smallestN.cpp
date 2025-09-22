#include <iostream>
using namespace std;

int main(){
    int num[] = {5,15,22,1,-15,12};
    int size = 6;
    int smallest = INT_MAX;
    for(int i=0; i<size; i++){
        if(num[i] < smallest){
            smallest = num[i];
        }
    }
    cout << "Smallest number is: " << smallest << endl;
    return 0;
}