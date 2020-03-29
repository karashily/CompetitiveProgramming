#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <map>
#include <set>
 
int a[1001];
int b[1001];
 
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	
	int max = -1;
 
 
	for (int l = 0; l < n; l++)
	{
		for (int r = n; r > l; r--)
		{
			long a1 = 0;
			long b1 = 0;
			for (int i = l; i < r; i++) {
				a1 |= a[i];
				b1 |= b[i];
			}
			if (a1 + b1 > max) max = a1 + b1;
		}
	}
 
	cout << max;
 
	return 0;
}