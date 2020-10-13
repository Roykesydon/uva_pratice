#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edge;
vector<int> toposort;
vector<bool> vis;
vector<vector<int>> un_edge;
vector<pair<int, int>> ans;
vector<int>topo_pos;
void dfs(int u)
{
	if (!vis[u])
	{
		vis[u] = true;
		for (auto j : edge[u])
			dfs(j);
		toposort.push_back(u);
	}
}
int main()
{
	int t;
	int n, m;
	int c, x, y;
	bool flag;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vis.resize(n + 1, 0);
		edge.resize(n + 1);
		un_edge.resize(n + 1);
		topo_pos.resize(n+1);
		for (int i = 0; i < m; i++)
		{
			cin >> c >> x >> y;
			if (c)
			{
				edge[x].push_back(y);
			}

			else
			{
				un_edge[x].push_back(y);
				un_edge[y].push_back(x);
			}
		}
		for (int i = 1; i <= n; i++)
			dfs(i);
		reverse(toposort.begin(), toposort.end());
		for(int i=1;i<=n;i++)
		{
			topo_pos[toposort[i-1]]=i;
		}
		/*
		cerr << "toposort: ";
		for (auto i : toposort)
		    cerr << i << ' ';
		cerr << '\n';
		*/
		flag = true;
		for (int i = 1; i <= n; i++)
		{
			for (auto j : edge[i])
			{
				if (topo_pos[j] < topo_pos[i])
				{
					// cerr<<"j= "<<j<<" i= "<<i<<'\n';
					// cerr<<"find(i)= "<<find(i)<<" find(j)= "<<find(j)<<'\n';
					flag = false;
					break;
				}
				ans.push_back({i,j});
			}
			if (!flag)
				break;
		}

		if (!flag)
		{
			cout << "NO\n";
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(auto j:un_edge[i])
				{
					if(topo_pos[j]>topo_pos[i])
						ans.push_back({i,j});
				}
			}
			cout << "YES\n";
			for (auto j : ans)
				cout << j.first << ' ' << j.second << '\n';
		}
		topo_pos.clear();
		ans.clear();
		toposort.clear();
		vis.clear();
		edge.clear();
		un_edge.clear();
	}
	return 0;
}
