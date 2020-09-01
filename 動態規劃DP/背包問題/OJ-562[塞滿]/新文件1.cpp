#include <bits/stdc++.h>
using namespace std;
vector<int> arr, dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, sum, v;
    cin >> t;
    while (t--)
    {
        cin >> n;
        arr.clear();
        arr.resize(n);
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        v = ((sum & 1) ? sum / 2 + 1 : sum / 2);
        dp.clear();
        dp.resize(v + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = v; j >= arr[i]; j--)
                dp[j] = max(dp[j], dp[j - arr[i]]);
        for (int i = v; i >= 0; i--)
        {
            if (dp[i])
            {
                cout << abs(i - (sum - i)) << '\n';
                break;
            }
        }
    }
    return 0;
}
