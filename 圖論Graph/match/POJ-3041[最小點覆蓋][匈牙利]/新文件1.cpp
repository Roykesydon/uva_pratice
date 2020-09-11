#include<iostream>
#include<vector>
using namespace std;
vector<int>match;
vector<bool>vis;
vector<vector<int> >edge;
bool dfs(int index){
    for(int i=0;i<edge[index].size();i++){
        if(!vis[edge[index][i]]){
            vis[edge[index][i]]=true;
            if(match[edge[index][i]]==-1||dfs(match[edge[index][i]])){
                match[index]=edge[index][i];
                match[edge[index][i]]=index;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,k,x,y,ans;
    cin>>n>>k;
    vis.resize(n*2+1);
    match.resize(n*2+1,-1);
    edge.resize(n*2+1);
    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        edge[x].push_back(y+n);
        edge[y+n].push_back(x);
    }
    ans=0;
    for(int i=1;i<=n;i++){
        if(match[i]==-1){
            vis.assign(n*2+1,false);
            if(dfs(i))ans++;
        }
    }
    cout<<ans<<'\n';

    return 0;
}
