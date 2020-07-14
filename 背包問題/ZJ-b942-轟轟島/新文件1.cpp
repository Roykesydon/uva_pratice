#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
vector<int> arr;
int main()
{
	int x, cnt,ans;
	int sum,mid,l,r;
	string str;
	stringstream ss;
	while (getline(cin, str))
	{
		arr.resize(29);
		ss.clear();
		ss.str("");
		ss << str;
		cnt = 0;
		while (ss >> x)
			arr[cnt++] = x;
		sum=0;
		//cerr<<0<<'\n';
		for(int i=0;i<cnt;i++)
			sum+=arr[i];
		// for(int i=0;i<cnt;i++)
		// 	cout<<arr[i]<<' ';
		// cout<<endl;
		//cerr<<1<<'\n';
		dp.resize(sum+1,0);
		dp[0]=1;
		for(int i=0;i<cnt;i++)
		{
			for(int j=sum;j>=arr[i];j--)
				dp[j]=max(dp[j],dp[j-arr[i]]);
		}
		cerr<<2<<'\n';
		l=r=mid=sum/2;
		while(1)
		{
			if(l>=0)
			{
				if(dp[l]>0)
				{
					ans=l;
					break;
				}
				l--;
			}
			if(r<=sum)
			{
				if(dp[r]>0)
				{
					ans=r;
					break;
				}
				r++;
			}
		}
		cout<<(sum-ans)*ans<<'\n';
		
		
		dp.clear();
		arr.clear();
	}
}
