#include <bits/stdc++.h>
using namespace std;
vector<int>dp1,dp2;
vector<int>box_pri;
vector<vector<pair<int,int>>>item;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        dp1.clear();
        dp2.clear();
        box_pri.clear();
        item.clear();
        box_pri.resize(n);
        dp1.resize(k+1,0);
        dp2.resize(k+1,0);
        item.resize(n);
        for(int i=0;i<n;i++)
            item[i].resize(m);
        for(int i=0;i<n;i++)
            cin>>box_pri[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>item[i][j].first;//cost,value
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>item[i][j].second;
        for(int i=0;i<n;i++){
            dp2=dp1;
            for(int j=0;j<m;j++)
                for(int g=item[i][j].first;g<=k;g++)
                    dp2[g]=max(dp2[g],dp2[g-item[i][j].first]+item[i][j].second);
            for(int j=k;j>=box_pri[i];j--)
                dp1[j]=max(dp1[j],dp2[j-box_pri[i]]);
        }
        cout<<dp1[k]<<'\n';
    }

    return 0;
}
