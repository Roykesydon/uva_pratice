#include<bits/stdc++.h>
using namespace std;
#define reszie resize
#define ll long long
ll dp[26][27][10000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cas=1;
    int n,m;
    for(int i=0;i<26;i++)
        dp[i][1][i+1]=1;//dp[letter][len][weight]
    for(int i=2;i<=26;i++)
        for(int j=i+1;j<=10000;j++)
            for(int g=0;g<26;g++)
                for(int k=0;k<g;k++)
                    dp[g][i][j]+=dp[k][i-1][j-(g+1)];
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        cout<<"Case "<<cas++<<": ";
        int ans=0;
        if(n>26)n=0;
        for(int i=0;i<26;i++)
            ans+=dp[i][n][m];
        cout<<ans<<'\n';
    }

    return 0;
}
