#include <bits/stdc++.h>
using namespace std;
#define MAXN 360
vector<pair<int, int>> arr;
vector<int> dp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, l;
	while (cin >> n >> l)
	{
		arr.clear();
		arr.resize(n);
		dp.clear();
		dp.resize(MAXN + 1, 0);
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second; //time,damage
		for (int j = 0; j <= MAXN; j++)
			for (int i = 0; i < n; i++)
				if (j + arr[i].first <= MAXN)
					dp[j + arr[i].first] = max(dp[j + arr[i].first], dp[j] + j * arr[i].second);

		for (int i = 0; i <= MAXN; i++)
			if (dp[i] >= l)
			{
				cout << i << '\n';
				break;
			}
	}
	return 0;
}
