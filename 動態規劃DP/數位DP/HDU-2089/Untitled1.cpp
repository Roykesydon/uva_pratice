#include <iostream>
#include <string>
#include <cstring>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
#define ll long long
int arr[10];
int dp[10][2][2];
int n;
int dfs(int pos, bool pre_six, bool limit)
{
    if (pos == 0)
        return 1;
    if (dp[pos][pre_six][limit] != -1)
        return dp[pos][pre_six][limit];
    int v = ((limit) ? arr[n - pos] : 9);
    int ans = 0;
    for (int i = 0; i <= v; i++)
        if (!(i == 2 && pre_six) && i != 4)
            ans += dfs(pos - 1, i == 6, limit && i == v);
    return dp[pos][pre_six][limit] = ans;
}
int solve(string x)
{
    n = x.size();
    for (int i = 0; i < n; i++)
        arr[i] = x[i] - '0';
    memset(dp, -1, sizeof(dp));
    return dfs(n, 0, 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string l, r;
    while (cin >> l >> r)
    {
        if (l == "0" && r == "0")
            break;
        int n = l.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (l[i] > '0')
            {
                l[i]--;
                break;
            }
            l[i] = '9';
        }
        cout << solve(r) - solve(l) << '\n';
    }

    return 0;
}
