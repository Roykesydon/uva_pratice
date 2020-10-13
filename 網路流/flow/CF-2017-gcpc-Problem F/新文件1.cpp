#include<bits/stdc++.h>
using namespace std;
#define SZ(x) (int)x.size()
#define PB(x,y,z) push_back(x,y,z)
struct Dinic{
  static const int MXN = 10000;
  struct Edge{ int v,f,re; };
  int n,s,t,level[MXN];
  vector<Edge> E[MXN];
  void init(int _n, int _s, int _t){
    n = _n; s = _s; t = _t;
    for (int i=0; i<n; i++) E[i].clear();
  }
  void add_edge(int u, int v, int f){
    E[u].PB({v,f,SZ(E[v])});
    E[v].PB({u,0,SZ(E[u])-1});
  }
  bool BFS(){
    for (int i=0; i<n; i++) level[i] = -1;
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while (!que.empty()){
      int u = que.front(); que.pop();
      for (auto it : E[u]){
        if (it.f > 0 && level[it.v] == -1){
          level[it.v] = level[u]+1;
          que.push(it.v);
        }
      }
    }
    return level[t] != -1;
  }
  int DFS(int u, int nf){
    if (u == t) return nf;
    int res = 0;
    for (auto &it : E[u]){
      if (it.f > 0 && level[it.v] == level[u]+1){
        int tf = DFS(it.v, min(nf,it.f));
        res += tf; nf -= tf; it.f -= tf;
        E[it.v][it.re].f += tf;
        if (nf == 0) return res;
      }
    }
    if (!res) level[u] = -1;
    return res;
  }
  int flow(int res=0){
    while ( BFS() )
      res += DFS(s,2147483647);
    return res;
  }
}flow,tmp_flow;

int main()
{
	int m,n,k;
	int x,y;
	int maxn=0;
  int ans;
	cin>>m>>n>>k;
	flow.init(m+n+2+1,m+n+1,m+n+2);	//setting
	for(int i=1;i<=m;i++)			//start to left
		flow.add_edge(m+n+1,i,1);
	for(int i=0;i<k;i++)
	{
		cin>>x>>y;
		flow.add_edge(x,m+y,1);
	}
	for(int i=1;i<=n;i++)
		flow.add_edge(i+m,m+n+2,1);
  ans=flow.flow();
	tmp_flow=flow;
	for(int i=1;i<=m;i++)
	{
		flow.add_edge(m+n+1,i,2);
		maxn=max(maxn,flow.flow());
		flow=tmp_flow;
	}
	cout<<ans+maxn<<'\n';
	return 0;
}
