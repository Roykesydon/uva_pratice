#include <iostream>
#include <vector>
using namespace std;
#define ll long long
vector<int> item, backpack, tmp;
vector<int> c, dp;
int c1, c2, n;
bool check(int x)
{
    int sum = 0;
    tmp.clear();
    backpack.clear();
    for (int i = 0; i < n; i++)
        if ((1 << i) & x)
        {
            sum += item[i + 1];
            tmp.push_back(item[i + 1]);
        }
    //cerr << "x= " << x << " tmp.size()= " << tmp.size() << '\n';
    backpack.resize(c1 + 1, 0);
    for (int i = 0; i < tmp.size(); i++)
        for (int j = c1; j >= tmp[i]; j--)
            backpack[j] = max(backpack[j], backpack[j - tmp[i]] + tmp[i]);
    //cerr << "x= " << x << " backpack[c1]= " << backpack[c1] << '\n';
    if (sum - backpack[c1] <= c2)
    {
        //cerr << "x= " << x << " is ok\n";
        return true;
    }

    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> n >> c1 >> c2;
        item.clear();
        item.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> item[i];
        c.clear();
        c.resize(1 << n, 0);
        for (int i = 0; i < (1 << n); i++)
            if (check(i))
                c[i] = 1;
        dp.clear();
        dp.resize(1 << n, 1e9);
        dp[0] = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                if (c[j])
                    if ((i & j) == 0)
                        dp[i | j] = min(dp[i | j], dp[i] + 1);
            }
        }

        cout << "Scenario #" << cas << ":\n";
        cout << dp[(1 << n) - 1] << '\n';
        cout << '\n';
    }
    return 0;
}
/*
3
5 10 2
1 2 3 4 5
5 4 3 2 1
5 10 12
1 2 3 4 5
5 4 3 2 1
5 10 16
1 2 3 4 5
5 4 3 2 1
*/
