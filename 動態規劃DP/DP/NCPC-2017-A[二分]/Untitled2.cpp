#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define eps 1e-6
vector<ld> dp;
vector<ll> nxt, ans;
vector<ll> shop;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    ll n;
    ld a, b, t, r, l;
    cin >> l >> a >> b >> t >> r;
    cin >> n;
    shop.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> shop[i];
    sort(shop.begin(), shop.end());
    dp.resize(n + 1, 1e18);
    nxt.resize(n, -1);
    dp[n] = (ld)l / (ld)a;
    for (ll i = n - 1; i >= 0; i--)
    {
        //shop[i]------tmp_a--running---tmp_b-----------tmp_c-------end
        ll tmp_a = shop[i] + a * t, tmp_b = shop[i] + a * t + b * r;


        if (l < tmp_a || abs(tmp_a-l)<=eps)             //end in the period one
            dp[i] = min(dp[i], (l - shop[i]) / a);
        else if (l < tmp_b || abs(l - tmp_b)<=eps )     //end in the period two
            dp[i] = min(dp[i], (l - shop[i] - a * t) / b + t);
        else
            dp[i] = min(dp[i], (l - shop[i] - a * t - r * b) / a + t + r);  //end in the period three


        auto u = upper_bound(shop.begin(), shop.end(), shop[i]);
        if (u != shop.end())
        {
            ll j = u - shop.begin();
            if (shop[j] <= tmp_a && dp[i] > dp[j] + (shop[j] - shop[i]) / a)
            {
                dp[i] = dp[j] + (shop[j] - shop[i]) / a;
                nxt[i] = j;
            }
        }

        u = lower_bound(shop.begin(), shop.end(), tmp_b);
        ll j;
        if (u != shop.end())
        {
            j = u - shop.begin();
            if (dp[i] > dp[j] + (shop[j] - (tmp_b)) / a + t + r)
            {
                dp[i] = dp[j] + (shop[j] - (tmp_b)) / a + t + r;
                nxt[i] = j;
            }
        }
        

        if (u != shop.begin())
        {
            u--;
            j = u - shop.begin();
            if (j > i && shop[j] >= tmp_a && shop[j] <= tmp_b && dp[i] > dp[j] + (shop[j] - (tmp_a)) / b + t)
            {
                dp[i] = dp[j] + (shop[j] - (tmp_a)) /b + t;
                nxt[i] = j;
            }
        }

    }


    ans.push_back(-1);
    long double minn = l / a;
    for (ll i = 0; i < n; i++)
    {
        if (shop[i] / a + dp[i] < minn||abs(shop[i] / a + dp[i] - minn)<=eps)
        {
            minn = shop[i] / a + dp[i];
            ans.clear();
            ans.push_back(i);
            ll tmp = nxt[i];
            while (tmp != -1)
            {
                ans.push_back(tmp);
                tmp = nxt[tmp];
            }
        }
    }
    if (ans[0] == -1)
    {
        cout << "0\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for (ll i = 0; i < ans.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
