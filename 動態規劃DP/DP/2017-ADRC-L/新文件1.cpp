#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define mod 1000000007
using namespace std;
 
int num;
vector<ll> n,m,ed;
vector<vector<ll>> cost;
vector<vector<vector<ll>>> dp;
vector<vector<vector<pair<int,ll>>>> edge;
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>num;
    cost.resize(num);
    edge.resize(num);
    n.resize(num);
    m.resize(num);
    ed.resize(num);
    dp.resize(num);
    for(int i=0;i<num;i++){
        cin>>n[i]>>m[i];
        cost[i].resize(n[i]);
        for(int j=0;j<n[i];j++) cin>>cost[i][j];
        edge[i].resize(n[i]);
        for(int j=0;j<m[i];j++){
            int a,b,c;
            cin>>a>>b>>c;
            edge[i][a-1].push_back({b-1,c});
        }
        cin>>ed[i];
        --ed[i];
    }
    for(int i=0;i<num;i++){
        dp[i].resize(n[i],vector<ll>(200001,1e16));
        dp[i][0][0]=0;
        for(int j=1;j<=200000;j++){
            for(int k=0;k<n[i];k++){
                for(auto p:edge[i][k]){
                    dp[i][p.first][j]=min(dp[i][p.first][j],dp[i][k][j-1]+p.second);
                }
                dp[i][k][j]=min(dp[i][k][j],dp[i][k][j-1]+cost[i][k]);
            }
        }
    }
    ll ans=1e18;
    for(int i=0;i<=200000;i++){
        ll cnt=0;
        for(int j=0;j<num;j++){
            cnt+=dp[j][ed[j]][i];
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
