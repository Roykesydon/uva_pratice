#include<bits/stdc++.h>
using namespace std;

string str="RGBCMYK";
map<char,int>id;
int n,m;
vector<int>arr;
vector<vector<int>>eli;
vector<vector<vector<int>>>dp;
void init(){
    eli.clear();
    eli.resize(n);
    for(int i=0;i<n;i++)
        eli[i].resize(n,0);

    dp.clear();
    dp.resize(n);
    for(int i=0;i<n;i++)
        dp[i].resize(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j].resize(7,0);

    arr.clear();
    arr.resize(n);
    for(int i=0;i<n;i++)
        arr[i]=id[str[i]];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<7;i++)
        id[str[i]]=i;
    
    cin>>str>>m;
    n=str.size();
    init();

    for(int i=0;i<n;i++){
        dp[i][i][arr[i]]=1;
        eli[i][i]=1>=m;
    }
    for(int i=1;i<n;i++){//the two loops is important, it make the interval Dp's method can be used with O(n^2)
        for(int j=i-1;j>=0;j--){
            for(int color=0;color<7;color++){
                for(int k=j;k<i;k++)
                {
                    if(eli[j][k])
                        dp[j][i][color]=max(dp[j][i][color],dp[k+1][i][color]);
                    if(eli[k+1][i])
                        dp[j][i][color]=max(dp[j][i][color],dp[j][k][color]);
                    if(dp[j][k][color]&&dp[k+1][i][color])
                        dp[j][i][color]=max(dp[j][i][color],dp[j][k][color]+dp[k+1][i][color]);
                }
                if(dp[j][i][color]>=m)
                    eli[j][i]=1;
            }
        }
    }
    cout<<((eli[0][n-1])?"Yes\n":"No\n");
    return 0;
}
