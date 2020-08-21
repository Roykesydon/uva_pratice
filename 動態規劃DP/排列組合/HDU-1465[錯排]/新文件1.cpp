#include <bits/stdc++.h>
using namespace std;
#define MAXN 20
#define ll long long
ll dp[MAXN + 1];
void init()
{
    dp[1] = 0;
    dp[2] = 1;
    for (ll i = 3; i <= MAXN; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1]+dp[i-2]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n;
    while (cin >> n && n)
        cout << dp[n] << '\n';
    return 0;
}
