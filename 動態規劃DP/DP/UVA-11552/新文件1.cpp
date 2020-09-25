#include <bits/stdc++.h>
using namespace std;
#define MAXN (1120)
vector<vector<int>> dp;
vector<int> ck_size;
vector<vector<bool>> vis;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, k,ans;
    string str;
    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        dp.clear();
        dp.resize(str.size() / k);
        vis.clear();
        vis.resize(dp.size());
        for (int i = 0; i < vis.size(); i++)
            vis[i].resize(26, 0);
        ck_size.clear();
        ck_size.resize(dp.size());
        for (int i = 0; i < dp.size(); i++)
            dp[i].resize(26,1e9);
        for (int i = 0; i < dp.size(); i++)
        {
            vector<int> tmp;
            tmp.clear();
            for (int j = 0; j < k; j++)
            {
                tmp.push_back(str[i * k + j] - 'a');
                vis[i][str[i * k + j] - 'a'] = 1;
            }
            sort(tmp.begin(), tmp.end());
            tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
            ck_size[i] = tmp.size();
        }
        // for(int i=0;i<dp.size();i++)
        // {
        //     cout<<'\n';
        //     cout<<"i= "<<i<<'\n';
        //     cout<<"size= "<<ck_size[i]<<'\n';
        //     for(int j=0;j<26;j++)
        //         if(vis[i][j])
        //             cout<<char(j+'a')<<' ';
        //     cout<<'\n';
        // }
        for (int i = 0; i < dp.size(); i++)
            for (int j = 0; j < 26; j++)
            {
                if(i==0){
                    if(vis[i][j])
                        dp[i][j]=ck_size[i];
                    continue;
                }

                if (vis[i][j])
                    for (int g = 0; g < 26; g++)
                    {
                        if(vis[i-1][g]){
                            if(vis[i][g]&&(g!=j||ck_size[i]==1))
                                dp[i][j]=min(dp[i][j],dp[i-1][g]+ck_size[i]-1);
                            else
                                dp[i][j]=min(dp[i][j],dp[i-1][g]+ck_size[i]);
                        }
                    }
            }

        // for(int i=0;i<dp.size();i++)
        // {
        //     cout<<'\n';
        //     cout<<"i= "<<i<<'\n';
        //     for(int j=0;j<26;j++){
        //         if(dp[i][j]!=1e9)
        //             cout<<" dp["<<i<<"]["<<char(j+'a')<<"]= "<<dp[i][j]<<'\n';
        //     }
        //     cout<<'\n';
        // }
        ans=1e9;
        for(int i=0;i<26;i++)
            ans=min(ans,dp[dp.size()-1][i]);
        cout<<ans<<'\n';
    }

    return 0;
}

