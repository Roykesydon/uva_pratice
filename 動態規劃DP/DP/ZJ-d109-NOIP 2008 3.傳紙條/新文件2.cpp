#include <bits/stdc++.h>
using namespace std;
int dp[100 + 1][50 + 1][50 + 1];//dp[k][n][n]
int arr[50 + 1][50 + 1];
int max4(int a, int b, int c, int d)
{
    a = max(a, b);
    c = max(c, d);
    a = max(a, c);
    return a;
}
int main()
{
    memset(dp, 0, sizeof(dp));
    memset(arr, 0, sizeof(arr));
    int m, n;
    while (cin >> m >> n)
    {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> arr[j][i];
        for (int k = 3; k <= n + m; k++)
        {
            for (int i = 1; i <= k - 1 && i <= n; i++)
                for (int j = 1; j <= k - 1 && j <= n; j++)
                {
                    int y1 = k - i;
                    int y2 = k - j;
                    if (i == j && k != m + n)
                        continue;
                    dp[k][i][j] = max4(dp[k - 1][i][j], dp[k - 1][i - 1][j], dp[k - 1][i][j - 1], dp[k - 1][i - 1][j - 1]) + arr[i][y1] + arr[j][y2];
                }
        }
        cout << dp[m + n][n][n] << '\n';

        // cout << endl;
        // for (int k = 0; k <= n + m ; k++)
        // {
        //     for (int i = 1; i <= m; i++)
        //     {
        //         for (int j = 1; j <= n; j++)
        //             cout << setw(3) << dp[k][i][j];
        //         cout << '\n';
        //     }
        //     cout << endl;
        // }
    }

    return 0;
}
