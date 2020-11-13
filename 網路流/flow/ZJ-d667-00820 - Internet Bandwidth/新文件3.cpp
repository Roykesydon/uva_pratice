#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define PB push_back
#define SZ(X) (int)X.size()
struct Dinic {
	static const int MXN = 10000;
	struct Edge { int v, f, re; };
	int n, s, t, level[MXN];
	vector<Edge> E[MXN];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t;
		for (int i = 0; i < n; i++) E[i].clear();
	}
	void add_edge(int u, int v, int f) {
		E[u].PB({ v,f,SZ(E[v]) });
		E[v].PB({ u,0,SZ(E[u]) - 1 });
	}
	bool BFS() {
		for (int i = 0; i < n; i++) level[i] = -1;
		queue<int> que;
		que.push(s);
		level[s] = 0;
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (auto it : E[u]) {
				if (it.f > 0 && level[it.v] == -1) {
					level[it.v] = level[u] + 1;
					que.push(it.v);
				}
			}
		}
		return level[t] != -1;
	}
	int DFS(int u, int nf) {
		if (u == t) return nf;
		int res = 0;
		for (auto& it : E[u]) {
			if (it.f > 0 && level[it.v] == level[u] + 1) {
				int tf = DFS(it.v, min(nf, it.f));
				res += tf; nf -= tf; it.f -= tf;
				E[it.v][it.re].f += tf;
				if (nf == 0) return res;
			}
		}
		if (!res) level[u] = -1;
		return res;
	}
	int flow(int res = 0) {
		while (BFS())
			res += DFS(s, 2147483647);
		return res;
	}
}flow;
int main()
{
	int n;
	int cnt = 1;
	int s, t, c;
	int u, v, w,ans;
	while (cin >> n && n)
	{
		cin >> s >> t >> c;
		flow.init(n, s-1, t-1);
		while (c--)
		{
			cin >> u >> v >> w;
			flow.add_edge(u-1, v-1, w);
			flow.add_edge(v-1, u-1, w);
		}
		//cerr << "safe\n";
		ans=flow.flow();
		//cout << ans<<'\n';
		cout << "Network "<<cnt++ << '\n';
		cout << "The bandwidth is " << ans << ".\n";

	}

	return 0;
}
