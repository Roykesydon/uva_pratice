#include <bits/stdc++.h>
using namespace std;
int cnt_leftup_one[1001][1001], dp[1001][1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m, x, maxn;
    char ch;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(cnt_leftup_one,0,sizeof(cnt_leftup_one));
        memset(dp,0,sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> ch;
                cnt_leftup_one[i][j] = ch-'0' + cnt_leftup_one[i][j - 1] + cnt_leftup_one[i - 1][j] - cnt_leftup_one[i - 1][j - 1];
            }
        maxn = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] - 1;
                if (i == 1 || j == 1)
                    dp[i][j]++;
                while (i + dp[i][j] <= n && j + dp[i][j] <= m && cnt_leftup_one[i + dp[i][j]][j + dp[i][j]] - cnt_leftup_one[i - 1][j+dp[i][j]] - cnt_leftup_one[i+dp[i][j]][j - 1] + cnt_leftup_one[i - 1][j - 1] <= 1)
                    dp[i][j]++;
                maxn = max(maxn, dp[i][j]);
            }
        cout << maxn << '\n';
    }
    return 0;
}
