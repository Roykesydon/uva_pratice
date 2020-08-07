#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a.second>b.second;
	}
};
vector<vector<int>> arr;
vector<vector<pair<int, int>>> edge;
vector<int>dis;
vector<bool>vis;
void dijkstra()
{
	dis[0]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
	pq.push({0,0});
	while(!pq.empty())
	{
		auto u=pq.top();
		pq.pop();
		if(!vis[u.first])
		{
			vis[u.first]=1;
			for(auto i:edge[u.first])
			{
				if(dis[i.first]>dis[u.first]+i.second)
				{
					dis[i.first]=dis[u.first]+i.second;
					pq.push({i.first,dis[i.first]});
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	int n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		arr.resize(n + 1);
		edge.resize((n + 1) * (m + 1) + 1);
		dis.resize(n*m+1,1e9);
		vis.resize(n*m+1,0);
		for (int i = 1; i <= n; i++)
			arr[i].resize(m + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> arr[i][j];

		edge[0].push_back({1, arr[1][1]});
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				int id = (i - 1) * m + j;
				if (i - 1 >= 1)
					edge[id].push_back({id - m,arr[i-1][j]});
				if(i+1<=n)
					edge[id].push_back({id+m,arr[i+1][j]});
				if(j-1>=1)
					edge[id].push_back({id-1,arr[i][j-1]});
				if(j+1<=m)
					edge[id].push_back({id+1,arr[i][j+1]});
			}
		}
		// for(int i=0;i<=n*m;i++)
		// {
		// 	cerr<<"i= "<<i<<endl;
		// 	for(auto j: edge[i])
		// 	{
		// 		cerr<<j.first<<' '<<j.second<<" || ";
		// 	}
		// 	cerr<<endl;
		// }
		//cerr<<"OK1\n";
		dijkstra();
		cout<<dis[n*m]<<'\n';


		vis.clear();
		dis.clear();
		edge.clear();
		arr.clear();
	}

	return 0;
}
