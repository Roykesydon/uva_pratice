#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6
vector<long double> dp;
vector<pair<int, long double>> arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, x, sum;
    long double p, dx;
    cin >> t;
    while (t--)
    {
        cin >> p >> n;
        arr.clear();
        arr.resize(n);
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> dx;
            arr[i] = {x, dx};
            sum += x;
        }
        dp.clear();
        dp.resize(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = sum; j >= arr[i].first; j--)
                dp[j] = max(dp[j], dp[j - arr[i].first] * (1 - arr[i].second));
        for (int i = sum; i >= 0; i--)
        {
            if ((1.0 - dp[i]) < p || abs(1.0 - dp[i] - p) <= eps)
            {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
