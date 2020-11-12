#include<bits/stdc++.h>
using namespace std;
#define MXN 205
#define ll long long
ll dp[MXN][MXN][MXN];
ll arr[MXN];
ll sq(ll num){
    return num*num;
}
ll dp_dfs(int l,int r,int tmp){//l ~ r and there is [tmp] elements which have the same color as r-th element behind the r 
    if(dp[l][r][tmp])
        return dp[l][r][tmp];
    if(l>r)return dp[l][r][tmp]=0;
    if(l==r)return sq(tmp+1);
    ll ans=dp_dfs(l,r-1,0)+sq(tmp+1);
    for(int i=l;i<r;i++)
        if(arr[i]==arr[r])
            ans=max(ans,dp_dfs(l,i,tmp+1)+dp_dfs(i+1,r-1,0));
    return dp[l][r][tmp]=ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;

    for(int cas=1;cas<=t;cas++){
        cin>>n;
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Case "<<cas<<": ";
        cout<<dp_dfs(0,n-1,0)<<'\n';
    }
    return 0;
}
