#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
vector<vector<int>> arr;
gp_hash_table<ll, ll> mp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, p, x, ans = 0;
	cin >> n >> p;
	arr.resize(4);
	for (int i = 0; i < 4; i++)
		arr[i].resize(n);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		mp[arr[0][i] + arr[1][j]]++;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mp.find(p - arr[2][i] - arr[3][j])!=mp.end())
				ans += mp[p - arr[2][i] - arr[3][j]];
	cout << ans << '\n';
	return 0;
}
