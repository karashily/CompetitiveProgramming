#include <iostream>
 
using namespace std;
 
int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		long long sum = 0;
		long long a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum += a;
		}
		long long r = sum / n;
		if (sum % n) r++;
		cout << r << endl;
	}
	return 0;
}
