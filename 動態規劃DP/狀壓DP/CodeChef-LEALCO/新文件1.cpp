#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
vector<int>dp;
int t, n, k, m;
int solve(int state)
{
	int tmp[n];
	bool flag;
	int tmp_state;
	int i, cnt=0;
	for (int i=0;i<n;i++)
		tmp[i]=arr[i];
	i=0;
	tmp_state=state;
	while (tmp_state)
	{
		if (tmp_state&1)
		{
			tmp[i]++;
			cnt++;
		}
		tmp_state>>=1;
		i++;
	}
	//cerr<<"state= "<<state<<" cnt= "<<cnt<<'\n';
	flag=1;
	for (int i=0;i+k<=n;i++)
	{
		int tmpsum=0;
		int maxn=0;
		for (int j=0;j<k;j++)
			maxn=max(tmp[i+j], maxn);
		for (int j=0;j<k;j++)
			if (tmp[i+j]==maxn)
				tmpsum++;

		if (tmpsum>=m)
		{
			flag=0;
			break;
		}
	}
	// cerr<<"return "<<(flag)?cnt:-1;
	//cerr<<endl;
	if (flag)return cnt;
	else	return -1;
}
void shut()
{
	arr.clear();
	dp.clear();
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans;
	while (cin>>t) {
		while (t--)
		{
			cin>>n>>k>>m;
			arr.resize(n);
			dp.resize(1<<n);
			for (int i=0;i<n;i++)
				cin>>arr[i];
			if (m==1)
			{
				cout<<-1<<'\n';
				shut();
				continue;
			}
			for (int i=0;i<(1<<n);i++)
				dp[i]=solve(i);

			ans=-1;
			for (int i=0;i<(1<<n);i++)
				if (dp[i]!=-1) {
					if (ans==-1)ans=dp[i];
					else ans=min(ans, dp[i]);
				}
			cout<<ans<<'\n';
			shut();
		}
	}
}
