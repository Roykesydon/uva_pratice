#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> arr;
vector<ll> dp;
ll n;
// string show(int index)
// {
//     string str = "";
//     for (int i = 0; i < n; i++)
//     {
//         str = (char)((index & 1) + '0') + str;
//         index >>= 1;
//     }
//     return str;
// }
ll dfs(ll index)
{
    //cerr << "dfsing : " << show(index) << endl;
    if (dp[index] != -1)
        return dp[index];
    ll cnt = 0, tmpp, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        if ((1 << i) & index)
        {
            tmpp = i + 1;
            cnt++;
        }
    }
    if (cnt == 1)
    {
        if (arr[0][tmpp] == 1)
            return dp[index] = 1;
        return dp[index] = 0;
    }
    for (ll i = 0; i < n; i++)
    {
        if ((1 << i) & index)
        {
            bool flag = false;
            for (ll j = 0; j < n; j++)
            {
                if ((1 << j) & index && j != i)
                {
                    if (arr[j + 1][i + 1] == 1)
                    {
                        flag = true;
                        break;
                    }
                }
            }
            if (arr[0][i + 1])
                flag = true;
            if (flag)
                sum += dfs(index - (1 << i));
        }
    }
    return dp[index] = sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    char ch;
    cin >> t;
    for (ll cas = 1; cas <= t; cas++)
    {
        cin >> n;
        arr.clear();
        arr.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            arr[i].resize(n + 1);
        for (ll i = 0; i <= n; i++)
            for (ll j = 1; j <= n; j++)
            {
                cin >> ch;
                arr[i][j] = ch - '0';
            }
        dp.clear();
        dp.resize(1 << n, -1);
        cout << "Case " << cas << ": " << dfs((1 << n) - 1) << '\n';
    }

    return 0;
}
/*
1
5
10101
10011
10011
00111
11100
11101



1
4
1101
1111
0010
1101
1111
*/
