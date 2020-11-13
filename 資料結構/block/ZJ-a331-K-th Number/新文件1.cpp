#include <bits/stdc++.h>
using namespace std;
int l, r;
int ql, qr;
int sz;
int len;
class block
{
public:
    vector<int> local;
    vector<int> global;
};
vector<block> blk;
vector<int> arr;
int f(int x)
{
    if (ql / sz == qr / sz)
    {
        int cnt = 0;
        for (int i = ql % sz; i <= qr % sz; i++)
            if (blk[ql / sz].local[i] < x)
                cnt++;
        return cnt;
    }
    else
    {
        int cnt = 0;
        for (int i = ql % sz; i < sz; i++)
            if (blk[ql / sz].local[i] < x)
                cnt++;
        for (int i = 0; i <= qr % sz; i++)
            if (blk[qr / sz].local[i] < x)
                cnt++;
        for (int i = ql / sz + 1; i < qr / sz; i++)
        {
            cnt += lower_bound(blk[i].global.begin(), blk[i].global.end(), x) - blk[i].global.begin();
        }
        return cnt;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int k;
    int cnt;
    int mid;
    int maxn, minn;

    while (cin >> n >> m)
    {
        sz = sqrt(n);
        len = n / sz + 1;
        blk.resize(len);
        arr.resize(n);
        maxn = -1e9 - 1;
        minn = 1e9 + 1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxn = max(maxn, arr[i]);
            minn = min(arr[i], minn);
            blk[i / sz].local.push_back(arr[i]);
            blk[i / sz].global.push_back(arr[i]);
        }
        //cerr << "safe1\n";
        for (int i = 0; i < len; i++)
        {
            sort(blk[i].global.begin(), blk[i].global.end());
        }
        for (int i = 0; i < m; i++)
        {
            cin >> ql >> qr >> k;
            ql--;
            qr--;
            l = minn;
            r = maxn;
            while (l < r)
            {
                mid = (l + r + 1) / 2;
                if (l == r)
                    break;
                // cerr << " l= " << l << " r= " << r;
                // cerr << " mid= " << mid << '\n';
                cnt = f(mid);
                if (cnt <= k - 1) //有可能對
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << l << '\n';
        }
        blk.clear();
        arr.clear();
    }

    return 0;
}
