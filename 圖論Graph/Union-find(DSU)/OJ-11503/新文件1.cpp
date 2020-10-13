#include<bits/stdc++.h>
using namespace std;
vector<pair<string, string>>arr;
vector<string>id;
vector<vector<int>>edge;
vector<int>sz;
vector<int>f;
int find(int x) {
	if (f[x]==x)
		return x;
	return f[x]=find(f[x]);
}
void merge(int a, int b) {
	sz[find(b)]+=sz[find(a)];
	f[find(a)]=find(b);
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int t, n;
	cin>>t;
	while (t--) {
		cin>>n;
		arr.clear();arr.resize(n);
		id.clear();
		for (int i=0;i<n;i++) {
			cin>>arr[i].first>>arr[i].second;
			id.push_back(arr[i].first);
			id.push_back(arr[i].second);
		}
		sort(id.begin(), id.end());
		id.resize(unique(id.begin(), id.end())-id.begin());
		edge.clear();edge.resize(id.size());
		sz.clear();sz.resize(id.size(), 1);
		f.clear();f.resize(id.size());
		for (int i=0;i<f.size();i++)f[i]=i;
		for (int i=0;i<n;i++) {
			int x1=lower_bound(id.begin(), id.end(), arr[i].first)-id.begin(), x2=lower_bound(id.begin(), id.end(), arr[i].second)-id.begin();
			if (find(x1)!=find(x2))
				merge(x1, x2);
			cout<<sz[find(x1)]<<'\n';
		}
	}
	return 0;
}
