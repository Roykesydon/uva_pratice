#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class edge
{
public:
	int to_node;
	long long weight;
};
long long maxn, maxp;
vector<edge>vec[1000000 + 1];

void DFS(int from,int cur, long long value)
{
	if (value >= maxn)
	{
		maxn = value;
		maxp = cur;
	}
	for (auto j : vec[cur])
	{
		if (j.to_node != from)
		{
			DFS(cur,j.to_node, value + j.weight);
		}
	}
}

int main()
{
	int t;
	int x, y, z;
	int n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x >> y >> z;
			vec[x].push_back({ y,z });
			vec[y].push_back({ x,z });
		}
		maxn = 0;
		maxp = 1;
		DFS(-1,1, 0);
		//cout << "maxn=" << maxn << " maxp=" << maxp << '\n';
		maxn = 0;
		DFS(-1, maxp, 0);
		cout << maxn << '\n';
		for (int i = 1; i <= n; i++)
			vec[i].clear();


	}


	return 0;
}
