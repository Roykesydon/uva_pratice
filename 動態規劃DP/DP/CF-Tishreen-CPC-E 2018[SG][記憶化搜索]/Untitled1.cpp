#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll dp[101][200];
ll dfs(int index,int bits){
    if(dp[index][bits])
        return dp[index][bits];
    if(index==0&&bits==0)
        return 0;
    ll sum=0;
    for(int i=index;i>0;i--)
        sum=(sum+dfs(index-i,bits^i))%mod;
    return dp[index][bits]=sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n,ans;
    cin>>t;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<200;i++)
        dp[0][i]=1;
    for(int i=1;i<=100;i++)
        dfs(i,0);
    while(t--){
        cin>>n;
        cout<<dp[n][0]<<'\n';
    }
    return 0;
}

