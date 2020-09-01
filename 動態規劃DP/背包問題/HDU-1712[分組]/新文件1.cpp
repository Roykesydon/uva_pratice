#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
vector<int> dp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	while (cin >> n >> m && (n || m))
	{
		arr.clear();
		arr.resize(n + 1);
		for (int i = 0; i <= n; i++)
			arr[i].resize(m + 1);
		dp.clear();
		dp.resize(m + 1);

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> arr[i][j];

		for (int i = 1; i <= n; i++)
			for (int j = m; j >= 0; j--)
				for (int k = 1; k <= m; k++)
					if (j - k >= 0)
						dp[j] = max(dp[j], dp[j - k] + arr[i][k]);
		cout << dp[m] << '\n';
	}

	return 0;
}
