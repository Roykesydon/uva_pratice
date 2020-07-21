#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edge;
int dfs(int cur, int from, int value)
{
	int tmp_max = value;
	for (auto i : edge[cur])
	{
		if (i == from)
			continue;
		tmp_max = max(dfs(i, cur, value + 1), tmp_max);
	}
	return tmp_max;
}
int main()
{
	int n, r, h, m, tmp;
	int x, y;
	int ans;
	cin >> n >> r >> h >> m;
	edge.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	//cerr<<"safe\n";
	/*
	for(int i=1;i<=n;i++)
	{
		cerr<<i<<" : \n";
		for(auto j:edge[i])
			cout<<j<<' ';
		cout<<'\n';
	}
	*/
	ans = n;
	for (int i = 1; i <= n; i++)
	{
		tmp=1;
		for (auto k : edge[i])
		{
			if(i==h||i==m)tmp = max(tmp, dfs(k, i, 2)-1);
			else tmp = max(tmp, dfs(k, i, 2));
		}
		ans=min(ans,tmp);
	}
	cout << ans << '\n';

	return 0;
}
