#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> parent;
vector<ll> sum;
vector<ll> num;
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void merge(int p, int pq)
{
    parent[p] = pq;
}
int main()
{
    int n, m, x, p, q, pp, pq;
    while (cin >> n >> m)
    {
        parent.resize(2 * n);
        sum.resize(2 * n);
        num.resize(2 * n);
        for (long long i = 0; i < n; i++)
        {
            parent[i] = parent[i + n] = i + n;
            sum[i] = sum[i + n] = i + 1;
            num[i] = num[i + n] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> x;
            switch (x)
            {
            case 1:
                cin >> p >> q;
                pp = find(p - 1);
                pq = find(q - 1);
                if (pp == pq)
                    continue;
                merge(pp, pq);
                sum[pq] += sum[pp];
                num[pq] += num[pp];
                break;
            case 2:
                cin >> p >> q;
                pp = find(p - 1);
                pq = find(q - 1);
                if (pp == pq)
                    continue;
                num[pp]--;
                sum[pp] -= p;
                merge(p - 1, pq);
                sum[pq] += p;
                num[pq]++;
                break;
            case 3:
                cin >> p;
                pp = find(p - 1);
                cout << num[pp] << ' ' << sum[pp] << '\n';
                break;
            }
        }
        parent.clear();
        sum.clear();
        num.clear();
    }

    return 0;
}
