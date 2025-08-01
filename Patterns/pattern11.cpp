#include <iostream>
using namespace std;

int main(){

    int n = 4;

    //TOP LEFT 
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }

    //TOP RIGHT
        for(int j=2*(n-1-i);j>0;j--){
            cout<<" ";
        }
        for(int k=0;k<i+1;k++){
            cout<<"*";
        }
        cout<<endl;
    }

    //BOTTOM LEFT
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cout<<"*";
        }

    //BOTTON RIGHT
        for(int j=0;j<2*i;j++){
            cout<<" ";
        }
        for(int k=n;k>i;k--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
//output:
// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *