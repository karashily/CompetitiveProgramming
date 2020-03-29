#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <map>
#include <set>
 
int main()
{
	long long n;
	cin >> n;
	string s;
	cin >> s;
 
	set<char> st;
 
	for(int i=0;i<s.length();i++) st.insert(s[i]);
 
	if (s.length() > 26)
		cout << -1;
	else
		cout << s.length() - st.size();
 
	return 0;
}