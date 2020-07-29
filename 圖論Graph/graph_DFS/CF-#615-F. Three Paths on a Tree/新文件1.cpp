#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int, int>>> edge;
vector<int> ans;
ll len;
ll backup;
int maxp;
ll ans_sum;
void preDFS(int cur, int from, int dep)
{
	//cerr<<"cur= "<<cur<<" from= "<<from<<" dep= "<<dep<<'\n';
	if (dep > len)
	{
		len = dep;
		maxp = cur;
	}
	for (auto i : edge[cur])
	{
		if (i.first == from)
			continue;
		preDFS(i.first, cur, dep + i.second);
	}
}
bool DFS(int cur, int from)
{
	if (cur == ans[1])
		return true;
	for (auto &i : edge[cur])
	{
		if (i.first == from)
			continue;
		if (DFS(i.first, cur))
		{
			cerr << i.first << " has ghost~\n";
			if (cur != ans[1] && cur != ans[0])
				backup = cur;
			ans_sum++;
			i.second = 0;
			//cout<<"cur= "<<cur<<" to "<<i.first<<" : "<<i.second<<'\n';
			return true;
		}
	}
	return false;
}
int main()
{
	int n;
	int u, v;
	cin >> n;
	edge.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		edge[u].push_back({v, 1});
		edge[v].push_back({u, 1});
	}
	len = 1;
	preDFS(1, 1, 1);
	ans.push_back(maxp);
	//cerr<<"safe1\n";

	len = 1;
	preDFS(maxp, maxp, 1);
	ans.push_back(maxp);
	//cerr<<"safe2\n";

	ans_sum = 0;
	DFS(ans[0], ans[0]);
	//cerr<<"safe3\n";

	len = 0;
	preDFS(ans[0], ans[0], 0);
	if (len == 0)
		ans.push_back(backup);
	else
		ans.push_back(maxp);
	ans_sum += len;
	//cerr<<"safe4\n";

	cout << ans_sum << '\n';
	for (int i = 0; i < 3; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
