#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, maxn, maxp;
    while (cin >> n && n)
    {
        arr.clear();
        arr.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        cin >> m;
        if (m < 5)
        {
            cout << m << '\n';
            continue;
        }
        maxn = 0;
        for (int i = 1; i <= n; i++)
            if (arr[i] > maxn)
            {
                maxn = arr[i];
                maxp = i;
            }
        m -= 5;
        arr[maxp] = 0;
        dp.clear();
        dp.resize(m + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = m; j >= arr[i]; j--)
                dp[j] = max(dp[j], dp[j - arr[i]]);
        // for (int i = 0; i <= m; i++)
        // {
        //     cout << "i= " << i << " dp[i]= " << dp[i] << '\n';
        // }
        for (int i = m; i >= 0; i--)
            if (dp[i])
            {
                //cout << " m+5= " << m + 5 << " -maxn=" << -maxn << " -i= " << -i << '\n';
                cout << m + 5 - maxn - i << '\n';
                break;
            }
    }
    return 0;
}
/*
4
7 6 8 4
10
0
*///
