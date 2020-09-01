#include <bits/stdc++.h>
using namespace std;
vector<int> arr, ans;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int v, n, tmp, maxn;
    while (cin >> v >> n)
    {
        arr.clear();
        arr.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        dp.clear();
        dp.resize(n + 1);
        for (int i = 0; i <= n; i++)
            dp[i].resize(v + 1, 0);
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= v; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]]);
            }

        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= v; j++)
        //         cout << dp[i][j] << ' ';
        //     cout << endl;
        // }
        ans.clear();
        maxn = 0;
        for (int i = n, tmp = v; tmp != 0 && i > 0; i--)
        {
            if (dp[i][tmp] == 1 && maxn == 0)
            {
                maxn = tmp;
            }
            if (dp[i][tmp] == 0)
            {
                tmp--;
                i++;
                continue;
            }
            if (dp[i][tmp] != dp[i - 1][tmp])
            {
                tmp -= arr[i];
                ans.push_back(arr[i]);
            }
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << "sum:" << maxn << '\n';
    }
    return 0;
}//
