#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, x, ans = 0;
    cin >> n;
    dp.push_back(2);
    dp.push_back(3);
    while (x >= 0)
    {
        dp.push_back(dp[dp.size() - 1] + dp[dp.size() - 2]);
        x = dp[dp.size() - 1] + dp[dp.size() - 2];
    }
    auto u = lower_bound(dp.begin(), dp.end(), n) - dp.begin();
    cout << ((dp[u] == n) ? u + 1 : u) << '\n';
    return 0;
}
