#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<ll, ll>>> edge;
vector<pair<ll, ll>> vec;
vector<vector<ll>> dp;
int main()
{
	ll t;
	ll n, m, tmp;
	ll x, y;
	cin >> t;
	cin >> n >> m >> tmp;
	edge.resize(n + 1);
	vec.resize(n + 1);
	dp.resize(t + 1);
	for (int i = 0; i <= t; i++)
		dp[i].resize(n + 1, 1e18);
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		edge[x].push_back({y, tmp}); //where , time
		edge[y].push_back({x, tmp});
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" : ";
		for(auto j:edge[i])
			cout<<j.first<<' '<<j.second<<" || ";
		cout<<'\n' ;
	}
	*/
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		vec[i] = {x, y}; //time cost
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<i<<" : ";
			cout<<vec[i].first<<' '<<vec[i].second<<" || ";
		cout<<'\n' ;
	}
	*/
	if(t<=vec[1].first)
	{
		cout << "It is a trap.\n";
		return 0;
	}
	dp[vec[1].first][1] = vec[1].second;

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i >= vec[j].first)
			{
				if (dp[i - vec[j].first][j] != 1e18)
				{
					//cerr<<i<<' '<<j<<"  situation1\n";
					dp[i][j] = min(dp[i][j], dp[i - vec[j].first][j] + vec[j].second);
				}

			}
			for (auto k : edge[j])//where , time
			{
				if (i>=k.second + vec[k.first].first)// time , cost
				{
					
					if (dp[i-(k.second + vec[k.first].first)][k.first] != 1e18)
					{
						//cerr<<i<<' '<<j<<"  situation2\n";
						//cout<<"k.second= "<<k.second<<' '<<"vec["<<k.first<<"]= "<< vec[k.first].first<<'\n';
						dp[i][j] = min(dp[i][j], dp[i-(k.second + vec[k.first].first)][k.first] + vec[k.first].second);
					}
				}
			}
		}
	}
	/*
	for (int i = 0; i <= t; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (dp[i][j] == 1e18)
				cout << "   INF";
			else
				cout << setw(6) << dp[i][j];
		}

		cout << '\n';
	}
	*/
	if (dp[t][1] != 1e18)
		cout << dp[t][1];
	else
		cout << "It is a trap.\n";

	return 0;
}
