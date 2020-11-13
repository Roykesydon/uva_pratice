#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
vector<vector<vector<ll>>> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    dp.resize(n);
    for (int i = 0; i < n; i++)
        dp[i].resize(max(k + 1, 3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= max(k, 2); j++)
            dp[i][j].resize(4, 0); //00 01 10 11
    dp[0][1][0] = 1;
    dp[0][2][1] = 1;
    dp[0][2][2] = 1;
    dp[0][1][3] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= max(k, 2); j++)
        {
            for (int g = 0; g < 4; g++)
            {
                if (g == 0)
                    dp[i][j][g] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % mod;
                if (g == 1)
                {
                    dp[i][j][g] = dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 1][3];
                    if (j >= 2)
                        dp[i][j][g] += dp[i - 1][j - 2][2];
                    dp[i][j][g] %= mod;
                }

                if (g == 2)
                {
                    dp[i][j][g] = dp[i - 1][j - 1][0] + dp[i - 1][j][2] + dp[i - 1][j - 1][3];
                    if (j >= 2)
                        dp[i][j][g] += dp[i - 1][j - 2][1];
                    dp[i][j][g] %= mod;
                }
                if (g == 3)
                {
                    dp[i][j][g] = dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3];
                    dp[i][j][g] %= mod;
                }
            }
        }
    }
    cout << (dp[n - 1][k][0] + dp[n - 1][k][1] + dp[n - 1][k][2] + dp[n - 1][k][3]) % mod << '\n';
    return 0;
}
