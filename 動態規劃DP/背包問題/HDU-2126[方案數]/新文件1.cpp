#include <bits/stdc++.h>
using namespace std;
vector<int> arr, dp, ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        arr.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        dp.clear();
        dp.resize(m + 1, 0);
        ans.clear();
        ans.resize(m + 1, 0);
        for (int i = 0; i <= m; i++) // key!
            ans[i] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = m; j >= arr[i]; j--)
            {
                if (dp[j - arr[i]] + 1 == dp[j])
                    ans[j] += ans[j - arr[i]];
                else if (dp[j - arr[i]] + 1 > dp[j])
                {
                    dp[j] = dp[j - arr[i]] + 1;
                    ans[j] = ans[j - arr[i]];
                }
            }
        }
        if (dp[m] != 0)
            cout << "You have " << ans[m] << " selection(s) to buy with " << dp[m] << " kind(s) of souvenirs.\n";
        else
            cout << "Sorry, you can't buy anything.\n";
    }
    return 0;
}
