#include<bits/stdc++.h>
using namespace std;
vector<int>a,b;
vector<vector<int>>dp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n;
        a.clear();
        a.resize(n+2,0);
        b.clear();
        b.resize(n+2,0);
        dp.resize(n+2);
        for(int i=0;i<n+2;i++)
            dp[i].resize(n+2,0);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                dp[i][j]=1e9;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];

        for(int len=1;len<=n;len++)
            for(int i=1;i+len-1<=n;i++)
                for(int j=i;j<=i+len-1;j++)
                    dp[i][i+len-1]=min(dp[i][i+len-1],dp[i][j-1]+dp[j+1][i+len-1]+a[j]+b[i-1]+b[i+len-1+1]);

        cout<<"Case #"<<cas<<": "<<dp[1][n]<<'\n';
    }

    return 0;
}
