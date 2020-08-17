#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
vector<ll> id;
map<ll, ll> mp;
vector<ll> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, x;
    while (cin >> n >> k)
    {
        mp.clear();
        id.clear();id.resize(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> id[i];
            mp[id[i]]++;
        }
        sort(id.begin(), id.end());
        id.resize(unique(id.begin(), id.end()) - id.begin());
        dp.clear();dp.resize(k + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < id.size(); i++){
            for (int j = k; j >= 1; j--)
                dp[j] += dp[j - 1] * mp[id[i]] % mod;
        }
        dp[k]%=mod;
        cout << dp[k] << '\n';
    }

    return 0;
}
