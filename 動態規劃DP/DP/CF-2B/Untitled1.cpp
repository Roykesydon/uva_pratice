#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MXN 1005
ll arr[MXN][MXN], dp[MXN][MXN], dir[MXN][MXN];
vector<char> ans;
ll check2(ll x)
{
    ll tmp = 0;
    while (x % 2 == 0 && x)
    {
        tmp++;
        x >>= 1;
        if (x == 0)
            break;
    }
    return tmp;
}
ll check5(ll x)
{
    ll tmp = 0;
    while (x % 5 == 0 && x)
    {
        tmp++;
        x /= 5;
        if (x == 0)
            break;
    }
    return tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    bool flag = 0;
    ll wowx, wowy;
    cin >> n;
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
            {
                flag = 1;
                wowx = i;
                wowy = j;
            }
        }

    dir[0][0] = -1;
    memset(dp, 0x3f, sizeof(dp));

    dp[0][0] = check2(arr[0][0]);
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            if (!i && !j)
                continue;
            if (!arr[i][j])
            {
                dp[i][j] = 1;
                dir[i][j]=0;
                continue;
            }
            ll tmp = check2(arr[i][j]);
            if (i)
            {
                if (dp[i][j] > dp[i - 1][j] + tmp)
                {
                    dp[i][j] = dp[i - 1][j] + tmp;
                    dir[i][j] = 0; //down
                }
            }
            if (j)
            {
                if (dp[i][j] > dp[i][j - 1] + tmp)
                {
                    dp[i][j] = dp[i][j - 1] + tmp;
                    dir[i][j] = 1; //right
                }
            }
        }

    ll x = n - 1, y = n - 1;
    ll tmp = dir[x][y];
    ll tmp_ans = dp[x][y];
    while (tmp != -1)
    {
        if (tmp == 1)
        {
            ans.push_back('R');
            y--;
        }
        else
        {
            ans.push_back('D');
            x--;
        }
        tmp = dir[x][y];
    }

    //--------------------
    dir[0][0] = -1;
    memset(dp, 0x3f, sizeof(dp));

    dp[0][0] = check5(arr[0][0]);
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
        {
            if (!i && !j)
                continue;

            if (!arr[i][j])
            {
                dp[i][j] = 1;
                dir[i][j]=0;
                continue;
            }
            ll tmp = check5(arr[i][j]);
            if (i)
            {
                if (dp[i][j] > dp[i - 1][j] + tmp)
                {
                    dp[i][j] = dp[i - 1][j] + tmp;
                    dir[i][j] = 0; //down
                }
            }
            if (j)
            {
                if (dp[i][j] > dp[i][j - 1] + tmp)
                {
                    dp[i][j] = dp[i][j - 1] + tmp;
                    dir[i][j] = 1; //right
                }
            }
        }

    x = n - 1, y = n - 1;
    tmp = dir[x][y];
    if (tmp_ans > dp[x][y])
    {
        ans.clear();
        tmp_ans = dp[x][y];
        while (tmp != -1)
        {
            if (tmp == 1)
            {
                ans.push_back('R');
                y--;
            }
            else
            {
                ans.push_back('D');
                x--;
            }
            tmp = dir[x][y];
        }
    }

    if (flag && tmp_ans >= 1)
    {
        cout << "1\n";
        for (ll i = 0; i < wowx; i++)
            cout << "D";
        for (ll i = 0; i < n - 1; i++)
        {
            cout << "R";
        }
        for (ll i = 0; i < n - wowx - 1; i++)
            cout << "D";
        cout << '\n';
        return 0;
    }

    cout << tmp_ans << '\n';
    for (ll i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
    cout << '\n';
    return 0;
}
