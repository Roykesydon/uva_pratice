#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>>edge;
long double ans;
void dfs(int cur,int from,int dep,long double chance){
    //cout<<"cur= "<<cur<<" from= "<<from<<" dep= "<<dep<<" chance= "<<chance<<'\n';
    bool flag =false;
    for(auto i:edge[cur]){
        if(i!=from){
            flag=true;
            if(cur==1)
                dfs(i,cur,dep+1,chance/edge[cur].size());
            else
                dfs(i,cur,dep+1,chance/(edge[cur].size()-1));
        }
    }
    if(!flag)ans+=chance*dep;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,u,v;
    cin>>n;
    edge.resize(n+1);
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    ans=+0.0;
    dfs(1,1,0,1.0);
    cout<<fixed<<setprecision(9)<<ans<<'\n';
    return 0;
}
/*
3
3 5 7 4 3
2 1 1 2000
5 12 2 5 1 2 4
*/
