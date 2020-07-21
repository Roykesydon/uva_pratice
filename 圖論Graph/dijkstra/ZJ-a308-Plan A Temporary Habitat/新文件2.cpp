#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct	edge
{
	int to_node;
	long long weight;
};
class cmp
{
public:
	bool operator()(edge a, edge b)
	{
		if (a.weight > b.weight)
			return true;
		return false;
	}
};
long long dis[200000 + 1];
bool vis[200000 + 1];
vector < edge > vec[200000];
void dijkstra(int n,int s)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = 1e18;
		vis[i] = 0;
	}
	dis[s] = 0;
	priority_queue<edge, vector<edge>, cmp > pq;
	pq.push({ s,0 });
	while (!pq.empty())
	{
		auto u = pq.top();
		pq.pop();
		if(!vis[u.to_node])
		{
			vis[u.to_node] = 1;
			for (auto i : vec[u.to_node])
			{
				if (dis[i.to_node] > dis[u.to_node] + i.weight)
				{
					dis[i.to_node] = dis[u.to_node] + i.weight;
					pq.push({i.to_node,dis[i.to_node]});
				}
			}
		}
	}
}

int main()
{
	int n, m, s, t;
	int x, y, z;
	while (cin >> n >> m >> s >> t)
	{
		for (int i = 0; i < m; i++)
		{
			cin >> x>>y>>z;
			vec[x].push_back({ y,z });
			vec[y].push_back({ x,z });
		}
		dijkstra(n,s);
		cout << dis[t]<<'\n';
		for (int i = 1; i <= n; i++)
			vec[i].clear();
	}


	return 0;
}
