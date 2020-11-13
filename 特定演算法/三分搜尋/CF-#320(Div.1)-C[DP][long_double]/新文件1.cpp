#include <bits/stdc++.h>
using namespace std;
#define eps 1e-15
#define double long double
vector<double> arr;
double check(double x)
{
    vector<double> dp;
    vector<double> test;
    dp.resize(arr.size());
    test.resize(arr.size());
    double ans = 0, tmp = 0;
    for (int i = 0; i < arr.size(); i++)
        test[i] = (double)arr[i] - x;

    ans = dp[0] = test[0];
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = max(dp[i - 1] + test[i], test[i]);
        ans = max(ans, dp[i]);
    }
    tmp = dp[0] = test[0];
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = min(dp[i - 1] + test[i], test[i]);
        tmp = min(tmp, dp[i]);
    }

    return max(abs(tmp), ans);
}
int main()
{
    double x, l, r, ml, mr;
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    l = -10000.0;
    r = 10000.0;
    while (r - l > eps)
    {
        ml = (r - l) / 3.0 + l;
        mr = (r - l) * 2.0 / 3.0 + l;
        if (check(ml) > check(mr))
        {
            l = ml;
        }
        else
        {
            r = mr;
        }
    }
    cout << fixed << setprecision(9) << check(r) << '\n';

    return 0;
}
