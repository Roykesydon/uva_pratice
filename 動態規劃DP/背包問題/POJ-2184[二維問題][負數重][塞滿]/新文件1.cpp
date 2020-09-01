#include <iostream>
#include <vector>
using namespace std;
#define eps 1e-6
vector<int> dp;
vector<pair<int, int> > arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, maxn;
    cin >> n;
    arr.resize(n + 1);
    dp.resize(2 * 100000 + 5, -1e9);
    dp[100000] = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].first >> arr[i].second;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i].first >= 0)
        {
            for (int j = 200000 + 4; j >= 0; j--)
                if (j - arr[i].first >= 0 && j - arr[i].first < 200000 + 5 && dp[j - arr[i].first] != -1e9)
                    dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
        }
        else
        {
            for (int j = 0; j <= 200000 + 4; j++)
                if (j - arr[i].first >= 0 && j - arr[i].first < 200000 + 5 && dp[j - arr[i].first] != -1e9)
                    dp[j] = max(dp[j], dp[j - arr[i].first] + arr[i].second);
        }

        // for (int i = 100000; i < dp.size(); i++)
        //     if (dp[i] != -1e9)
        //         cout << "i= " << i << " dp[i]= " << dp[i] << '\n';
        // cout << endl;
    }

    maxn = 0;
    for (int i = 100000; i <= 200000 + 4; i++)
        if (dp[i] >= 0 && i + dp[i] - 100000 > maxn)
            maxn = i + dp[i] - 100000;
    cout << maxn << '\n';

    return 0;
}
