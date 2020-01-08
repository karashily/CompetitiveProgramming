#include <iostream>
#include <algorithm>
using namespace std;

int rod_cut_bottom(int n, int* prices) {
    int* memo = new int[n+1];
    memo[0] = 0;
    for(int i = 1; i < n + 1; i++) memo[i] = -1;
    for(int i = 1; i <= n; i++) {
        int r = -1;
        for(int j=1;j<=i;j++) {
            r = max(r, prices[j] + memo[i - j]);
        }
        memo[i] = r;
    }
    return memo[n];
}

int rod_cut_top_aux(int n, int* prices, int* memo) {
    if(n == 0) return 0;
    if(memo[n] != -1) return memo[n];
    int r = -1;
    for(int i = 0; i < n; i++) {
        r = max(r, rod_cut_top_aux(i, prices, memo) + prices[n-i]);
    }
    memo[n] = r;
    return r;
}

int rod_cut_top(int n, int* prices) {
    int* memo = new int[n+1];
    for(int i=0;i <= n; i++) memo[i] = -1;
    return rod_cut_top_aux(n, prices, memo);
}

int extended_rod_cut_bottom(int n, int* prices, int* cuts) {
    int* memo = new int[n+1];
    memo[0] = 0;
    for(int i = 1; i < n + 1; i++) memo[i] = -1;
    for(int i = 1; i <= n; i++) {
        int r = -1;
        for(int j = 1; j <= i; j++) {
            if (prices[j] + memo[i-j] > r) {
                r = prices[j] + memo[i-j];
                cuts[i] = j;
            }
        }
        memo[i] = r;
    }
    return memo[n];
}

int main() {
    int n = 5;
    int prices[] = {0,1,5,8,9,10,17,17,20,24,30};
    cout << rod_cut_top(n, prices) << endl;
    cout << rod_cut_bottom(n, prices) << endl;
    
    //extended version
    int* cuts = new int[n+1];
    for(int i = 0;i <= n; i++) cuts[i] = -1;
    cout << extended_rod_cut_bottom(n, prices, cuts) << endl;
    while(n>0) {
        cout << cuts[n] << " ";
        n = n - cuts[n];
    }
    return 0;
}