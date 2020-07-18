#include<iostream>
#include<deque>
#include<vector>
using namespace std;
#define ll long long
vector<ll>arr;
vector<ll>sum;
vector<ll>dp;
deque < pair<ll,ll> >deq;
double banana(pair<ll, ll> a,ll b)
{
	return a.first*b+a.second;
}
double banana2(pair<ll, ll> a, pair<ll, ll> b)
{
	return (double)(b.second - a.second) / (a.first - b.first);
}
/*
m1x+b1=m2x+b2;
x=(b2-b1)/(m1-m2);
2*x+1=5*x-3;
*/
int main()
{
	ll n, m;
	while (cin >> n >> m)
	{
		arr.resize(n);
		sum.resize(n,0);
		dp.resize(n,0);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i == 0)sum[i] = arr[i];
			else sum[i] = sum[i - 1] + arr[i];
		}
		deq.push_back({ 0,0 });
		for (int i = 0; i < n; i++)
		{
			
			while (deq.size() > 1 && banana(deq[0], sum[i]) <= banana(deq[1], sum[i]))
				deq.pop_front();
			dp[i] = -banana(deq.front(), sum[i]) + m + sum[i] * sum[i];
			ll a = 2 * sum[i], b = -(dp[i] + sum[i] * sum[i]);
			while (deq.back().first == a && deq.back().second<=b)
			{
				deq.pop_back();
			}
			while (deq.size() > 1 && banana2(deq.back(), { a,b }) <= banana2(deq[deq.size() - 1], deq[deq.size() - 2]))
			{
				deq.pop_back();
			}
			deq.push_back({ a,b });
		}
		cout << dp[n - 1] << '\n';

		deq.clear();
		dp.clear();
		arr.clear();
		sum.clear();
	}


	return 0;
}
/*
dp[i]=dp[j]+(sum[i]-sum[j])^2+m
dp[i]=dp[j]+sum[i]^2-sum[i]*sum[j]+sum[j]^2+m
dp[i]= ( dp[j]+sum[j]^2 ) ( -2sum[i]*sum[j] ) + ( m + sum[i]^2)
m= -2 *sum[j] //求最小值，多個負號 變成正的 2 *sum[j]
x= sum[i]
b= dp[j]+sum[j]^2 求最小值，多個負號 變成-dp[j]+sum[j]^2
*/
