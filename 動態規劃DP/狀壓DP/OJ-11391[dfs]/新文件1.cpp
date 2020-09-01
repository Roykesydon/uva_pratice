#include <bits/stdc++.h>
#define ll long long
using namespace std;
int r, c, n;
pair<int, int> dir[8] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<int> dp;
inline int calc(int x, int y)
{
    return x * c + y;
}
bool safe0(int x, int y)
{
    if (x >= 0 && x <= r - 1 && y >= 0 && y <= c - 1)
        return true;
    return false;
}
int dfs(int state)
{
    int x, y;
    if (dp[state] != -1)
        return dp[state];
    int sum = 0;
    for (int i = 0; i < r * c; i++)
    {
        if (state & (1 << i))
        {
            x = i / c;
            y = i % c;
            for (int j = 0; j < 8; j++)
            {
                if (safe0(x + dir[j].first * 2, y + dir[j].second * 2) && safe0(x + dir[j].first, y + dir[j].second) && state & (1 << calc(x + dir[j].first, y + dir[j].second)) && !(state & (1 << calc(x + dir[j].first * 2, y + dir[j].second * 2))))
                    sum+=dfs(state-(1<<i)-(1 << calc(x + dir[j].first, y + dir[j].second))+(1 << calc(x + dir[j].first * 2, y + dir[j].second * 2)));
            }
        }
    }
    return dp[state]=sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, x, y, state = 0;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> r >> c >> n;
        dp.clear();
        dp.resize(1 << (r * c), -1);
        state = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            state |= (1 << ((x - 1) * c + y - 1));
        }
        for (int i = 0; i < r * c; i++)
            dp[1 << i] = 1;
        cout << "Case " << cas << ": " << dfs(state) << '\n';
    }
    return 0;
}
/*
1
3 3 3
3 1
2 2
1 2

*/
