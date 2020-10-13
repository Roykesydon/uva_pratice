#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> dp;
deque<pair<int, int> > deq;
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		arr.resize(n);
		dp.resize(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
		{
			if (i < 3)
			{
				dp[i] = arr[i];
				while (!deq.empty() && deq.back().first < dp[i])
					deq.pop_back();
				if (!i)
					deq.push_back({dp[i], i});
			}
			else
			{
				dp[i] = arr[i];
				dp[i] += deq.front().first;
				// while (!deq.empty() && deq.front().second <= i - 3)
				// 	deq.pop_front();
				while (!deq.empty() && deq.back().first < dp[i-3+1])
					deq.pop_back();
				deq.push_back({dp[i-3+1], i-3+1});
			}
		}
		/*
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << dp[i] << ' ';
		cout << endl;
		*/
		if (n <= 3)
		{
			int maxd = 0;
			for (int i = 0; i < n; i++)
				maxd = max(maxd, dp[i]);
			cout << maxd << '\n';
		}
		else
		{
			int maxd = 0;
			for (int i = n-1; i > n - 3; i--)
				maxd = max(maxd, dp[i]);
			cout << maxd << '\n';
		}

		deq.clear();
		dp.clear();
		arr.clear();
	}

	return 0;
}
