#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> arr1, arr2;
vector<int> dp;
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second >= 0 && b.second >= 0)
            return a.first < b.first;
        else
            return a.first + a.second > b.first + b.second;
    }
};
int main()
{
    int n, cur, a, b, ans = 0, maxn = 0;
    cin >> n >> cur;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (b >= 0)
            arr1.push_back({a, b});
        else
            arr2.push_back({a, b});
    }
    sort(arr1.begin(), arr1.end(), cmp());
    for (int i = 0; i < arr1.size(); i++)
        if (cur >= arr1[i].first)
        {
            cur += arr1[i].second;
            ans++;
        }
    sort(arr2.begin(), arr2.end(), cmp());
    dp.resize(cur + 1, 0);
    for (int i = 0; i < arr2.size(); i++)
    {
        for (int j = arr2[i].first; j <= cur; j++)
        {
            if (j + arr2[i].second >= 0)
            {
                dp[j + arr2[i].second] = max(dp[j + arr2[i].second], dp[j] + 1);
            }
        }
    }
    for (int i = 0; i < dp.size(); i++)
        maxn = max(maxn, dp[i]);

    cout << ans + maxn << '\n';
    return 0;
}
