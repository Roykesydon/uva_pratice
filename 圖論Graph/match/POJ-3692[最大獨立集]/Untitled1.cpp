#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >edge;
vector<vector<int> >mp;
vector<int>match,vis;
int n,m;
bool dfs(int x){
    if(!vis[x]){
        vis[x]=1;
        for(int k=0;k<edge[x].size();k++){
            // cerr<<"safe1\n";
            int i=edge[x][k];
            // cerr<<"safe2\n";
            if(match[i]==-1||dfs(match[i])){
                match[x]=i;
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}
int hungary(){
    int tmp=0;
    match.clear();
    match.resize(n+m,-1);
    for(int i=0;i<n;i++){
        // cerr<<"i= "<<i<<'\n';
        if(match[i]==-1){
            vis.clear();
            vis.resize(n+m,0);
            if(dfs(i))
                tmp++;
        }
    }
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q,x,y,cas=1;
    while(cin>>n>>m>>q){
        if(n==0&&m==0&&q==0)
            break;
        mp.clear();
        edge.clear();
        edge.resize(n+m);
        mp.resize(n+m);
        for(int i=0;i<mp.size();i++)
            mp[i].resize(n+m,0);  

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mp[i][j]=1;

        for(int i=n;i<n+m;i++)
            for(int j=n;j<n+m;j++)
                mp[i][j]=1;

        for(int i=0;i<q;i++){
            cin>>x>>y;
            x--;
            y--;
            mp[x][y+n]=1;
            mp[y+n][x]=1;
        }
        // cerr<<"safe\n";
        for(int i=0;i<n+m;i++)
            for(int j=0;j<n+m;j++)
                if(mp[i][j]!=1)
                    edge[i].push_back(j);
        // cerr<<"safe2\n";
        cout<<"Case "<<cas++<<": ";
        cout<<n+m-hungary()<<'\n';

    }


    return 0;
}
