#include <iostream>
using namespace std;
#include <algorithm>
int a[1001];
int h[1001];

int main ()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<n;i++)
	{
		h[i]++;
		for(int j=i-1;(j>=0)&&(a[j]<=a[j+1]);j--) h[i]++;
		for(int j=i+1;(j<n)&&(a[j-1]>=a[j]);j++) h[i]++;
	}
	sort(h,h+n);
	cout << h[n-1] << endl;
	return 0;
}