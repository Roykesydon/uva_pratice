#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr,dp,pre;
vector<int>ans;
#define reszie resize
void dfs(int layer,int pos,bool flag){
    // cerr<<"in i: "<<layer<<" j: "<<pos<<'\n';
    
    if(pre[layer][pos]==-1);
    else if(pre[layer][pos]==0)
        dfs(layer-1,pos,0);
    else if(pre[layer][pos]==1)
        dfs(layer,pos-1,0);
    else if(pre[layer][pos]==2)
        dfs(layer,pos+1,0);

    ans.push_back(pos+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m,minn,minp;
    while (cin >> n >> m)
    {
        arr.clear();
        arr.resize(n);
        ans.clear();
        for (int i = 0; i < n; i++)
            arr[i].resize(m);
        dp.clear();
        dp.resize(n);
        for (int i = 0; i < n; i++)
            dp[i].resize(m,1e9);
        pre.clear();
        pre.resize(n);
        for (int i = 0; i < n; i++)
            pre[i].resize(m);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        for(int i=0;i<m;i++){
            dp[0][i]=arr[0][i];
            pre[0][i]=-1;
        }
        // cerr<<"safe\n";
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=arr[i][j]+dp[i-1][j]; 
                pre[i][j]=0;//down 
            }
            for(int j=1;j<m;j++){
                if(dp[i][j]>arr[i][j]+dp[i][j-1]){
                    dp[i][j]=arr[i][j]+dp[i][j-1];
                    pre[i][j]=1;//left
                }
            }
            for(int j=m-2;j>=0;j--){
                if(dp[i][j]>arr[i][j]+dp[i][j+1]){
                    dp[i][j]=arr[i][j]+dp[i][j+1];
                    pre[i][j]=2;//right
                }
            }
        }
        // cerr<<"safe2\n";
        minn=1e9;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)
        //         cout<<setw(3)<<dp[i][j];
        //     cout<<'\n';
        // }
        for(int j=0;j<m;j++)
        {
            if(dp[n-1][j]<=minn){
                minn=dp[n-1][j];
                minp=j;
            }
        }
        dfs(n-1,minp,1);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1)cout<<" ";
        }
        cout<<'\n';
    }

    return 0;
}
