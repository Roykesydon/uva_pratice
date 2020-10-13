#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>arr;
vector<vector<ll>>dp;
int main()
{
	int t, b, k;
	string str;
	cin>>t;
	for (int cnt=1;cnt<=t;cnt++)
	{
		cin>>b>>k;
		cin>>str;
		arr.resize(str.size());
		dp.resize(1<<str.size());
		for (int i=0;i<dp.size();i++)
			dp[i].resize(k, 0);
		dp[0][0]=1;
		for (int i=0;i<arr.size();i++)
			if (str[i]>='0'&&str[i]<='9')arr[i]=str[i]-'0';
			else arr[i]=str[i]-'A'+10;

		for (int i=0;i<(1<<arr.size());i++)
			for (int g=0;g<k;g++) {
				if (dp[i][g]==0)continue;
				for (int j=0;j<arr.size();j++) {
					if ((1<<j)&i) continue;
					dp[i|(1<<j)][(g*b+arr[j])%k]+=dp[i][g];
				}
			}

		cout<<"Case "<<cnt<<": "<<dp[(1<<arr.size())-1][0]<<'\n';
		arr.clear();
		dp.clear();
	}
	return 0;
}
