#include <bits/stdc++.h>
using namespace std;
int dp[2000][2000];
int dfs(int n,int m){
    if(n<=0||m<=0)
        return -1;
    if(dp[n][m]!=-1)
        return dp[n][m];
    return dp[n][m]=max(dfs(n+3-5,m+2-10)+2,dfs(n+3-20,m+2+5)+2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<=2;i++){
        for(int j=0;j<2000;j++)
            dp[i][j]=1;
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << dfs(n,m) << '\n';
    }

    return 0;
}
