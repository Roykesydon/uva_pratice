#include <bits/stdc++.h>
using namespace std;
int arr[7];
vector<int> dp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int flag, cas = 1;
	while (cin >> arr[1])
	{
		for (int i = 2; i <= 6; i++)
			cin >> arr[i];
		flag = 0;
		for (int i = 1; i <= 6; i++)
			flag += arr[i] * i;
		if (!flag)
			break;
		//cerr << "flag= " << flag << '\n';
		dp.clear();
		dp.resize(flag + 1, -1);
		dp[0] = 0;
		for (int i = 1; i <= 6; i++)
		{
			//cerr << "i= " << i << '\n';
			int sum = 1;
			int k = 1;
			if (arr[i])
			{
				while (arr[i] > sum)
				{
					for (int j = flag; j >= i * k; j--)
						dp[j] = max(dp[j], dp[j - i * k]);
					//cerr << "k= " << k << '\n';
					k *= 2;
					sum += k;
				}
				sum -= k;
				//cerr << "arr[i] - sum= " << arr[i] - sum << '\n';
				for (int j = flag; j >= i * (arr[i] - sum); j--)
					dp[j] = max(dp[j], dp[j - i * (arr[i] - sum)]);
			}
		}
		cout << "Collection #" << cas++ << ":\n";
		if (!(flag & 1) && !dp[flag / 2])
			cout << "Can be divided.\n\n";
		else
			cout << "Can't be divided.\n\n";
	}
	return 0;
}
