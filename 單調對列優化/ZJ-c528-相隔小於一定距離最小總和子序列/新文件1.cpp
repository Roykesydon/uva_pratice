#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> vec;
vector<ll> dp;
deque<pair<ll, ll>> deq;
//set<pair<ll, ll>> myset;
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
                //myset.insert({dp[i], i});
                // while (!deq.empty() && deq.front().second < i - k)
                //     deq.pop_front();
                while (!deq.empty() && deq.back().first >= dp[i])
                    deq.pop_back();
                deq.push_back({dp[i], i});
                //單調對列優化
            }

            else
            {
                dp[i] = vec[i] + deq.front().first;
                // mind = 1e18;
                // for (ll j = i - k; j < i; j++)
                //     mind = min(mind, dp[j]);
                //mind = myset.begin()->first;
                while (!deq.empty() && deq.front().second <= i - k)
                    deq.pop_front();
                while (!deq.empty() && deq.back().first >= dp[i])
                    deq.pop_back();
                deq.push_back({dp[i], i});

                //myset.erase(myset.find({dp[i - k], i - k}));
                //myset.insert({dp[i], i});
            }
        }
        mind = 1e18;

        // for (int i = 0; i > n; i++)
        //     cout << dp[i] << ' ';
        // cout << endl;

        for (ll i = n - k; i < n; i++)
            mind = min(mind, dp[i]);
        cout << mind << '\n';
        vec.clear();
        deq.clear();
        //myset.clear();
        dp.clear();
    }
}
