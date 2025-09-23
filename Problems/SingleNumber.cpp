#include <iostream>
using namespace std;

int main() {
    int nums[] = {4, 1, 2, 1, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = ans ^ nums[i];
    }
    cout << ans << endl;
    return 0;
}