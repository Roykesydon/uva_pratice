#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> arr1, arr2;
vector<pair<int, int>> item;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, ans = -1, sum1 = 0, sum2 = 0;
    cin >> n >> k;
    arr1.resize(n);
    arr2.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];
    //  X/Y==k    ||    X-k*Y==0
    //(a1+b1)/(a2+b2)==k
    //a1+b1=ka2+kb2;
    //(a1-ka2)+(b1-kb2)==0;
    item.resize(n);
    dp.resize(n + 1);
    for (int i = 0; i <= n; i++)
        dp[i].resize(20000 + 1, -1e9);
    dp[0][10000] = 0;
    for (int i = 0; i < n; i++)
    {
        item[i].first = arr1[i];
        item[i].second = arr1[i] - k * arr2[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 20000; j++)
        {
            dp[i + 1][j] = dp[i][j];
            if (j - item[i].second >= 0 && j - item[i].second <= 20000 && dp[i][j - item[i].second] != -1e9)
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - item[i].second] + item[i].first);
        }
    if (dp[n][10000] != 0)
        cout << dp[n][10000] << '\n';
    else
        cout << -1 << '\n';
    return 0;
    //4/1  2/2== 4-2*1=2  2-2*2=-2
}
