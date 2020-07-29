#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		if (a.second * b.second < 0)
			return a.second > b.second;
		else
			return a.first < b.first;
	}
};
class cmp2
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second+a.first > b.second+b.first;
	}
};
vector<pair<int, int>> arr;
vector<pair<int, int>> item;
vector<int> dp;
int main()
{
	int n, r;
	int maxn = 0;
	int ans;
	cin >> n >> r;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end(), cmp());

	for (int i = 0; i < n; i++)
	{
		if (arr[i].second < 0)
		{
			item.push_back(arr[i]);
			continue;
		}
		if (arr[i].first <= r)
		{
			r += arr[i].second;
			maxn++;
		}
	}
	cerr << "maxn= "<<maxn<<" r= "<<r<<'\n';
	sort(item.begin(),item.end(),cmp2());
	dp.resize(r + 1, 0);
	for (int j = 0; j < item.size(); j++)
	{
		for (int i = item[j].first; i <= r; i++)
		{
			if (j == 0)
				dp[i+item[j].second] = 1;
			else
			{
				if (i +item[j].second >= 0)
					dp[i+item[j].second] = max(dp[i]+1, dp[i+item[j].second]);
			}
		}
	}

	
	ans = 0;
	for (int i = 0; i <= r; i++)
		ans = max(ans, dp[i]);
	ans += maxn;
	cout << ans << '\n';

	item.clear();
	return 0;
}
