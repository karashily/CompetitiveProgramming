#include <iostream>
using namespace std;
#include <cmath>
#include <string>
#include <map>
 
map<char, int> m;
string s;
 
int main()
{
	cin >> s;
	if (s.length() < 4) {
		cout << "No";
		return 0;
	}
 
	for (int i = 0; i < s.length(); i++) {
		m[s[i]]++;
	}
 
	if (m.size() == 4 || m.size() == 3)
	{
		cout << "Yes";
		return 0;
	}
	else if (m.size() == 2) {
		for (auto const& x : m)
		{
			if (x.second < 2) {
				cout << "No";
				return 0;
			}
		}
		cout << "Yes";
		return 0;
	}
 
	cout << "No";
	return 0;
}