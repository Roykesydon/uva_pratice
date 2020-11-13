#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll dp[2][200005];
ll sum_layer(ll n){
    return n*(n+1)/2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x,y;
    ll ans=0,pre,now;
    cin>>x>>y;
    dp[0][x]=1;
    for(ll i=1;true;i++){
        if(sum_layer(i)>x+y)break;
        now=i&1,pre=1^now;
        for(int j=0;j<=x;j++)
            dp[now][j]=0;
        for(int j=0;j<=x;j++)
            if(sum_layer(i)-(x-j)<=y)
                dp[now][j]=dp[pre][j];//don't put red
        for(int j=0;j<=x;j++)
            if(x-j+i<=x&&j-i>=0)
                dp[now][j-i]=(dp[now][j-i]+dp[pre][j])%mod;
    }
    for(int i=0;i<=x;i++)
        ans=(ans+dp[now][i])%mod;
    cout<<ans<<'\n';
    return 0;
}
