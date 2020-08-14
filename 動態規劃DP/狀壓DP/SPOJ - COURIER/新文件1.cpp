#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>floyd;
vector<vector<int>>dp;
vector<pair<int, int>>pack;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    int n, m, b, s;
    int u, v, w, z;
    int minn;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>s;
        floyd.resize(n+1);
        for (int i=0;i<=n;i++)
            floyd[i].resize(n+1, 1e8);
        for (int i=0;i<m;i++){
            cin>>u>>v>>w;
            floyd[u][v]=min(floyd[u][v], w);
            floyd[v][u]=min(floyd[v][u], w);
        }
        for (int i=1;i<=n;i++)
            floyd[i][i]=0;

        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    floyd[i][j]=min(floyd[i][j], floyd[i][k]+floyd[k][j]);

        cin>>z;
        for (int i=0;i<z;i++){
            cin>>u>>v>>b;
            for (int j=0;j<b;j++)
                pack.push_back({ u, v });
        }
        dp.resize(1<<pack.size());
        for (int i=0;i<(1<<pack.size());i++)
            dp[i].resize(n+1, 1e8);
        dp[0][s]=0;
        minn=1e8;
        for (int i=0;i<(1<<pack.size());i++){
            for (int j=0;j<pack.size();j++){
                if (i&(1<<j)) continue;

                for (int g=1;g<=n;g++)
                    dp[i|(1<<j)][pack[j].second]=min(dp[i|(1<<j)][pack[j].second], dp[i][g]+floyd[pack[j].first][pack[j].second]+floyd[g][pack[j].first]);
            }
            if(i==(1<<pack.size())-1)
               for (int g=1;g<=n;g++)
                   minn=min(minn,dp[i][g]+floyd[g][s]);
        }
        cout<<minn<<'\n';

        pack.clear();
        floyd.clear();
        dp.clear();
    }

    return 0;
}
