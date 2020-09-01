#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> check;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int q, len, x, y;
    cin >> str;
    len = str.size();
    check.resize(len);
    dp.resize(len);
    for (int i = 0; i < len; i++)
        dp[i].resize(len, 0);
    for (int i = 0; i < len; i++)
        check[i].resize(len, 0);
    for (int i = 0; i < len; i++)
        check[i][i] = true;
    for (int l = 1; l < len; l++)
        for (int i = 0, j = i + l; i < len - l; i++, j++)
            if (l == 1)
                check[i][j] = (str[i] == str[j]);
            else
                check[i][j] = (check[i + 1][j - 1] && (str[i] == str[j]));
    for (int i = 0; i < len; i++)
        dp[i][i] = 1;
    for (int l = 1; l < len; l++)
        for (int i = 0, j = i + l; i < len - l; i++, j++)
            if (l == 1)
                dp[i][j] = 2 + (str[i] == str[j]);
            else
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + check[i][j]);
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        cout << dp[x - 1][y - 1] << '\n';
    }
    return 0;
}
