#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> vec;
vector<ll> dp;
set<pair<ll, ll>> myset;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k, mind, tmp;
    while (cin >> n >> k)
    {
        assert(n >= k);
        vec.resize(n);
        dp.resize(n);
        for (ll i = 0; i < n; i++)
            cin >> vec[i];
        tmp = 0;
        for (ll i = 0; i < n; i++)
        {
            if (i < k)
            {

                dp[i] = vec[i] + tmp;
                if (vec[i] < 0)
                    tmp += vec[i];
                myset.insert({dp[i], i});
            }

            else
            {
                // mind = 1e18;
                // for (ll j = i - k; j < i; j++)
                //     mind = min(mind, dp[j]);
                mind = myset.begin()->first;
                dp[i] = vec[i] + mind;
                myset.erase(myset.find({dp[i - k], i - k}));
                myset.insert({dp[i], i});
            }
        }
        mind = 1e18;
        for (ll i = n - k; i < n; i++)
            mind = min(mind, dp[i]);
        cout << mind << '\n';
        vec.clear();
        myset.clear();
        dp.clear();
    }
}
