#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;  //temporary array to store merged subarrays
    int i=st;          //starting index of left subarray
    int j=mid + 1;    //starting index of right subarray

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    //if there are remaining elements in left subarray
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }
    //copying elements from temporary array to original array
    for(int k=st; k<=end; k++){
        arr[k] = temp[k - st];
    }
}

void mergeSort(vector<int> &arr, int st, int end){
    if(st<end){
        int mid = st + (end - st)/2;
        mergeSort(arr, st, mid);         //left half
        mergeSort(arr, mid + 1, end);    //right half

        merge(arr, st, mid, end);
    }
}

int main(){
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, arr.size() - 1);

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}