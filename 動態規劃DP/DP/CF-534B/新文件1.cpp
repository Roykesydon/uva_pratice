#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v1, v2, t, d, ans;
    cin >> v1 >> v2;
    cin >> t >> d;
    dp.resize(t + 1);
    for (int i = 0; i <= t; i++)
        dp[i].resize(2000 + 1, -1);
    dp[0][v1] = v1;
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j <= 2000; j++)
        {
            for (int k = -d; k <= d; k++)
            {
                if (j + k >= 0 && j + k <= 2000 && dp[i - 1][j + k] != -1)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k] + j);
            }
        }
    }
    // cerr << "safe1\n";
    // for (int i = 0; i <= t; i++)
    // {
    //     for (int j = 0; j <= 2000; j++)
    //     {
    //         if (dp[i][j] != -1)
    //         {
    //             cerr << "i= " << i << " j= " << j << " dp= " << dp[i][j] << '\n';
    //         }
    //     }
    // }
    cout << dp[t - 1][v2] << '\n';
    return 0;
}
/*
5 6
4 2
*/
