#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int,ll>>>edge;
vector<ll>dis;
vector<ll>ans;
set<int>ans_node;
ll minn;
ll preDFS(int cur,int from,ll x)
{
	//cerr<<"cur= "<<cur<<" from= "<<from<<'\n';
	ll tmp=0;
	for(auto i:edge[cur])
	{
		if(i.first==from)
			continue;
		tmp+=preDFS(i.first,cur,i.second);
	}
	dis[cur]=tmp;
	return dis[cur]+x;
}
void DFS(int cur,int from,ll value)
{
	ll tmp;
	if(cur!=1)
		ans[cur]=ans[from]+value;

	if(ans[cur]==minn)
		ans_node.insert(cur);
	else if(ans[cur]<minn)
	{
		minn=ans[cur];
		ans_node.clear();
		ans_node.insert(cur);
	}

	for(auto i:edge[cur])
	{
		if(i.first==from)
			continue;
		tmp=(i.second==1)?-1:1;
		DFS(i.first,cur,tmp);
	}
	
}
int main()
{
	int n;
	int u,v;
	cin>>n;
	edge.resize(n+1);
	dis.resize(n+1);
	ans.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		edge[u].push_back({v,0});
		edge[v].push_back({u,1});
	}
	preDFS(1,1,0);
	
	// for(int i=1;i<dis.size();i++)
	// 	cerr<< dis[i]<<' ';
	// cerr<<'\n';

	ans_node.insert(1);
	ans[1]=dis[1];
	minn=dis[1];
	DFS(1,1,0);

	// for(int i=1;i<ans.size();i++)
	// 	cerr<< ans[i]<<' ';
	// cerr<<'\n';

	cout<<minn<<'\n';
	for(auto i:ans_node)
		cout<<i<<' ';
	cout<<'\n';
	return 0;
}
