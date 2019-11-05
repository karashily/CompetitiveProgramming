#include <iostream>
using namespace std;

int main()
{
    long long y, p, r;
	bool f1 = false, f2;
	cin >> p >> y;
    for(long long i=y;i>p;i--)
    {
		f2 = false;
        for(long long j = 2; j * j <= i && j <= p; j++) 
        {
			if(i % j == 0)
			{
				f2 = true;
				break;
			}
		}
		if(!f2)
		{
			f1 = true;
			r = i;
			break;
		}
	}
	if(f1) 
		cout << r << endl;
	else 
		cout << "-1\n";

	return 0;
}