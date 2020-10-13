#include<bits/stdc++.h>
using namespace std;
#define reszie resize
#define ll long long
vector<vector<ll>>dp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,n,m;
    while(cin>>n>>k>>m){
        dp.clear();
        dp.resize(k+1);
        for(int i=0;i<=k;i++)
            dp[i].resize(n+1,0);
        for(int i=1;i<=m;i++)
            dp[1][i]=1;
        for(int i=2;i<=k;i++)
            for(int j=i;j<=min(n,m*i);j++)
                for(int g=1;g<=m;g++)
                    if(j-g>=0)
                        dp[i][j]+=dp[i-1][j-g];
        cout<<dp[k][n]<<'\n';
    }

    return 0;
}
