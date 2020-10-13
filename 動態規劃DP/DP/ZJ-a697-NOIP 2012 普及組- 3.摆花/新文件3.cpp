#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
vector<ll> arr;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		//dp[i][j]=>用前i種花,擺放j朵的方法數
		arr.resize(n + 1);
		dp.resize(n + 1);
		for (int i = 0; i <= n; i++)
			dp[i].resize(m + 1, 0);
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 0; i <= arr[1]; i++)
			dp[1][i] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				for (int k = 0; k <= arr[i]; k++)
				{
					if (j - k < 0)
						break;
					if(k==0)
						dp[i][j] =  dp[i - 1][j - k];
					else
						dp[i][j] += dp[i - 1][j - k];
					dp[i][j]%=1000007;
				}		
			}
		}
		/*
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
				cout<<setw(5)<<dp[i][j];
			cout<<endl;
		}
		*/
		cout << dp[n][m] << '\n';

		arr.clear();
	}

	return 0;
}
