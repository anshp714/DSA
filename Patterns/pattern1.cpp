#include <iostream>
using namespace std;
/*int main(){
    int n = 4;

    for(int i=1; i<=n; i++){                  // * * * *
        for(int j=1; j<=n; j++){              // * * * *
            cout << "*" << " ";               // * * * *
        }                                     // * * * *
        cout << endl;
    }
    return 0;
}
*/
int main(){
    int n = 4;

    for(int i=1; i<=n; i++){                  // 1 2 3 4
        for(int j=1; j<=n; j++){              // 1 2 3 4
            cout << j << " ";                 // 1 2 3 4
        }                                     // 1 2 3 4
        cout << endl;
    }
    return 0;
}