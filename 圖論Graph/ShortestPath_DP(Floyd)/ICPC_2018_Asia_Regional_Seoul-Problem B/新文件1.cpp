#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
vector<vector<int>> d_cnt;
vector<vector<int>> dp;
vector<int> ans;
int main()
{
    int n, m;
    cin >> m >> n;
    arr.resize(n);
    d_cnt.resize(m);
    dp.resize(m);

    for (int i = 0; i < m; i++)
    {
        d_cnt[i].resize(m, 0);
        dp[i].resize(m, -1e9);
    }

    for (int i = 0; i < n; i++)
        arr[i].resize(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
            {
                if (j == k)
                    continue;
                if (arr[i][k] == 0)
                {
                    if (arr[i][j] != 0)
                        d_cnt[j][k]++;
                }
                else
                {
                    if (arr[i][j] == 0)
                        continue;
                    if (arr[i][j] < arr[i][k])
                        d_cnt[j][k]++;
                }
            }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                continue;
            if (d_cnt[i][j] > d_cnt[j][i])
                dp[i][j] = d_cnt[i][j];
        }
    }

    for (int k = 0; k < m; k++)
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = max(dp[i][j], min(dp[i][k], dp[k][j]));

    for (int i = 0; i < m; i++)
    {
        bool flag = 1;
        for (int j = 0; j < m; j++)
        {
            if (!(dp[i][j] >= dp[j][i]))
                flag = 0;
        }
        if (flag)
        {
            ans.push_back(i + 1);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    cout << '\n';
    return 0;
}
