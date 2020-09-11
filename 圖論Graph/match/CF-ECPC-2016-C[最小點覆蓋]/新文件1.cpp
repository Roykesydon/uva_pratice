#include<bits/stdc++.h>
using namespace std;
#define eps (1e-6)
class node{
public:
    double x,y;
    int column;
    int ring;
    bool death;
};
vector<node>monster;
vector<bool>used_weapon;
vector<int>match;
vector<int>vis;
vector<vector<int>>edge;
double distance(pair<double,double>a,pair<double,double>b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
bool dfs(int index){
    for(auto i:edge[index]){
        if(!vis[i]){
            vis[i]=1;
            if(match[i]==-1||dfs(match[i])){
                match[index]=i;
                match[i]=index;
                return true;
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("wall.in","r",stdin);
    int t,n,m,p,ans;
    double x,y;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n>>m>>p;
        monster.clear();
        monster.resize(p);
        used_weapon.clear();
        used_weapon.resize(n+m,0);
        for(int i=0;i<p;i++){
            cin>>monster[i].x>>monster[i].y;
            monster[i].column=floor(monster[i].x);
            monster[i].death=0;
            monster[i].ring=-1;
        }

        for(int i=0;i<p;i++){
            if(used_weapon[monster[i].column]){
                monster[i].death=1;
                continue;
            }
            if(distance({monster[i].x,monster[i].y},{double(n)/2.0,0.0})<=double(n)/2.0){
                used_weapon[monster[i].column]=1;
                ans++;
                monster[i].death=1;
                continue;
            }
            if(monster[i].y>double(n)/2.0+m&&distance({monster[i].x,monster[i].y},{double(n)/2.0,m})){
                used_weapon[monster[i].column]=1;
                monster[i].death=1;
                ans++;
                continue;
            }
        }

        for(int i=0;i<m;i++){
            if(i==m-1){
                for(int j=0;j<p;j++){
                    if(monster[j].death||monster[j].ring!=-1)continue;
                    if(distance({monster[j].x,monster[j].y},{double(n)/2.0,i})>double(n)/2.0)
                        monster[j].ring=i;
                }
            }
            for(int j=0;j<p;j++){
                if(monster[j].death||monster[j].ring!=-1)continue;
                if(distance({monster[j].x,monster[j].y},{double(n)/2.0,i})>double(n)/2.0&&distance({monster[j].x,monster[j].y},{double(n)/2.0,i+1})<double(n)/2.0)
                    monster[j].ring=i;
                //double(n)/2.0
            }
        }
        // for(int i=0;i<p;i++)
        //     cout<<fixed<<setprecision(2)<<monster[i].x<<' '<<monster[i].y<<' '<<monster[i].column<<" "<<monster[i].ring<<" "<<monster[i].death<<'\n';
        edge.clear();
        edge.resize(m+n);
        match.clear();
        match.resize(m+n,-1);
        vis.clear();
        vis.resize(m+n);//n first
        for(int i=0;i<p;i++){
            if(monster[i].death)continue;
            edge[monster[i].column].push_back(monster[i].ring+n);
            edge[monster[i].ring+n].push_back(monster[i].column);
        }
        for(int i=0;i<n;i++){
            if(match[i]==-1){
                vis.assign(m+n,0);
                if(dfs(i))
                    ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
/*
1
4 4 9
0.4 1.4
1.4 2.6
1.2 4.0
1.2 4.5
2.8 3.6
2.7 4.3
2.2 5.6
3.1 1.9
3.2 2.2
*/
