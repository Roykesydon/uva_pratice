#include <bits/stdc++.h>
using namespace std;
#define ll long long
class edge
{
public:
	ll u;
	ll v;
	ll w;
	friend bool operator<(edge a, edge b)
	{
		return a.w < b.w;
	}
};
ll stamp, dep, maxn;
vector<edge> e;
vector<ll> fa;
vector<edge> un_choose;
vector<vector<pair<ll, ll>>> tree_edge;
vector<pair<ll, ll>> in_out;
vector<vector<ll>> anc;
vector<vector<ll>> mx;

ll find(ll x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}
void merge(ll a, ll b)
{
	fa[a] = b;
}
void mx_DFS(ll father, ll cur, ll value)
{
	mx[cur][0] = value;
	ll tmp_father=father;
	for (int k = 1; k < dep; k++)
	{
		mx[cur][k] = max(mx[cur][k - 1], mx[tmp_father][k - 1]);
		tmp_father = anc[tmp_father][k - 1];
	}
	for (auto g : tree_edge[cur])
	{
		if (g.first != father)
			mx_DFS(cur, g.first, g.second);
	}
}
void build(ll father, ll cur)
{
	for (int i = 0; i < dep; i++)
	{
		anc[cur][i] = father;
		father = anc[father][i];
	}
}
void pre_DFS(ll from, ll cur)
{
	in_out[cur].first = stamp++;
	for (auto i : tree_edge[cur])
	{
		if (i.first != from)
			pre_DFS(cur, i.first);
	}
	in_out[cur].second = stamp++;
}
void DFS(ll from, ll cur)
{
	build(from, cur);
	for (auto i : tree_edge[cur])
	{
		if (i.first != from)
		{
			DFS(cur, i.first);
		}
	}
}
bool isFather(ll a, ll b)
{
	return (in_out[a].first <= in_out[b].first && in_out[a].second >= in_out[b].second);
}
void find_max(ll a, ll b)
{
	//cerr<<"find_max : "<< a<<" and "<<b<<'\n';
	for (int i = dep - 1; i >= 0; i--)
	{
		if (!isFather(anc[a][i], b))
		{
			maxn = max(mx[a][i], maxn);
			a = anc[a][i];
		}
	}
	maxn = max(maxn, mx[a][0]);
	//cerr<<"maxn= "<<maxn<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ll n, m;
	ll a, b, w;
	ll ans1;
	ll ans2;
	ll tmpa, tmpb;
	while (cin >> n >> m)
	{
		dep = __lg(n) + 1;
		e.resize(m);
		fa.resize(n + 1);
		tree_edge.resize(n + 1);
		in_out.resize(n + 1);
		anc.resize(n + 1);
		mx.resize(n + 1);
		for (int i = 0; i <= n; i++)
			anc[i].resize(dep);
		for (int i = 0; i <= n; i++)
			mx[i].resize(dep);

		for (int i = 0; i < m; i++)
			cin >> e[i].u >> e[i].v >> e[i].w;
		sort(e.begin(), e.end());
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		ans1 = 0;
		for (int i = 0; i < m; i++)
		{
			if (find(e[i].u) != find(e[i].v))
			{
				merge(find(e[i].u), find(e[i].v));
				tree_edge[e[i].u].push_back({e[i].v, e[i].w});
				tree_edge[e[i].v].push_back({e[i].u, e[i].w});
				ans1 += e[i].w;
			}
			else
			{
				un_choose.push_back({e[i].u, e[i].v, e[i].w});
			}
		}
		// for (int i = 1; i <= n; i++)
		// {
		// 	cerr << "i= " << i << " => ";
		// 	for (auto j : tree_edge[i])
		// 		cerr << j.first << ' ' << j.second << " || ";
		// 	cerr << '\n';
		// }
		// for (int i = 1; i <= n; i++)
		// {
		// 	cerr << "i= " << i << " => ";
		// 	for (auto j : tree_edge[i])
		// 		cerr << j.first << ' ' << j.second << " || ";
		// 	cerr << '\n';
		// }
		stamp = 1;
		pre_DFS(-1, 1);
		// for (int i = 1; i <= n; i++)
		// {
		// 	cerr << "i= " << i << " => ";
		// 	cerr << in_out[i].first << ' ' << in_out[i].second << " || ";
		// 	cerr << '\n';
		// }
		for (int i = 0; i < dep; i++)
			anc[1][i] = 1;
		DFS(1, 1);
		for(int i=0;i<dep;i++)
			mx[1][i]=0;
		mx_DFS(1, 1, 0);
		ans2 = 1e18;
		for (auto i : un_choose)
		{
			tmpa = i.u;
			tmpb = i.v;
			//cerr<<"search "<<tmpa<<" and "<<tmpb<<" :\n";
			maxn = 0;
			if(tmpa==tmpb)continue;
			if (isFather(tmpa, tmpb))
			{
				find_max(tmpb, tmpa);
			}
			else if (isFather(tmpb, tmpa))
			{
				find_max(tmpa, tmpb);
			}
			else
			{
				find_max(tmpa, tmpb);
				find_max(tmpb, tmpa);
			}
			ans2 = min(ans2, ans1 - maxn + i.w);
		}
		cout << ans1 << ' ' << ans2 << '\n';
		mx.clear();
		anc.clear();
		in_out.clear();
		un_choose.clear();
		e.clear();
		fa.clear();
		tree_edge.clear();
	}

	return 0;
}
