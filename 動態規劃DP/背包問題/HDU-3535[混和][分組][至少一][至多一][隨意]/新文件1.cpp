#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
vector<pair<int, int>> tmp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, s, c, g;

    while (cin >> n >> t)
    {
        dp.clear();
        dp.resize(n + 1);
        for (int i = 0; i <= n; i++)
            dp[i].resize(t + 1, -1);
        for (int i = 0; i <= t; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> m >> s;
            // if(i==1){
            // 	if(s==1)
            // 		for(int i=1;i<=t;i++)
            // 			dp[0][i]=-1;
            // }
            if (s == 0) //at least 1
            {
                for (int j = 0; j < m; j++)
                {
                    cin >> c >> g;
                    for (int k = t; k >= c; k--)
                    {
                        if (dp[i][k - c] != -1)
                            dp[i][k] = max(dp[i][k], dp[i][k - c] + g);
                        if (dp[i - 1][k - c] != -1)
                            dp[i][k] = max(dp[i][k], dp[i - 1][k - c] + g);
                    }
                }
            }
            else if (s == 1) //at most 1
            {
                for(int k=0;k<=t;k++)
                    dp[i][k]=dp[i-1][k];
                tmp.clear();
                for (int i = 0; i < m; i++)
                {
                    cin >> c >> g;
                    tmp.push_back({c, g});
                }
                for (int k = t; k >= 0; k--)
                {
                    for (int h = 0; h < m; h++)
                    {
                        if (k - tmp[h].first >= 0 && dp[i - 1][k - tmp[h].first] != -1)
                            dp[i][k] = max(dp[i][k], dp[i - 1][k - tmp[h].first] + tmp[h].second);
                    }
                }
            }
            else if (s == 2) //free
            {
                for (int k = 0; k <= t; k++)
                    dp[i][k] = dp[i - 1][k];
                for (int j = 0; j < m; j++)
                {
                    cin >> c >> g;

                    for (int k = t; k >= c; k--)
                    {
                        if (dp[i][k - c] != -1)
                            dp[i][k] = max(dp[i][k], dp[i][k - c] + g);
                    }
                }
            }
        }
        for (int i = t; i >= 0; i--)
        {
            if (dp[n][i] != -1)
            {
                cout << dp[n][i] << '\n';
                break;
            }
            if (i == 0)
                cout << -1 << '\n';
        }
    }

    return 0;
}
