#include <bits/stdc++.h>
using namespace std;

// int solve(int** nums, int n, int* m, int* idx, int rem) {
//     int maxTasks = 0;
//     for(int i = 0; i < n; i++) {
//         if(idx[i] < m[i] && rem >= nums[i][idx[i]]) {
//             idx[i]++;
//             maxTasks = max(maxTasks, 1 + solve(nums, n, m, idx, rem - nums[i][idx[i]-1]));
//             idx[i]--;
//         }
//     }
//     return maxTasks;
// }

class Solution{
private:
    int** nums;
    int n;
    int* m;
    int* idx;
    int*** memo;

    void buildMemo(int n, int* m, int interval) {
        this->memo = new int**[n+1];
        for(int i=0;i<=n;i++) {
            this->memo[i] = new int*[m[i]+1];
            for(int j=0;j<=m[i];j++) {
                this->memo[i][j] = new int[interval+1];
                for(int k=0;k<=interval;k++) {
                    this->memo[i][j][k] = -1;
                }
            }
        }
    }
    
    int auxSolve(int job, int rem) {
        if(job == n || rem == 0) return 0;

        if(~memo[job][idx[job]][rem]) return memo[job][idx[job]][rem];
    
        int r1 = 0;
        if(idx[job] < m[job] && rem >= nums[job][idx[job]]){
            idx[job]++;
            r1 = 1 + auxSolve(job, rem - nums[job][idx[job]-1]);
            idx[job]--;
        }
    
        r1 = max(r1, auxSolve(job + 1, rem));
    
        return memo[job][idx[job]][rem] = r1;
    }

public:
    Solution(int** nums, int n, int* m) {
        this->nums = nums;
        this->n = n;
        this->m = m;
        this->idx = new int[n];
        for(int i = 0; i < n; i++) this->idx[i] = 0;
    }
    
    int solve(int interval) {
        buildMemo(n, m, interval);
        auxSolve(0, interval);
    }

    int* getIdx() {
        return this->idx;
    }
};

int main () {
    int n;
    cout << "Number of jobs= ";
    cin >> n;
    
    int** nums = new int*[n];
    int* m = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Number of instructions of job " << i << " = ";
        cin >> m[i];
        nums[i] = new int[m[i]];

        cout << "Job " << i << " instructions time = ";
        for(int j = 0; j < m[i]; j++) {
            cin >> nums[i][j];
        }
    }
    
    Solution s(nums, n, m);
    
    
    int interval;
    cout << "Interval = ";
    cin >> interval;
    while(interval > 0) {
        cout << s.solve(interval) << endl;

        cout << "Interval(0 to end) = ";
        cin >> interval;
    }

    return 0;
}