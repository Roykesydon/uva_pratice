#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>edge;
vector<string>arr;
vector<string>id;
vector<int>ans;
vector<int>father;
int find(int x){
	if(father[x]==x)
		return x;
	return father[x]=find(father[x]);
}
void merge(int a,int b){
	father[find(a)]=find(b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, r,maxn;
	string u,v;
	while (cin>>c>>r&&(c||r)) {
		arr.clear();arr.resize(c);
		for (int i=0;i<c;i++) 
			cin>>arr[i];
		id.clear();id=arr;
		sort(id.begin(), id.end());
		id.resize(unique(id.begin(), id.end())-id.begin());
		for (int i=0;i<arr.size();i++)
			arr[i]=lower_bound(id.begin(), id.end(), arr[i])-id.begin();
		edge.clear();edge.resize(id.size());
		father.clear();father.resize(id.size());
		for(int i=0;i<father.size();i++)
			father[i]=i;
		for(int i=0;i<r;i++){
			cin>>u>>v;
			edge[lower_bound(id.begin(),id.end(),u)-id.begin()].push_back(lower_bound(id.begin(),id.end(),v)-id.begin());
			edge[lower_bound(id.begin(),id.end(),v)-id.begin()].push_back(lower_bound(id.begin(),id.end(),u)-id.begin());
		}
		for(int i=0;i<id.size();i++)
			for(auto j:edge[i])
				if(find(i)!=find(j))
					merge(i,j);
		ans.clear();ans.resize(id.size());
		maxn=0;
		for(int i=0;i<id.size();i++){
			ans[find(i)]++;
			maxn=max(maxn,ans[find(i)]);
		}
		cout<<maxn<<'\n';
	}

	return 0;
}
