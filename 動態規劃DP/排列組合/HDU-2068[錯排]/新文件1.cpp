#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
ll dp[MAXN + 1], f[15 + 1];
ll C(int n, int m)
{
    ll ans=1;
    for(int i=0;i<m;i++)    
        ans=ans*(n-i)/(i+1);    //here can't be written like "ans*= " !!!
    return ans;
}
void init()
{
    dp[0] = 1; //nobody is placed wrong place
    dp[1] = 0;
    dp[2] = 1;
    for (ll i = 3; i <= MAXN; i++)
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ans, m, n;
    init();
    while (cin >> n && n)
    {
        ans = 0;
        for (int i = n / 2; i >= 0; i--)
            ans += C(n, i) * dp[i];
        cout << ans << '\n';
    }
    return 0;
}
