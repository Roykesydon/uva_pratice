#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> item;
bitset<4001> dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, maxn, cnt;
    cin >> t;
    while (t--)
    {
        item.clear();
        arr.clear();
        dp = 1;

        cin >> n;
        arr.resize(2 * n);
        for (int i = 0; i < 2 * n; i++)
            cin >> arr[i];
        maxn = 0, cnt = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (arr[i] > maxn)
            {
                if (maxn != 0)
                    item.push_back(cnt);
                cnt = 0;
                maxn = arr[i];
            }
            cnt++;
        }
        item.push_back(cnt);
        for (int i = 0; i < item.size(); i++)
            dp |= dp << item[i];
        if (dp[n] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
