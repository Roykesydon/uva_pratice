#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>arr;
vector<ll>dp;
int main()
{
    ll n,m,ans=0;
    cin>>n>>m;
    arr.resize(n+1);
    dp.resize(n+1,0);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    if(m+1<=n)
    {
      dp[m+1]=arr[m+1];
      ans=max(ans,dp[m+1]);
    }

    for(ll i=1;i<=n;i++)
    {

      if(i<=m+1)continue;
      dp[i]=max(dp[i],dp[i-m]+arr[i]);
      for(int j=i;j>i-m;j--)
        dp[i]=max(dp[i],dp[j]);
      ans=max(dp[i],ans);

    }
    cout<<ans<<'\n';

    return 0;
}
