#include<iostream>
#include<vector>
#include<algorithm>
#define lowbit(x) (x&-x)
#define ll long long
using namespace std;
vector<ll>arr;
vector<ll>now;
vector<ll>id;
vector<ll>all;
vector<ll>bit;
ll maxn,n;
void modify(ll index, ll value)
{
	while (index <= n)
	{
		bit[index] += value;
		index += lowbit(index);
	}
}
ll query(ll index)
{
	ll tmp=0;
	while (index > 0)
	{
		tmp += bit[index];
		index -= lowbit(index);
	}
	return tmp;
}
int main()
{
	ll ans;
	cin >> n;
	arr.resize(n);
	id.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	id = arr;
	sort(id.begin(), id.end());
	id.resize(unique(id.begin(), id.end()) - id.begin());
	maxn = id.size();
	bit.resize(n + 1,0);
	now.resize(maxn + 1,0);
	all.resize(maxn + 1,0);
	for (int i = 0; i < n; i++)
		arr[i] = (lower_bound(id.begin(), id.end(), arr[i]) - id.begin())+1;
	/*
	for(int i = 0; i < n; i++)
		cerr << arr[i] << ' ';
	cerr << '\n';
	*/
	for (int i = 0; i < n; i++)
		all[arr[i]]++;
	now[arr[0]]++;
	modify(1, 1);
	ans = 0;
	//cerr << "safe1\n";
	for (int i = 1; i < n; i++)
	{
		//cerr <<"i= "<<i<<" now[arr[i]]= "<< now[arr[i]] <<" all[arr[i]]= "<< all[arr[i]]<< endl;
		//cerr << " query(all[arr[i]]-now[arr[i]]) " << query(all[arr[i]] - now[arr[i]])<<'\n';
		ans += i - query(all[arr[i]]-now[arr[i]]);
		now[arr[i]]++;
		modify(now[arr[i]], 1);
	}
	cout << ans << '\n';
	return 0;
}
