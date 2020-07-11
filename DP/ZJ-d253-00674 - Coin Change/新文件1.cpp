#include<bits/stdc++.h>
using namespace std;
int coin[6]={0,1,5,10,25,50};
vector<vector<long long> >dp;
int main()
{
    int n;
    dp.resize(6);
    for(int i=0;i<6;i++)
        dp[i].resize(7500,0);
    dp[0][0]=1;
    for(int i=1;i<=5;i++)
    {
        for(int j=0;j<7500;j++)
        {
            if(j>=coin[i])
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    /*
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<=17;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    while(cin>>n)
    {
        cout<<dp[5][n]<<'\n';
    }

    dp.clear();
    return 0;
}
