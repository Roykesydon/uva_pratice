#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<list<int>::iterator> addr;
list<int> lis;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, q, x, y;
    char ch;
    cin >> n >> m >> q;
    addr.resize(n);
    for (int i = 0; i < n; i++)
    {
        lis.push_back(i);
        addr[i] = prev(lis.end());
    }
    for (int i = 0; i < m; i++)
    {
        cin >> ch >> x >> y;
        if(x==y)continue;
        if (ch == 'R')
        {
            if (addr[y] == lis.begin())
            {
                lis.erase(addr[x]);
                lis.insert(lis.begin(), x);
                addr[x] = lis.begin();
            }
            else
            {
                lis.erase(addr[x]);
                lis.insert(addr[y], x);
                addr[x] = prev(addr[y]);
            }
        }
        else
        {
            if (next(addr[y]) == lis.end())
            {
                lis.erase(addr[x]);
                lis.insert(lis.begin(), x);
                addr[x] = lis.begin();
            }
            else
            {
                lis.erase(addr[x]);
                lis.insert(next(addr[y]), x);
                addr[x] = next(addr[y]);
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        if (addr[x] == lis.begin())
            cout << *prev(lis.end());
        else
            cout << *prev(addr[x]);
        cout << ' ';
        if (next(addr[x]) == lis.end())
            cout << *lis.begin();
        else
            cout << *next(addr[x]);
        if (i != q - 1)
            cout << ' ';
    }
    cout << '\n';

    return 0;
}
