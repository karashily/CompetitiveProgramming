#include <iostream>
using namespace std;
#include <string>

char out[2001];

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int k=(n-1)/2;
	out[k]=s[0];
	int j=1;
	if(n%2)
	{
		for (int i=1;i<n;i+=2)
		{
			out[k-j]=s[i];
			out[k+j]=s[i+1];
			j++;
		}
	}
	else
	{
		for (int i=1;i<n;i+=2)
		{
			out[k+j]=s[i];
			out[k-j]=s[i+1];
			j++;
		}
	}
	//out[n-1]=s[n-1];
	out[n]='\0';
	cout << out << endl;
	return 0;
}