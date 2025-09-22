#include <iostream>
using namespace std;

void ReverseNumber(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}
int main() {
    int arr[] = {5, 15, 22, 1, -15, 12};
    int size = 6;

    ReverseNumber(arr, size);
    
    cout<< "reversed array ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    


    return 0;
}