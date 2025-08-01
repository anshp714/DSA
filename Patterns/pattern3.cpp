#include <iostream>
using namespace std;

int main(){
    int n = 3;
    char ch = 'A';
    int num = 1;
    for(int i=0; i<n; i++){                  
        for(int j=0; j<n; j++){              
            cout << ch << " ";                
            ch++;
        }                                    
        cout << endl;
    }
    cout << " after pattern:"<<(int)ch<< endl;
    return 0;
}
// Output:
// 1 2 3
// 4 5 6
// 7 8 9
// after pattern:10

