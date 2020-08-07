#include<bits/stdc++.h>
using namespace std;
map<string, int>dp;
int DFS(string str)
{
	if(dp.count(str)!=0)
		return dp[str];
	int cnt=0;
	for (int i=0;i<12;i++)
		if (str[i]=='o')cnt++;
	dp[str]=cnt;

	for (int i=0;i<12;i++)
	{
		if (i-2>=0)
		{
			if (str[i]=='o'&&str[i-1]=='o'&&str[i-2]=='-')
			{
				string tmp;
				tmp=str;
				tmp[i]='-';
				tmp[i-1]='-';
				tmp[i-2]='o';
				dp[str]=min(dp[str], DFS(tmp));
			}
		}
		if (i+2<=11)
		{
			if (str[i]=='o'&&str[i+1]=='o'&&str[i+2]=='-')
			{
				string tmp;
				tmp=str;
				tmp[i]='-';
				tmp[i+1]='-';
				tmp[i+2]='o';
				dp[str]=min(dp[str], DFS(tmp));
			}
		}
	}

	return dp[str];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string str;
	int tmp[12];
	cin>>n;
	while (n--)
	{
		cin>>str;
		DFS(str);
		cout<<dp[str]<<'\n';
	}


	return 0;
}
