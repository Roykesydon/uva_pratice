#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> arr, dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        n /= 100;
        arr.clear();
        arr.resize(10);
        for (int i = 0; i < 10; i++)
            arr[i].resize(n);
        dp.clear();
        dp.resize(10);
        for (int i = 0; i < 10; i++)
            dp[i].resize(n+1, 1e9);
        for (int i = 9; i >= 0; i--)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 10; j++)
            {
                dp[j][i] = min(dp[j][i], dp[j][i - 1] + 30 - arr[j][i-1]);
                if (j > 0)
                    dp[j][i] = min(dp[j][i], dp[j - 1][i - 1] + 60 - arr[j-1][i-1]);
                if (j < 9)
                    dp[j][i] = min(dp[j][i], dp[j + 1][i - 1] + 20 - arr[j+1][i-1]);
            }
        cout << dp[0][n] << "\n\n";
    }
    return 0;
}
