#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>>tree;
vector<ll>id;
vector<ll>dp;
vector<ll>pos;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n;
	ll p,h;
	ll maxn;
	cin>>t;
	for(int cnt=1;cnt<=t;cnt++)
	{
		cin>>n;
		tree.resize(n);
		for(int i=0;i<n;i++)
		{
			cin>>p>>h;
			tree[i].first=p;
			tree[i].second=h;
			pos.push_back(p);
			pos.push_back(p+h);
		}

		sort(tree.begin(),tree.end());
		sort(pos.begin(),pos.end());
		id=pos;
		id.resize(unique(id.begin(),id.end())-id.begin());

		dp.resize(id.size(),0);
		dp[lower_bound(id.begin(),id.end(),tree[0].first)-id.begin()]=tree[0].second;
		dp[lower_bound(id.begin(),id.end(),tree[0].first+tree[0].second)-id.begin()]=tree[0].second;
		for(int i=1;i<n;i++)
		{
			dp[lower_bound(id.begin(),id.end(),tree[i].first+tree[i].second)-id.begin()]=max(dp[lower_bound(id.begin(),id.end(),tree[i].first)-id.begin()]+tree[i].second,dp[lower_bound(id.begin(),id.end(),tree[i].first+tree[i].second)-id.begin()]);
			dp[lower_bound(id.begin(),id.end(),tree[i].first)-id.begin()]=max(dp[lower_bound(id.begin(),id.end(),tree[i].first)-id.begin()],tree[i].second);
			if(lower_bound(id.begin(),id.end(),tree[i].first-tree[i].second)!=id.end()&&*(lower_bound(id.begin(),id.end(),tree[i].first-tree[i].second))==tree[i].first-tree[i].second)
				dp[lower_bound(id.begin(),id.end(),tree[i].first)-id.begin()]=max(dp[lower_bound(id.begin(),id.end(),tree[i].first)-id.begin()],dp[lower_bound(id.begin(),id.end(),tree[i].first-tree[i].second)-id.begin()]+tree[i].second);
		}

		maxn=0;
		for(int i=0;i<dp.size();i++)
			maxn=max(maxn,dp[i]);

		cout<<"Case #"<<cnt<<": ";
		cout<<maxn<<'\n';


		dp.clear();
		id.clear();
		pos.clear();
		tree.clear();
	}

	return 0;
}

