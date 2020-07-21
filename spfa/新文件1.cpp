//     ____              __                       __
//    / __ \____  __  __/ /_____  _______  ______/ /___  ____  ___
//   / /_/ / __ \/ / / / //_/ _ \/ ___/ / / / __  / __ \/ __ \/ _ \
//  / _, _/ /_/ / /_/ / ,< /  __(__  ) /_/ / /_/ / /_/ / / / /  __/
// /_/ |_|\____/\__, /_/|_|\___/____/\__, /\__,_/\____/_/ /_/\___/
//             /____/               /____/
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, double>>> edge;
vector<double> dis;
vector<bool> in_deq;
vector<int> len;
bool spfa(int n)
{
	deque<int> dq;
	dis[0] = 0;
	dq.push_back(0);
	in_deq[0] = 1;
	while (!dq.empty())
	{
		int u = dq.front();
		dq.pop_front();
		in_deq[u] = 0;
		//cerr<<"u= "<<u<<'\n';
		for (auto i : edge[u])
		{
			if (dis[i.first] > i.second + dis[u])
			{
				dis[i.first] = i.second + dis[u];
				len[i.first] = len[u] + 1;
				if (len[i.first] > n)
					return true;
				if (in_deq[i.first])
					continue;

				if (!dq.empty()&&dis[dq.front()] > dis[i.first])
					dq.push_front(i.first);
				else
					dq.push_back(i.first);
				//上面兩行目的是優化
				in_deq[i.first] = 1;
			}
		}
	}
	return false;
}
int main()
{
	int n, m;
	int x, y;
	double tmp;
	bool ans = false;
	cin >> n >> m;
	edge.resize(n);
	dis.resize(n, 1e18);
	len.resize(n, 1);
	in_deq.resize(n, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> tmp;
		tmp = -1.0 * log(tmp);
		edge[x - 1].push_back({y - 1, tmp});
	}

	/*
	for (int i = 0; i < m; i++)
	{
		for(auto j:edge[i])
			cout<<j.first<<' '<<j.second<<" || ";
		cout<<'\n';
	}
	*/

	// for (int i = 0; i < n; i++)
	// 	cout << dis[i] << ' ';

	//cerr<<"safe\n";
	if (spfa(n))
		cout << "inadmissible\n";
	else
		cout << "admissible\n";
	return 0;
}
