#include <bits/stdc++.h>
using namespace std;
set<long long> myset;
int main()
{
	long long t, n;
	long long x, y;
	for (long long i = 1; i < 1e9 + 1; i *= 3)
		for (long long j = 1; j <= 1e9 + 1; j *= 2)
			myset.insert(i * j);
	cin >> t;
	while (t--)
	{
		x = 1;
		y = 1;
		cin >> n;
		if (myset.lower_bound(n) != myset.end())
			x = *myset.lower_bound(n);
		if (myset.lower_bound(n) != myset.begin())
			y = *(--myset.lower_bound(n));
		cerr<<"x= "<<x<<"y= "<<y<<endl;
		if (max(double(y)/n,double(n)/y)<max(double(x)/n,double(n)/x))
			cout<<y<<'\n';
		else
			cout<<x<<'\n';
	}
}

