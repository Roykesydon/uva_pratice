#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[66][66][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    dp[1][1][1]=1;//bottom locked
    dp[1][0][0]=1;//bottom unlocked
    for(int i=2;i<66;i++){
        for(int j=0;j<=i;j++){
            dp[i][j][0]+=dp[i-1][j][0]+dp[i-1][j][1];
            dp[i][j][1]+=dp[i-1][j][0];
            if(j)
                dp[i][j][1]+=dp[i-1][j-1][1];
        }
    }
    int n,s;
    while(cin>>n>>s){
        if(n<0&&s<0)
            break;
        cout<<dp[n][s][0]+dp[n][s][1]<<'\n';
    }
    return 0;
}
/*
3
3 5 7 4 3
2 1 1 2000
5 12 2 5 1 2 4
*/
