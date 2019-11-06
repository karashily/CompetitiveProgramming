#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <map>
 
int a[101];
 
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
 
	int max = 0;
	int maxi = -1;
 
	int min = 99999;
	int mini = -1;
 
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			maxi = i;
		}
		if (a[i] < min) {
			min = a[i];
			mini = i;
		}
	}
 
	int arr[4];
	arr[0] = maxi;
	arr[1] = mini;
	arr[2] = n - maxi - 1;
	arr[3] = n - mini - 1;
 
	max = 0;
	for (int i = 0; i < 4; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
 
	cout << max;
 
	return 0;
}