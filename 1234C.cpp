#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
 
int a[200001];
vector<long long> vec;
set<long long> myset;
int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s1;
		string s2;
		cin >> s1;
		cin >> s2;
		int count = 0;
		bool f = false;
		bool row = 0;
		for (int i = 0; i < n; i++) {
			if (!row) {
				if (s1[i] == '3' || s1[i] == '4' || s1[i] == '5' || s1[i] == '6') {
					if (s2[i] == '3' || s2[i] == '4' || s2[i] == '5' || s2[i] == '6') {
						count++;
						row = 1;
					}
					else {
						f = true;
						break;
					}
				}
			}
			else {
				if (s2[i] == '3' || s2[i] == '4' || s2[i] == '5' || s2[i] == '6') {
					if (s1[i] == '3' || s1[i] == '4' || s1[i] == '5' || s1[i] == '6') {
						count++;
						row = 0;
					}
					else {
						f = true;
						break;
					}
				}
			}
		}
		if (f) cout << "NO" << endl;
		else if (count % 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}