#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

class edge{
public:
    string to_node;
    int weight;
};
class cmp
{
    public:
    bool operator()(edge a,edge b)
    {
        if(a.weight<b.weight)
            return true;
        return false;
    }
};
map<string,int>dis;
map<string,bool>vis;
map<string, vector<edge> >mp;
void dijkstra(string a)
{
    dis[a]=1e9;
    priority_queue<edge,vector<edge>,cmp >pq;
    pq.push({a,0});
    while(!pq.empty())
    {
        edge u=pq.top();
        //cout<<"choose edge:"<<u.to_node<<' '<<u.weight<<endl;
        pq.pop();
        if(!vis[u.to_node])
        {
            vis[u.to_node]=1;
            for(auto i:mp[u.to_node])//仔細一看才發現這題不是單純的最短路徑...
            {
                if(dis[i.to_node]<min(dis[u.to_node],i.weight))
                {
                    dis[i.to_node]=min(dis[u.to_node],i.weight);
                    pq.push({i.to_node,dis[i.to_node]});
                }
            }
        }
    }
    
}
int main()
{
    int count=0;
    int n, r,w;
    string a, b;
    while (cin >> n >> r)
    {
        if(!n&&!r)
            break;
        for (int i = 0; i < r; i++)
        {
            cin >> a >> b >> w;
            mp[a].push_back({ b,w });
            mp[b].push_back({ a,w });
            dis[a]=-1;
            dis[b]=-1;
            vis[a]=false;
            vis[b]=false;
        }
        cin>>a>>b;
        dijkstra(a);
        cout<<"Scenario #"<<++count<<'\n';
        cout<<dis[b]<<" tons\n\n";
        
        /*
        for (map<string, vector<edge> >::iterator mpi = mp.begin(); mpi != mp.end(); mpi++)
        {
            cout << endl;
            cout << mpi->first << endl;
            for (vector<edge>::iterator veci = mpi->second.begin(); veci != mpi->second.end(); veci++)
                cout << veci->to_node << ' ' << veci->weight << ' ';
        }
        */
       




        for (map<string, vector<edge> >::iterator mpi = mp.begin(); mpi != mp.end(); mpi++)
            mpi->second.clear();
        mp.clear();
        dis.clear();
    }

    system("PAUSE");
    return 0;
}
