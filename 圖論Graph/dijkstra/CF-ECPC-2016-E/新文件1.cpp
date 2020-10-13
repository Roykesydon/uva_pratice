#include<bits/stdc++.h>
using namespace std;
struct cmp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a.first>b.first;
	}
};
vector<vector<int> >edge;
vector<int>dis;
vector<bool>vis;
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp>pq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("jumping.in","r",stdin);
	int t,n,x;
	cin>>t;
	while(t--){
		cin>>n;
		edge.clear();
		edge.resize(n);
		for(int i=0;i<n;i++){
			cin>>x;
		if(i+x>=0&&i+x<n)
			edge[i+x].push_back(i);
		if(i-x>=0&&i-x<n)
			edge[i-x].push_back(i);
		}
		dis.clear();
		dis.resize(n,1e9);
		vis.clear();
		vis.resize(n,0);
		dis[n-1]=0;
		pq.push({0,n-1});
		while(!pq.empty()){
			auto u=pq.top();
			pq.pop();
			if(!vis[u.second]){
				vis[u.second]=1;
				for(auto i:edge[u.second]){
					if(dis[i]>dis[u.second]+1){
						dis[i]=dis[u.second]+1;
						pq.push({dis[i],i});
					}
				}
			}
		}
		for(int i=0;i<n;i++)
			cout<<((dis[i]==1e9)?-1:dis[i])<<'\n';
	}

	return 0;
}
