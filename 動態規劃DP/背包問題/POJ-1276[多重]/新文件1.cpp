#include <iostream>
#include<vector>
using namespace std;
vector<pair<int, int> > arr;
vector<int> dp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int total, n;
	while (cin >> total >> n)
	{
		arr.clear();
		arr.resize(n + 1);
		dp.clear();
		dp.resize(total + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
			cin >> arr[i].first >> arr[i].second; //cnt_value
		for (int i = 1; i <= n; i++)
		{
			//cerr<<"i= "<<i<<'\n';
			int sum = 1, k = 1;
			while (arr[i].first > sum)
			{
				for (int j = total; j >= k * arr[i].second; j--)
					dp[j] = max(dp[j], dp[j - k * arr[i].second]);
				//cerr<<"k= "<<k<<'\n';
				k *= 2;
				sum += k;
			}
			sum -= k;
			//cerr<<"(arr[i].first - sum)= "<<(arr[i].first - sum)<<'\n';
			for (int j = total; j >= (arr[i].first - sum)*arr[i].second; j--)
				dp[j] = max(dp[j], dp[j-(arr[i].first - sum)*arr[i].second]);
		}
		for (int i = total; i >= 0; i--)
			if (dp[i])
			{
				cout << i << '\n';
				break;
			}
	}
	return 0;
}
