#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6
vector<vector<double>> dp;
vector<int> arr;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x, sum;
	double p, dsum;
	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		arr.clear();
		arr.resize(n);
		dp.clear();
		dp.resize(n + 1);
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}
		for (int i = 0; i <= n; i++)
			dp[i].resize(sum + 1, +0.0);
		dp[0][0] = 1.0;
		for (int i = 0; i < n; i++)
		{
			for (int j = sum; j >= 0; j--)
			{
				dp[i + 1][j] += dp[i][j] * 0.5;
				if (j - arr[i] >= 0)
					dp[i + 1][j] += dp[i][j - arr[i]] * 0.5;
			}
		}
		//cerr << "sfae\n";
		dsum = +0.0;
		for (int i = 0; i <= sum; i++)
		{
			dsum += dp[n][i];
			//cerr << "i= " << i << " dsum= " << dsum << '\n';
			if (dsum > p || abs(dsum - p) <= eps)
			{
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}
