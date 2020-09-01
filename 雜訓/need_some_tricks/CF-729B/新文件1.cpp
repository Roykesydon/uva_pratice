#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll ans = 0;
    cin >> n >> m;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        arr[i].resize(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < m; j++)
            if (arr[i][j] == 1)
                flag = true;
            else if (flag == true)
                ans++;
    }
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = m - 1; j >= 0; j--)
            if (arr[i][j] == 1)
                flag = true;
            else if (flag == true)
                ans++;
    }
    for (int j = 0; j < m; j++)
    {
        bool flag = false;
        for (int i = 0; i < n; i++)
            if (arr[i][j] == 1)
                flag = true;
            else if (flag == true)
                ans++;
    }
    for (int j = 0; j < m; j++)
    {
        bool flag = false;
        for (int i = n - 1; i >= 0; i--)
            if (arr[i][j] == 1)
                flag = true;
            else if (flag == true)
                ans++;
    }
    cout << ans << '\n';
    return 0;
}
