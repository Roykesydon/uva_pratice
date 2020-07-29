#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
ll max3(ll a, ll b, ll c)
{
	return max(c, max(a, b));
}
ll max4(ll a, ll b, ll c, ll d)
{
	return max(a, max3(b, c, d));
}
inline void init_max_cost(ll *a, ll &b, ll &c)
{
	//memset(a, 0, sizeof(a));
	for (int i = 0; i < 3; i++)
		a[i] = 0;
	b = 0;
	c = 0;
}
inline void choose_max3_of_c1(ll *a, ll d)
{
	if (d >= a[0])
	{
		a[2] = a[1];
		a[1] = a[0];
		a[0] = d;
		return;
	}
	else if (d >= a[1])
	{
		a[2] = a[1];
		a[1] = d;
		return;
	}
	else if (d >= a[2])
	{
		a[2] = d;
		return;
	}
}
inline void count_card(int &cnt_c1, int &cnt_c2, int &cnt_c3, ll *max_c1, ll max_c2, ll max_c3)
{
	cnt_c1 = 0;
	cnt_c2 = 0;
	cnt_c3 = 0;

	for (int i = 0; i < 3; i++)
		if (max_c1[i] != 0)
			cnt_c1++;
	if (max_c2 != 0)
		cnt_c2 = 1;
	if (max_c3 != 0)
		cnt_c3 = 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, c, d, k;
	ll max_c1[3];
	ll max_c2;
	ll max_c3;
	int cnt_c1, cnt_c2, cnt_c3;
	ll maxn;
	while (cin >> n)
	{
		dp.resize(n + 1);
		for (int i = 0; i <= n; i++)
			dp[i].resize(10, -1);
		dp[0][0] = 0;

		for (int i = 1; i <= n; i++)
		{

			// cerr << endl
			// 	 << endl
			// 	 << endl
			// 	 << "Round :" << i << '\n';
			cin >> k;
			init_max_cost(max_c1, max_c2, max_c3);
			for (int j = 0; j < k; j++)
			{
				cin >> c >> d;
				switch (c)
				{
				case 1:
					choose_max3_of_c1(max_c1, d);
					break;
				case 2:
					max_c2 = max(max_c2, d);
					break;
				case 3:
					max_c3 = max(max_c3, d);
					break;
				}
				//cerr << "max_cost : " << max_c1[0] << ' ' << max_c1[1] << ' ' << max_c1[2] << " || " << max_c2 << " || " << max_c3 << '\n';
			}
			count_card(cnt_c1, cnt_c2, cnt_c3, max_c1, max_c2, max_c3);
			//cerr << "count : " << cnt_c1 << " || " << cnt_c2 << " || " << cnt_c3 << '\n';

			for(int j=0;j<10;j++)
				dp[i][j]=dp[i-1][j];

			for (int j = 0; j < 10; j++)
			{
				
				if (dp[i - 1][j] != -1)
				{
					// if(i==3)
					// 	cerr<<"dp[i - 1][(j + 1) % 10]= "<<dp[i - 1][(j + 1) % 10]<<" dp[i - 1][j] + max_c1[0] * 2= "<<dp[i - 1][j] + max_c1[0] * 2<<" dp[i - 1][j] + max_c1[0]= "<<dp[i - 1][j] + max_c1[0]<<'\n';
					if (cnt_c1 >= 1)
					{
						dp[i][(j + 1) % 10] = max(dp[i][(j + 1) % 10], (j >= 9) ? max(dp[i - 1][(j + 1) % 10], dp[i - 1][j] + max_c1[0] * 2) : max(dp[i - 1][(j + 1) % 10], dp[i - 1][j] + max_c1[0]));
						// if (i == 3)
						// 	cerr << "dp[" << i << "][" << j + 1 << "]= " << dp[i][j + 1] << '\n';
					}
					if (cnt_c2 != 0)
						dp[i][(j + 1) % 10] = max(dp[i][(j + 1) % 10], (j >= 9) ? max(dp[i - 1][(j + 1) % 10], dp[i - 1][j] + max_c2 * 2) : max(dp[i - 1][(j + 1) % 10], dp[i - 1][j] + max_c2));
					if (cnt_c3 != 0)
						dp[i][(j + 1) % 10] = max(dp[i][(j + 1) % 10], (j >= 9) ? max(dp[i - 1][(j + 1) % 10], dp[i - 1][j] + max_c3 * 2) : max(dp[i - 1][(j + 1) % 10], dp[i - 1][j] + max_c3));

					// if (i == 3)
					// 	cerr << "dp[" << i << "][" << j << "]= " << dp[i][j] << '\n';

					if (cnt_c1 >= 2)
						dp[i][(j + 2) % 10] = max(dp[i][(j + 2) % 10], (j >= 8) ? max(dp[i - 1][(j + 2) % 10], dp[i - 1][j] + max_c1[0] * 2 + max_c1[1]) : max(dp[i - 1][(j + 2) % 10], dp[i - 1][j] + max_c1[0] + max_c1[1]));
					if (cnt_c1 >= 1 && cnt_c2 != 0)
						dp[i][(j + 2) % 10] = max(dp[i][(j + 2) % 10], (j >= 8) ? max3(dp[i - 1][(j + 2) % 10], dp[i - 1][j] + max_c1[0] * 2 + max_c2, dp[i - 1][j] + max_c1[0] + max_c2 * 2) : max(dp[i - 1][(j + 2) % 10], dp[i - 1][j] + max_c1[0] + max_c2));

					if (cnt_c1 >= 3)
						dp[i][(j + 3) % 10] = max(dp[i][(j + 3) % 10], (j >= 7) ? max(dp[i - 1][(j + 3) % 10], dp[i - 1][j] + max_c1[0] * 2 + max_c1[1] + max_c1[2]) : max(dp[i - 1][(j + 3) % 10], dp[i - 1][j] + max_c1[0] + max_c1[1] + max_c1[2]));

					
				}
			}

			// cerr << "dp: ";
			// for (int j = 0; j < 10; j++)
			// 	cerr << setw(5)<< dp[i][j] << ' ';
			// cerr << '\n';
		}
		maxn = 0;
		for (int j = 9; j >= 0; j--)
			maxn = max(dp[n][j], maxn);
		cout << maxn << '\n';
		dp.clear();
	}

	return 0;
}

/*
20
1
1 1
1 
1 2
1
1 3
1 
1 4
1
1 5
1
1 6
1
1 7
1
1 8
1
1 9
1
1 10
1
1 11
1
1 12
1
1 13
1
1 14
1
1 15
1
1 16
1
1 17
1
1 18
1
1 19
1
1 20
*/
