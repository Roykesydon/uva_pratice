#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pl(x) (x * 2 + 1)
#define pr(x) (x * 2 + 2)
vector<ll> cost;
vector<ll> dp;
vector<ll> tree;
void build(int index, int l, int r)
{
	if (l == r)
	{
		tree[index] = dp[l];
		return;
	}
	int mid = (l + r) / 2;
	build(pl(index), l, mid);
	build(pr(index), mid + 1, r);

	tree[index] = min(tree[pl(index)], tree[pr(index)]);
}
void modify(int index, int ql, int qr, int l, int r, ll value)
{
	if (l >= ql && r <= qr)
	{
		tree[index] = value;
		return;
	}
	int mid = (l + r) / 2;
	if (mid >= ql)
		modify(pl(index), ql, qr, l, mid, value);
	if (mid < qr)
		modify(pr(index), ql, qr, mid + 1, r, value);
	tree[index] = min(tree[pl(index)], tree[pr(index)]);
}
ll query(int index, int ql, int qr, int l, int r)
{
	ll ans = 1e17;
	if (l >= ql && r <= qr)
	{
		return tree[index];
	}
	int mid = (l + r) / 2;
	if (ql <= mid)
		ans = min(ans, query(pl(index), ql, qr, l, mid));
	if (qr > mid)
		ans = min(ans, query(pr(index), ql, qr, mid + 1, r));
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int n, m;
	ll ans, tmp;
	cin >> t;
	for (int h = 1; h <= t; h++)
	{

		cin >> n >> m;

		cost.resize(n + 1);
		cost[0] = 0;
		for (int i = 0; i < n; i++)
			cin >> cost[i];

		dp.resize(n, 1e17);
		dp[0] = 0;
		tree.resize(4 * n);
		build(0, 0, n-1);

		// for (int i = 0; i < n; i++)
		// 	cerr << query(0, i, i, 0, n - 1) << '\n';

		//cerr<<"build_safe\n";
		for (int i = 1; i < n; i++)
		{
			if (cost[i] != 0)
			{
				if (i < m)
				{
					tmp = query(0, 0, i - 1, 0, n - 1);
					if (tmp == 1e17)
					{
						//cerr << "dp[" << i << "] = " << dp[i] << '\n';
						continue;
					}
					dp[i] = tmp + cost[i];
					modify(0, i, i, 0, n - 1, dp[i]);
				}
				else
				{
					tmp = query(0, i - m, i - 1, 0, n - 1);
					if (tmp == 1e17)
					{
						//cerr << "dp[" << i << "] = " << dp[i] << '\n';
						continue;
					}
					dp[i] = tmp + cost[i];
					modify(0, i, i, 0, n - 1, dp[i]);
				}
			}

			//cerr << "dp[" << i << "] = " << dp[i] << '\n';
		}

		if (n - m - 1 >= 0)
			ans = query(0, n - m - 1, n - 1, 0, n - 1);
		else
			ans = query(0, 0, n - 1, 0, n - 1);

		if (ans == 1e17)
			ans = -1;

		cout << "Case #" << h << ": ";
		cout << ans << '\n';

		dp.clear();
		tree.clear();
		cost.clear();
	}

	return 0;
}
//dp[i]=min(dp[j]+arr[i])
