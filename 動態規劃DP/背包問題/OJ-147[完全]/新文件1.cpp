#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6
#define ll long long
ll arr[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
vector<ll> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double dn;
    ll n;
    while (cin >> dn && abs(dn - 0.0) > eps)
    {
        n = (ll)(dn * 1000.0);
		if(n%10==9)n++;
		n/=10;
        //cout << "n= " << n << '\n';
        dp.clear();
        dp.resize(n + 1, 0);
        dp[0] = 1;
        for (ll i = 0; i <= 10; i++)
        {
            for (ll j = arr[i]; j <= n; j++)
                dp[j] += dp[j - arr[i]];
            // cout << "i= " << i << '\n';
            // for (ll j = 0; j <= n; j++)
            //     cout << "dp[" << j << "]= " << dp[j] << '\n';
        }

        cout << setw(6) << fixed << setprecision(2) << dn << setw(17) << dp[n] << '\n';
    }
    return 0;
}
