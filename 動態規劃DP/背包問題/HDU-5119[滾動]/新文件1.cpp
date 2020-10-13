#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2][1<<21];
int arr[50];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,m;
    ll ans;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=1000000;j++)
                dp[1][j]=0;
            for(int j=0;j<=1000000;j++)
                dp[1][j^arr[i]]+=dp[0][j];
            for(int j=0;j<=1000000;j++)
                dp[0][j]+=dp[1][j];
        }

        ans=0;
        for(int i=m;i<=1000000;i++)
            ans+=dp[0][i];
        cout<<"Case #"<<cas<<": "<<ans<<'\n';
    }
    return 0;
}
