#include <bits/stdc++.h>
using namespace std;
#define ll long long
class block
{
public:
    vector<ll> local;
    ll value;
};
vector<ll> arr;
vector<block> blk;
int main()
{
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    int sz = sqrt(n);
    int len = n / sz + 1;
    int opt, l, r;
    ll c;
    arr.resize(n);
    blk.resize(len);
    for (int i = 0; i < len; i++)
    {
        blk[i].value = 0;
    }
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        blk[i / sz].local.push_back(arr[i]);
    for (int i = 0; i < n; i++)
    {
        cin >> opt >> l >> r >> c;
        l--;
        r--;
        if (opt) //query r
        {
            cout << blk[r / sz].local[r % sz] + blk[r / sz].value << '\n';
        }
        else //[l,r]+c
        {
            if (l / sz == r / sz)
                for (int i = l; i <= r; i++)
                    blk[i / sz].local[i % sz] += c;
            else
            {
                for (int i = l % sz; i < sz; i++)
                    blk[l / sz].local[i] += c;
                for (int i = 0; i <= r % sz; i++)
                    blk[r / sz].local[i] += c;
                for (int i = l + sz; i / sz < r / sz; i += sz)
                    blk[i / sz].value += c;
            }
        }
    }

    arr.clear();
    blk.clear();

    return 0;
}
