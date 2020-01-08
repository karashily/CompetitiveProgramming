#include <iostream>
#include <algorithm>
using namespace std;

int mat_chain_mul_aux(int* nums, int start, int end, int** memo) {
    if(end - start == 3) {
        return nums[start] * nums[start+1] * nums[end-1];
    }
    if(end - start < 3) return 0;
    if(memo[start][end] != -1) return memo[start][end];
    int r = 1e9;
    for(int i = start + 1; i < end - 1; i++) {
        r = min(r, mat_chain_mul_aux(nums, start, i + 1, memo) + mat_chain_mul_aux(nums, i, end, memo) + nums[start] * nums[i] * nums[end - 1]);
    }
    return r;
}

int mat_chain_mul(int* nums, int n) {
    int** memo = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        memo[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) memo[i][j] = -1;
    }
    return mat_chain_mul_aux(nums, 0, n, memo);
}

int main() {
    int nums[] = {10, 100, 5, 50};
    int n = 4;
    cout << mat_chain_mul(nums, n);
    return 0;
}