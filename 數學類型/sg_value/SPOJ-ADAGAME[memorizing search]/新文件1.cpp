#include <bits/stdc++.h>
using namespace std;
int n, m;
int addn[4] = {1, 10, 100, 1000};
int dp[10000][100 + 1];
int dfs(int x, int tur)
{
    if (dp[x][tur] != -1)
        return dp[x][tur];
    if (tur >= m)
    {
        return dp[x][tur] = x;
    }
    int maxn = 0, minn = 10000;
    for (int i = 0; i < 4; i++)
    {
        int tmp = (x % (addn[i] * 10)) / addn[i];
        if (!(tur & 1))
        {
            if (tmp == 9)
                maxn = max(maxn, dfs(x-addn[i]*9, tur + 1));
            else
                maxn = max(maxn, dfs(x+addn[i], tur + 1));
        }
        else
        {
            if (tmp == 9)
                minn = min(minn, dfs(x-addn[i]*9, tur + 1));
            else
                minn = min(minn, dfs(x+addn[i], tur + 1));
        }
    }
    if (!(tur & 1))
        return dp[x][tur] = maxn;
    else
        return dp[x][tur] = minn;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(dp, -1, sizeof(dp));
        cout << ((dfs(n, 0) > n) ? "Ada\n" : "Vinit\n");
    }
    return 0;
}
