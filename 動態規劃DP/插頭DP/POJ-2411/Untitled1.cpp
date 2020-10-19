#include <iostream>
#include<cstring>
using namespace std;

#define ll long long
ll dp[12][12][1 << 12];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    while (cin >> n >> m && (n || m))
    {
        memset(dp, 0, sizeof(dp));
        dp[1][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int plug1 = 1 << (j - 1), plug2 = 1 << j;
                for (int k = 0; k < (1 << (m + 1)); k++)
                {
                    if (k & plug1 && k & plug2)
                        continue;
                    int st1, st2;
                    st1 = k & plug1, st2 = k & plug2;
                    if (st1 == 0 && st2 == 0)
                    {
                        dp[i][j][k | plug1] += dp[i][j-1][k];
                        dp[i][j][k | plug2] += dp[i][j-1][k];
                    }
                    else if (st1)
                        dp[i][j][k ^ plug1] += dp[i][j-1][k];
                    else if (st2)
                        dp[i][j][k ^ plug2] += dp[i][j-1][k];
                }
            }
            if (i != n)
                for (int j = 0; j < 1 << m; j++)
                    dp[i + 1][0][j<<1]+=dp[i][m][j];
        }

        cout << dp[n][m][0] << '\n';
    }

    return 0;
}
