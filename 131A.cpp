#include <iostream>
using namespace std;
#include <cmath>
#include <string>
 
 
int main() 
{
	string a;
	cin >> a;
	int n = a.length();
	bool f = true;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > 'Z') f = false;
	}
	
	if (f) {
		if (a[0] >= 'a') a[0] -= 'a' - 'A';
		else a[0] += 'a' - 'A';
		for (int i = 1; i < n; i++)
			if (a[i] < 'a') a[i] += 'a' - 'A';
	}
 
	cout << a;
	
	return 0;
}