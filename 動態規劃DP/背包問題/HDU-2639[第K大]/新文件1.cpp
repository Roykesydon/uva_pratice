#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> dp;
vector<ll> arr;
vector<pair<ll, ll>> item;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, v, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> v >> k;
        dp.clear();
        dp.resize(v + 1);
        for (int i = 0; i <= v; i++)
            dp[i].resize(k, 0);
        item.clear();
        item.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> item[i].first;
        for (int i = 1; i <= n; i++)
            cin >> item[i].second;
        for (int i = 1; i <= n; i++)
        {
            for (int j = v; j >= item[i].second; j--)
            {
                arr.clear();
                for (int g = 0; g < k; g++)
                {
                    arr.push_back(dp[j][g]);
                    arr.push_back(dp[j - item[i].second][g] + item[i].first);
                }
                sort(arr.rbegin(), arr.rend());
                arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
                for (int g = 0, p1 = 0, p2 = 0; g < k && g < arr.size(); g++)
                {
                    dp[j][g] = arr[g];
                }
            }
            // cout << "i= " << i << '\n';
            // // for (int j = 0; j <= v; j++)
            // // {
            // //     for (int g = 0; g < k; g++)
            // //     {
            // //         cout << " dp[" << j << "][" << g << "]= " << dp[j][g] << ' ';
            // //     }
            // //     cout << endl;
            // // }
        }
        cout << dp[v][k - 1] << '\n';
    }
    return 0;
}
/*
3
5 10 2
1 2 3 4 5
5 4 3 2 1
5 10 12
1 2 3 4 5
5 4 3 2 1
5 10 16
1 2 3 4 5
5 4 3 2 1
*/
