#include <iostream>
#include <map>
using namespace std;
 
int a[100005];
int b[100005];
map<int, bool> mp;
int main() {
	int n;
	cin >> n;
 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
 
	int i = 0;
	int offset = 0;
	while (i < n) {
		if (a[i - offset] != b[i]) {
			if (mp.count(a[i - offset])) {
				offset--;
				continue;
			}
			mp[b[i]] = 1;
			offset++;
		}
		i++;
	}
 
	cout << mp.size() << endl;
	return 0;
}