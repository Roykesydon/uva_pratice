#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
#define MAXN 1001
ll stir[MAXN][MAXN], C[MAXN][MAXN];
void init()
{
	//stir[i][j]=j*stir[i-1][j]+stir[i-1][j-1];
	for (int i = 0; i < MAXN; i++)
	{
		C[i][0] = 1;
		C[i][i] = 1;
		stir[i][i] = 1;
	}
	for (int i = 1; i < MAXN; i++)
	{
		for (int j = 1; j < i; j++)
		{
			stir[i][j] = (j * stir[i - 1][j] + stir[i - 1][j - 1]) % mod;
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, r, k, m, tmp, ans;
	init();
	while (cin >> n >> r >> k >> m)
	{
		tmp = n - (r - 1) * k - 1;
		if (tmp < 0)
			cout << "0\n";
		else
		{
			tmp = C[tmp + r][r];
			ans = 0;
			for (ll i = 0; i <= min(r, m); i++)
			{
				ans += stir[r][i];
				ans %= mod;
			}
			ans *= tmp;
			cout << ans % mod << '\n';
		}
	}
	return 0;
}
