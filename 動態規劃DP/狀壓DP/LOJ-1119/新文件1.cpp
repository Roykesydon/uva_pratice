#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>>arr;
map<int,int>dp;
int main()
{
	int t, n;
	int cnt=0;
	cin>>t;
	while (t--)
	{
		cin>>n;
		arr.resize(n);
		for (int i=0;i<n;i++)
			arr[i].resize(n);


		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				cin>>arr[i][j];
		for(int i=0;i<(1<<n);i++)
			dp[i]=1e9;
		dp[0]=0;
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))continue;

				int sum=arr[j][j];
				for(int k=0;k<n;k++)
					if(i&(1<<k))
						sum+=arr[j][k];

				dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+sum);
			}
		}

		cout<<"Case "<<++cnt<<": "<<dp[(1<<n)-1]<<'\n';
		arr.clear();
		dp.clear();
	}

	return 0;
}
