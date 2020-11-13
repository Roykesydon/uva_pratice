#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int>>> arr; //w,l,h
vector<int> dp;
int main()
{
	int n, d, ans = 0;
	cin >> n >> d;
	dp.resize(1e8 + 1, 0);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].second.first >> arr[i].first >> arr[i].second.second;
	sort(arr.begin(), arr.end());
	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i].second.first + dp[arr[i].first] > d)
			ans++;
		for (int j = 0; j < arr[i].first; j++)
		{
			if (j + arr[i].first > 1e8)
				break;
			dp[j] = max(dp[j], dp[j + arr[i].first] + arr[i].second.second);
			if(dp[j]>1e8)
				dp[j]=1e8+1;
		}
	}
	cout << ans << '\n';
	return 0;
}
