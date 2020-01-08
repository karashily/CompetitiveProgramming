#include <iostream>
using namespace std;

int fib_bottom(int n) {
    int big = 1;
    int small = 1;
    for(int i = 2; i < n; i++) {
        int temp = big;
        big += small;
        small = temp;
    }
    return big;
}

int fib_top(int n, int* memo) {
    if(n == 1 || n == 2) {
        return 1;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fib_top(n-1, memo)+fib_top(n-2, memo);
    return memo[n];
}

int main () {

    int n = 30;
    int * memo = new int[n+2];
    for(int i = 0; i<n+2;i++) memo[i] = -1;
    cout << fib_bottom(n) << endl;
    cout << fib_top(n, memo) << endl;

    return 0;
}