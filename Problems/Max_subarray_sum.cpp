#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = { -2,1,-3,4,-1,2,1,-5,4};
    int n = 9;
    int maxSum = INT_MIN;

    // Brute Force Approach O(n^2)
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
        
    }
    cout << maxSum << endl;

    //Kadane's Algorithm O(n)
        int currSum = 0;
 
        for(int i = 0; i<n; i++){
            currSum += arr[i];
            maxSum = max(currSum,maxSum);
            if(currSum < 0){
                currSum = 0;
            }
        }
        cout << maxSum << endl;

}