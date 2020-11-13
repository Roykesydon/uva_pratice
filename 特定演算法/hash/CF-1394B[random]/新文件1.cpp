#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<pair<ll, ll>>> edge;
vector<vector<ll>> dk;
vector<ll> arr;
set<ll> st;
ll k;
ll sum = 0, ans = 1;
mt19937 gen(0x5EED);

int randint(int lb, int ub)
{
	return uniform_int_distribution<int>(lb, ub)(gen);
}
void dfs(ll layer, ll val)
{
	if (layer == k)
	{
		for (ll i = 1; i <= layer; i++)
			if ((val * dk[layer][i]) % mod == ans)
				sum++;
		return;
	}
	for (ll i = 1; i <= layer; i++)
		dfs(layer + 1, (val * dk[layer][i]) % mod);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, m, u, v, w;
	cin >> n >> m >> k;
	arr.resize(n + 1);
	edge.resize(n + 1);
	dk.resize(k + 1);
	for (ll i = 1; i <= k; i++)
		dk[i].resize(i + 1, 1);
	for (ll i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		edge[u].push_back({w, v});
	}
	for (ll i = 1; i <= n; i++)
		sort(edge[i].begin(), edge[i].end());
	// for (int i = 1; i <= n; i++)
	// {
		// cerr << "i= " << i << '\n';
	// 	for (auto j : edge[i])
			// cerr << j.first << ' ' << j.second << " || ";
		// cerr << '\n';
	// }
	for (ll i = 1; i <= n; i++)
		arr[i] = randint(2, mod - 1);
	// for(int i=1;i<=n;i++)
		// cerr<<"arr["<<i<<"]= "<<arr[i]<<'\n';
	for (ll i = 1; i <= n; i++)
	{
		ans *= arr[i];
		ans %= mod;
	}
	// cerr<<"ans= "<<ans<<'\n';
	for (ll i = 1; i <= k; i++)
	{
		for (ll j = 1; j <= i; j++)
		{
			// cerr<<'\n';
			// cerr << "i= " << i << " j= " << j << '\n';
			st.clear();
			for (ll x = 1; x <= n; x++)
				if (edge[x].size() == i)
					st.insert(edge[x][j-1].second);
			// cerr<<"u= ";
			for (auto u : st)
			{
				// cerr<<u<<' ';
				dk[i][j] *= arr[u];
				dk[i][j] %= mod;
			}
			// cerr<<'\n';
			// cerr<<"dk["<<i<<"]["<<j<<"]= "<<dk[i][j]<<'\n';
		}
	}
	dfs(1, 1);
	cout << sum << '\n';
	return 0;
}
