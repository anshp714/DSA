#include <iostream>
using namespace std;

int LinearSearch(int arr[],int size, int target){
    for(int i=0; i<size; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = {5,15,22,1,-15,12};
    int size = 6;
    int target = 34;

    cout << "Target found at index: " << LinearSearch(arr,size,target) << endl;
    return 0;
    
    
}