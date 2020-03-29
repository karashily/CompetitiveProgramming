#include <iostream>
using namespace std;
#include <cmath>
#include <string>
 
 
string a;
 
 
int main() 
{
	cin >> a;
	int n = a.length();
 
	for (int i = 1; i < n; i++)
	{
		if ((a[i - 1] == 'b' && a[i] == 'a') || (a[i - 1] == 'c' && a[i] == 'b') || (a[i - 1] == 'c' && a[i] == 'a')) {
			cout << "NO" << endl;
			return 0;
		}
	}
 
	int na = 0, nb = 0, nc = 0;
 
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 'a') na++;
		if (a[i] == 'b') nb++;
		if (a[i] == 'c') nc++;
	}
 
	if (na == 0 || nb == 0) {
		cout << "NO";
		return 0;
	}
 
	if (nc == nb || nc == na)
		cout << "YES";
	else
		cout << "NO";
 
	return 0;
}