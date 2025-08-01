#include <iostream>
using namespace std;

int main(){

    int n = 4;

//Top half of the diamond

    for(int i=0;i<n; i++){

        //Spaces1
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<< "*";

        if(i!=0){

        //spaces2
        for(int k=0;k<2*i-1;k++){
            cout<<" ";
        }

            cout<<"*";
        }

        cout<<endl;
    }
// Bottom half of the diamond

    for(int i=0;i<n-1;i++){

        //spaces1
        for(int j=0;j<i+1;j++){
            cout<<" ";
        }

        cout << "*";
        if(i != n-2){
        //spaces2
        for(int k=0;k<2*(n-i)-5;k++){
            cout<<" ";
        }

            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}
// Output:
//    *
//   * *
//  *   *
// *     *
//  *   *
//   * *
//    *