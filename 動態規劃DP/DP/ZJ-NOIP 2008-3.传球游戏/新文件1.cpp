#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<int> tmp;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		dp.resize(n, 0);
		tmp.resize(n);
		dp[0] = 1;
		while (m--)
		{
			tmp = dp;
			for (int i = 0; i < n; i++)
			{
				
				dp[i] = tmp[(i - 1 + n) % n] + tmp[(i + 1) % n];
			}
		}
		// for (int i = 0; i < n; i++)
		// 	cout << dp[i] << ' ';
		// cout << '\n';

		cout << dp[0] << '\n';
		tmp.clear();
		dp.clear();
	}
	return 0;
}
