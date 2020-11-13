#include <bits/stdc++.h>
#define pl(x) (x * 2 + 1)
#define pr(x) (x * 2 + 2)
using namespace std;
vector<int> arr;
vector<int> tree_high;
vector<int>tree_low;
void build_high(int index, int l, int r)
{
    if (l == r)
    {
        tree_high[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build_high(pl(index), l, mid);
    build_high(pr(index), mid + 1, r);
    tree_high[index] = max(tree_high[pl(index)], tree_high[pr(index)]);
}
void build_low(int index, int l, int r)
{
    if (l == r)
    {
        tree_low[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build_low(pl(index), l, mid);
    build_low(pr(index), mid + 1, r);
    tree_low[index] = min(tree_low[pl(index)], tree_low[pr(index)]);
}
void query_high(int index, int ql, int qr, int l, int r, int &high)
{
    if (l >= ql && r <= qr)
    {
        high = max(high, tree_high[index]);
        return;
    }
    int mid = (l + r) / 2;
    if (ql <= mid)
        query_high(pl(index), ql, qr, l, mid, high);
    if (qr > mid)
        query_high(pr(index), ql, qr, mid + 1, r, high);
}
void query_low(int index, int ql, int qr, int l, int r, int &low)
{
    if (l >= ql && r <= qr)
    {
        low = min(low, tree_low[index]);
        return;
    }
    int mid = (l + r) / 2;
    if (ql <= mid)
        query_low(pl(index), ql, qr, l, mid, low);
    if (qr > mid)
        query_low(pr(index), ql, qr, mid + 1, r, low);
}
int main()
{
    int n, q;
    int a, b;
    int high, low;
    while (cin >> n >> q)
    {
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        tree_high.resize(4 * n);
        tree_low.resize(4*n);
        build_high(0, 0, n - 1);
        build_low(0,0,n-1);
        for (int i = 0; i < q; i++)
        {
            cin >> a >> b;
            high = 0;
            low = 1e9;
            query_high(0, a - 1, b - 1, 0, n - 1, high);
            query_low(0, a - 1, b - 1, 0, n - 1, low);
            cout<<high-low<<endl;
        }

        tree_high.clear();
        tree_low.clear();
        arr.clear();
    }

    return 0;
}
