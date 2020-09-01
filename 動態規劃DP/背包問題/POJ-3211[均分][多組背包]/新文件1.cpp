#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, int> mp;
vector<vector<int> > dp;
vector<vector<int> > arr;
vector<int> total;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, cnt = 1, x;
	int sum = 0;
	string str;
	while (cin >> n >> m && (n || m))
	{
		cnt = 1;
		mp.clear();
		arr.clear();
		arr.resize(n + 1);
		total.clear();
		total.resize(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> str;
			mp[str] = cnt++;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x >> str;
			total[mp[str]] += x;
			arr[mp[str]].push_back(x);
		}
		dp.clear();
		dp.resize(n + 1);
		for (int i = 0; i <= n; i++)
			dp[i].resize(total[i] / 2 + 1, 0);
		for (int i = 0; i <= n; i++)
			dp[i][0] = 1;
		// for(int i=1;i<=n;i++)
		// 	cout<<total[i]<<'\n';
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < arr[i].size(); j++)
				for (int k = total[i] / 2; k >= arr[i][j]; k--)
					dp[i][k] = max(dp[i][k], dp[i][k - arr[i][j]]);
			for (int j = total[i] / 2; j >= 0; j--)
				if (dp[i][j])
				{
					sum += max(j, total[i] - j);
					break;
				}
		}
		cout << sum << '\n';
	}
	return 0;
}

