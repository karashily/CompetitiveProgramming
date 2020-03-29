#include <iostream>
using namespace std;
 
int a[100005];
int b[100005];
 
int main() {
	int n;
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> a[i];
 
	long long sum = 0;
 
	int f = 0;
 
	for (long long i = 0; i < n; i++) {
		if (a[i] % 2) {
			if (f != 0) {
				b[i] = a[i] / 2;
				if (f < 0) {
					if (a[i] < 0) b[i]--;
					f++;
				}
				else {
					f--;
				}
			}
			else {
				b[i] = a[i] / 2;
				if (a[i] > 0) {
					b[i]++;
					f--;
				}
				else {
					f--;
				}
			}
		}
		else {
			b[i] = a[i] / 2;
		}
		sum += b[i];
	}
	
	for (long long i = 0; i < n; i++) {
		cout << b[i] << endl;
	}
	return 0;
}