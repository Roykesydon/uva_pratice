#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<ll>> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    ll ans = 0;
    cin >> s1 >> s2;
    dp.resize(s1.size());
    for (int i = 0; i < dp.size(); i++)
        dp[i].resize(s2.size(), 0);
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (j != 0)
                dp[i][j] = dp[i][j - 1];
            if (s1[i] == s2[j])
                if (j != 0 && i != 0)
                    dp[i][j] += dp[i - 1][j - 1] + 1;
                else
                    dp[i][j]++;
            dp[i][j] %= mod;
        }
    }
    // for (int i = 0; i < s1.size(); i++)
    // {
    //     for (int j = 0; j < s2.size(); j++)
    //         cout << dp[i][j] << ' ';
    //     cout << '\n';
    // }
    for (int i = 0; i < s1.size(); i++)
    {
        ans += dp[i][s2.size() - 1];
        ans %= mod;
    }

    cout << ans << '\n';
    return 0;
}
