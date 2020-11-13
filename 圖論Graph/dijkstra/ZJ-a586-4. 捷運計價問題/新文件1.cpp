#include<bits/stdc++.h>
using namespace std;
map<string,bool>vis;
class path{
    public:
        int len;
        int change;
};


map<string,path>dis;
map<string,vector<string> >mp;
class cmp
{
    public:
    bool operator()(pair <string,path> a,pair <string,path> b)
    {
        return a.second.len/3*5+a.second.change*5>b.second.len/3*5+b.second.change*5;
    }
};
priority_queue< pair <string,path>,vector<pair <string,path> >,cmp>pq;
void dijkstra(string start,string end)
{
    dis[start]={0,0};
    pq.push({start,{0,0}});
    while(!pq.empty())
    {
        int tmp;
        auto u=pq.top();
        pq.pop();
        if(!vis[u.first])
        {
            vis[u.first]=1;
            for(auto i:mp[u.first])
            {
                tmp=0;
                if(i[0]!=u.first[0])
                    tmp=1;
                if(dis[i].change*5+dis[i].len/3*5>(u.second.len+1)/3*5+(u.second.change+tmp)*5)
                {
                    dis[i].len=u.second.len+1;
                    dis[i].change=u.second.change+tmp;
                }


                pq.push({i,dis[i]});
            }
        }
    }
    cout<<dis[end].len/3*5+dis[end].change*5+10<<'\n';

}
int main()
{
    int n;
    string a,b;
    while(cin>>n)
    {
        while(n--)
        {
            cin>>a>>b;
            mp[a].push_back({b});
            mp[b].push_back({a});

            dis[a]={(int)1e9,0};
            vis[a]=false;
            dis[b]={(int)1e9,0};
            vis[b]=false;
        }
        cin>>a>>b;
        dijkstra(a,b);
        /*
        for(auto i:dis)
        {
            cout<<i.first<<" : ";
            cout<<i.second.len/3*5+i.second.change*5+10<<'\n';
        }
        */
    }
    

}
