#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
int item[] = {1, 5, 10, 25};
int cnt[4];
int dp[10001];
int used[10001][4];
// vector<int> dp;
// vector<vector<int> > used;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3] && (n || cnt[0] || cnt[1] || cnt[2] || cnt[3]))
	{
		// dp.clear();
		// dp.resize(n + 1, -1e9);
		// used.clear();
		// used.resize(n + 1);
		// for (int i = 0; i <= n; i++)
		// 	used[i].resize(4, 0);

		memset(dp,-1,sizeof(dp));
		memset(used,0,sizeof(used));

		dp[0] = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = item[i]; j <= n; j++)
			{
				if (j - item[i] != -1)
				{
					if (dp[j] < dp[j - item[i]] && used[j - item[i]][i] + 1 <= cnt[i])
					{
						dp[j] = dp[j - item[i]] + 1;
						for (int g = 0; g < 4; g++)
							used[j][g] = used[j - item[i]][g];
						used[j][i]++;
					}
				}
			}
		}
		if (dp[n] == -1)
		{
			cout << "Charlie cannot buy coffee." << '\n';
			continue;
		}
		else{
			cout<<"Throw in "<<used[n][0]<<" cents, "<<used[n][1]<<" nickels, "<<used[n][2]<<" dimes, and "<<used[n][3]<<" quarters.\n";
		}
	}
	return 0;
}
