#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class node
{
public:
	int h, a, c;
};
class cmp
{
public:
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second<b.second;
	}
}; vector<node> arr;
vector<int> dp;
vector<pair<int, int> > item;
int main()
{
	int k,maxn=0;
	cin >> k;
	arr.resize(k);
	for (int i = 0; i < k; i++){
		cin >> arr[i].h >> arr[i].a >> arr[i].c;
		maxn=max(maxn,arr[i].a);
	}

	for (int i = 0; i < k; i++)
	{
		//cerr<<"i= "<<i<<"\n\n";
		int sum = 1, x = 1;
		while (arr[i].c > sum)
		{
			//cerr<<"x= "<<x<<'\n';
			item.push_back({arr[i].h * x, arr[i].a});
			x *= 2;
			sum += x;
		}
		sum -= x;
		//cerr<<"arr[i].c - sum= "<<arr[i].c - sum<<'\n';
		item.push_back({(arr[i].c - sum) * arr[i].h, arr[i].a});
	}
	sort(item.begin(),item.end(),cmp());
	dp.resize(maxn+1,0);
	dp[0]=1;
	for(int i=0;i<item.size();i++)
		for(int j=item[i].second;j>=0;j--)
			if(j-item[i].first>=0)
				dp[j]=max(dp[j],dp[j-item[i].first]);
	for(int i=maxn;i>=0;i--){
		if(dp[i]){
			cout<<i<<'\n';
			break;
		}
	}
	/*
	if(x+y) is easier than (y+x) && choose both independently is fine;
		put x firstly need to paid height that at least : y.a
		put y firstly need to paid height that at least : x.a
		y.a < x.a;
		x.a>y.a;
	*/
	return 0;
}
