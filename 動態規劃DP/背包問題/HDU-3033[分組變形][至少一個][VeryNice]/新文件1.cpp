#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> arr;
int main()
{
	int n, m, k, x, p, v;
	bool flag;
	while (cin >> n >> m >> k)
	{
		arr.clear();
		arr.resize(k + 1);
		dp.clear();
		dp.resize(k + 1);
		for (int i = 0; i <= k; i++)
			dp[i].resize(m + 1, -1);
		for(int i=0;i<=m;i++)
			dp[0][i]=0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			cin >> p >> v;
			arr[x].push_back({p, v});
		}
		for (int i = 1; i <= k; i++)				//do backpack in every group and basic on the front group
			for (int g = 0; g < arr[i].size(); g++) //order is important!
				for (int j = m; j >= 0; j--)		//order is important!
					if (j - arr[i][g].first >= 0)
					{
						if (dp[i][j - arr[i][g].first] != -1)
							dp[i][j] = max(dp[i][j], dp[i][j - arr[i][g].first] + arr[i][g].second); //order is important! Wrong situation:price=0
						if (dp[i - 1][j - arr[i][g].first] != -1)
							dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i][g].first] + arr[i][g].second); //order is important!
					}
		flag = 0;
		for (int i = m; i >= 0; i--)
		{
			if (dp[k][i] != -1)
			{
				flag = true;
				cout << dp[k][i] << '\n';
				break;
			}
		}
		if(!flag)
			cout<<"Impossible\n";
	}

	return 0;
}
