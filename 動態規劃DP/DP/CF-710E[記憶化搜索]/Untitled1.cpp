#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, x, y;
#define MXN 10000005
ll dp[MXN];
ll min3(ll a,ll b,ll c)
{
    return min(a,min(b,c));
}
ll dfs(ll tar)
{
    if(tar==0)
        return 0;
    if (dp[tar])
        return dp[tar];
    if(tar&1)
        return dp[tar]=min3(dfs(tar-1)+x,dfs(tar/2)+x+y,dfs((tar+1)/2)+x+y);
    else
        return dp[tar]=min(dfs(tar/2)+y,dfs(tar-1)+x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y;
    dp[1]=x;
    for(ll i=2;i<=n;i++)
        dfs(i);
    cout << dfs(n) << '\n';
    return 0;
}

