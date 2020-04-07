#include <iostream>
#include <algorithm>
#include <string>
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

class Solution {
private:
	int** nums;
	int n;
	int* m;
	int* idx;
	int*** ansMemo;
	int*** trans;


	void buildAnsMemo(int n, int* m, int interval) {
		this->ansMemo = new int** [n];
		this->trans = new int** [n];
		for (int i = 0; i < n; i++) {
			this->ansMemo[i] = new int* [m[i] + 1];
			this->trans[i] = new int* [m[i] + 1];
			for (int j = 0; j <= m[i]; j++) {
				this->ansMemo[i][j] = new int[interval + 1];
				this->trans[i][j] = new int[interval + 1];
				for (int k = 0; k <= interval; k++) {
					this->ansMemo[i][j][k] = -1;
					this->trans[i][j][k] = 0;
				}
			}
		}
	}


	int auxSolve(int job, int rem) {
		if (job == n || rem == 0) return 0;

		if (~ansMemo[job][idx[job]][rem]) return ansMemo[job][idx[job]][rem];

		// take
		int r1 = 0;
		if (idx[job] < m[job] && rem >= nums[job][idx[job]]) {
			idx[job]++;
			r1 = 1 + auxSolve(job, rem - nums[job][idx[job] - 1]);
			idx[job]--;
		}

		//leave
		int r2 = auxSolve(job + 1, rem);

		if (r1 > r2) {
			trans[job][idx[job]][rem] = 1;
		}
		else {
			trans[job][idx[job]][rem] = -1;
			r1 = r2;
		}

		return ansMemo[job][idx[job]][rem] = r1;
	}

	int* auxIdx(int job, int rem) {
		if (job == n || rem == 0) return idx;

		if (trans[job][idx[job]][rem] == 1) {
			idx[job]++;
			return auxIdx(job, rem - nums[job][idx[job] - 1]);
		}
		else if (trans[job][idx[job]][rem] == -1) {
			return auxIdx(job + 1, rem);
		}
	}

public:
	Solution(int** nums, int n, int* m) {
		this->nums = nums;
		this->n = n;
		this->m = m;
		this->idx = new int[n];
		for (int i = 0; i < n; i++) this->idx[i] = 0;
	}

	int solve(int interval) {
		buildAnsMemo(n, m, interval);
		int ret = auxSolve(0, interval);
		idx = auxIdx(0, interval);
		return ret;
	}

	int* getIdx() {
		return this->idx;
	}
};

int main() {
	int n;
	cout << "Number of jobs = ";
	cin >> n;

	int** nums = new int* [n];
	int* m = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Number of instructions of job " << i << " = ";
		cin >> m[i];
		nums[i] = new int[m[i]];

		cout << "Job " << i+1 << " instructions runtime = ";
		for (int j = 0; j < m[i]; j++) {
			cin >> nums[i][j];
		}
	}

	Solution* s = new Solution(nums, n, m);


	int interval;
	cout << "Interval = ";
	cin >> interval;
	while (interval > 0) {
		string working = "\nWorking.....\n";
		for (int i = 0; i < working.length(); i++) {
			cout << working[i];
			for (int j = 0; j < 10000000; j++);
		}
		cout << "\nMax possible number of instructions = " << s->solve(interval) << endl;
		int* tmp = s->getIdx();
		cout << "Number of instructions taken per job = ";
		for (int i = 0; i < n; i++) cout << tmp[i] << " ";
		cout << "\n\nInterval(0 to end) = ";
		cin >> interval;
	}

	return 0;
}