#include <bits/stdc++.h>
using namespace std;
struct node
{
	int u, v, w;
};
struct cmp1
{
	bool operator()(node a, node b)
	{
		return a.w > b.w;
	}
};
struct cmp2
{
	bool operator()(node a, node b)
	{
		return a.w < b.w;
	}
};
int f[100000 + 1], n, m, minn, maxx;
map<int, int> mp;
vector<node> edge;
vector<int> fa;
priority_queue<node, vector<node>, cmp1> pq1;
priority_queue<node, vector<node>, cmp2> pq2;
void init()
{
	f[0] = 1;
	f[1] = 1;
	mp[1]++;
	int i = 2;
	int tmp = 0;
	while (true)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] > 100000)
			break;
		mp[f[i]]++;
		i++;
	}
}
int find(int x)
{
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}
void merge(int a, int b)
{
	fa[find(a)] = find(b);
}
void build_small()
{
	fa.clear();
	fa.resize(n);
	for (int i = 0; i < n; i++)
		fa[i] = i;
	for (int i = 0; i < m; i++)
		pq1.push(edge[i]);
	while (!pq1.empty())
	{
		auto u = pq1.top();
		pq1.pop();
		if (find(u.u) != find(u.v))
		{
			//cout<<"u.w= "<<u.w<<'\n';
			merge(u.u, u.v);
			if (u.w)
				minn++;
		}
	}
	for (int i = 0; i < n; i++)
		if (find(i) != find(0))
			minn = 0;
}
void build_big()
{
	fa.clear();
	fa.resize(n);
	for (int i = 0; i < n; i++)
		fa[i] = i;
	for (int i = 0; i < m; i++)
		pq2.push(edge[i]);
	while (!pq2.empty())
	{
		auto u = pq2.top();
		pq2.pop();
		if (find(u.u) != find(u.v))
		{
			merge(u.u, u.v);
			if (u.w)
				maxx++;
		}
	}
	for (int i = 0; i < n; i++)
		if (find(i) != find(0))
			maxx = 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, u, v, x;
	init();
	cin >> t;
	for (int cas = 1; cas <= t; cas++)
	{
		cin >> n >> m;
		edge.clear();
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> x;
			edge.push_back({u - 1, v - 1, x});
		}
		minn = 0, maxx = 0;
		build_small();
		build_big();
		cout << "Case #" << cas << ": ";
		for (int i = minn; i <= maxx; i++)
		{
			if (mp.count(i))
			{
				cout << "Yes\n";
				break;
			}
			if (i == maxx)
				cout << "No\n";
		}
		//cout<<"minn= "<<minn<<" maxx= "<<maxx<<'\n';
	}
}
/*
1
4 4
1 2 1
2 3 1
2 4 1
1 4 0
*/
