#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>edge;
vector<bool>child_vis;
vector<vector<int>>anc;
vector<vector<int>>in_out;
int stamp, m;
void preDFS(int from, int cur) {
	in_out[cur][0]=stamp++;
	for (auto i:edge[cur])
		if (i!=from)
			preDFS(cur, i);
	in_out[cur][1]=stamp++;
}
void DFS(int from, int cur) {
	int tmp_father=from;
	for (int i=0;i<m;i++) {
		anc[cur][i]=tmp_father;
		tmp_father=anc[tmp_father][i];
	}
	for (auto i:edge[cur])
		if (i!=from)
			DFS(cur, i);
}
bool isFather(int a, int b) {
	if (in_out[a][0]<=in_out[b][0]&&in_out[a][1]>=in_out[b][1])
		return true;
	return false;
}
int lca(int a, int b) {
	if (isFather(a, b))
		return a;
	if (isFather(b, a))
		return b;
	for (int i=m-1;i>=0;i--)
		if (!isFather(anc[a][i], b))
			a=anc[a][i];
	return anc[a][0];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, x, tmp, root, q, y;
	cin>>t;
	for (int cas=1;cas<=t;cas++) {
		cout<<"Case "<<cas<<":\n";
		cin>>n;
		m=(int)(log(n)/log(2))+1;
		edge.clear();edge.resize(n+1);
		child_vis.clear();child_vis.resize(n+1, 0);
		child_vis[0]=1;
		for (int i=1;i<=n;i++) {
			cin>>x;
			for (int j=0;j<x;j++) {
				cin>>tmp;
				child_vis[tmp]=1;
				edge[i].push_back(tmp);
				edge[tmp].push_back(i);
			}
		}
		for (int i=1;i<=n;i++)
			if (!child_vis[i])
				root=i;
		anc.clear();anc.resize(n+1);
		for (int i=1;i<=n;i++)
			anc[i].resize(m);
		for (int i=0;i<m;i++)
			anc[root][i]=root;
		in_out.clear();in_out.resize(n+1);
		for (int i=0;i<=n;i++)
			in_out[i].resize(2);
		stamp=0;
		preDFS(root, root);
		DFS(root, root);
		cin>>q;
		for (int i=0;i<q;i++) {
			cin>>x>>y;
			cout<<lca(x, y)<<'\n';
		}
	}
	return 0;
}
