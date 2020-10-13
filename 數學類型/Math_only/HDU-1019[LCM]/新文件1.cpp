#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll lcm(ll a, ll b)
{
	return a / __gcd(a, b) * b;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t, ans, x,cnt,m;
	string str;
	stringstream ss;
	cin >> t;
	getline(cin, str);
	while (t--)
	{
		cin>>m;
		ans=0;
		for(int i=0;i<m;i++){
			cin>>x;
			if(!i)
				ans=x;
			else
				ans=lcm(x,ans);
		}
		cout << ans << '\n';
	}
	return 0;
}
