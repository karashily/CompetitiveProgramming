#include <iostream>
using namespace std;
#include <cmath>
#include <string>
 
 
int main() 
{
	int n, t;
	string a;
 
	cin >> n >> t >> a;
 
	for (int i = 0; i < t; i++) {
		for (int j = 1; j < n; j++) {
			if (a[j - 1] == 'B' && a[j] == 'G') {
				a[j] = 'B';
				a[j - 1] = 'G';
				j++;
			}
		}
	}
 
	cout << a;
 
	return 0;
}