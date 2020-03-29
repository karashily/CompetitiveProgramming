#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
int a[200001];
vector<long long> vec;
set<long long> myset;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	for (int i = 0; i < n; i++) {
		bool found = false;
		int q = myset.size();
		myset.insert(a[i]);
		if (q == myset.size()) found = true;
			
		if (!found) {
			if (myset.size() > m) {
				myset.erase(vec[vec.size()-m]);
			}
			vec.push_back(a[i]);
		}
	}
	m = min(m, int(vec.size()));
	cout << m << endl;
	for (int i = 0; i < m; i++) {
		cout << vec[vec.size()-1-i] << " ";
	}
	cout << endl;
	
	return 0;
}