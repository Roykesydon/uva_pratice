#include<bits/stdc++.h>
using namespace std;
vector<int>health;
vector<vector<int>>arr;
map<int, int>dp;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, cnt=0;
	char ch;
	cin>>t;
	while (t--)
	{
		cin>>n;
		health.resize(n);
		arr.resize(n);
		for (int i=0;i<n;i++)
			arr[i].resize(n);
		for (int i=0;i<n;i++)
			cin>>health[i];

		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				cin>>ch;
				arr[i][j]=ch-'0';
			}

		for (int i=0;i<(1<<n);i++)
			dp[i]=1e9;
		dp[0]=0;

		for (int i=0;i<(1<<n);i++)
			for (int j=0;j<n;j++)
			{
				if (i&(1<<j))continue;
				int damage=1;
				for (int k=0;k<n;k++)
					if (i&(1<<k))
						damage=max(damage, arr[k][j]);

				dp[i|(1<<j)]=min(dp[i|(1<<j)], dp[i]+(((health[j]+damage)%damage==0)?health[j]/damage:(health[j]/damage)+1));
			}
		cout<<"Case "<<++cnt<<": "<<dp[(1<<n)-1]<<'\n';
		dp.clear();
		arr.clear();
		health.clear();
	}


	return 0;
}
