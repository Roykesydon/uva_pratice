#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;
int n;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int m, r;
	int a, b, w;
	bool err;
	cin >> m;
	while (m--)
	{
		err = false;
		cin >> n >> r;
		dp.resize(n);
		for (int i = 0; i < n; i++)
			dp[i].resize(n, 1e9);
		for (int i = 0; i < r; i++)
		{
			cin >> a >> b >> w;
			dp[a][b] = w;
		}

		for (int i = 0; i < n; i++)
			dp[i][i] = 0;

		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		for(int i=0;i<n;i++)
			if(dp[i][i]<0){
				err=true;
				break;
			}

		if (err)
			cout << "Wonderful Tour\n";
		else
			cout << "No Wonderful Tours\n";
		dp.clear();

	}
}
