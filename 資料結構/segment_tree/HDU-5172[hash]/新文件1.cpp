#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pl(x) (x * 2 + 1)
#define pr(x) (x * 2 + 2)
ll tmp;
vector<int> arr;
vector<ll> v_hash;
vector<ll> sum;
vector<ll> seg;
mt19937 gen(0x5EED);
int randint(int lb, int ub)
{
    return uniform_int_distribution<int>(lb, ub)(gen);
}
void build(int index, int l, int r)
{
    if (l == r)
    {
        seg[index] = v_hash[arr[l]];
        return;
    }
    int mid = (l + r) / 2;
    build(pl(index), l, mid);
    build(pr(index), mid + 1, r);
    seg[index] = seg[pl(index)] * seg[pr(index)];
    seg[index] %= mod;
}
void query(int index,int ql,int qr,int l,int r){
    if(l>=ql&&r<=qr){
        tmp*=seg[index];
        tmp%=mod;
        return ;
    }
    int mid=(l+r)/2;
    if(ql<=mid)
        query(pl(index),ql,qr,l,mid);
    if(qr>mid)
        query(pr(index),ql,qr,mid+1,r);
}
int main()
{
    int n, m, l, r;
    ios::sync_with_stdio(0);
    cin.tie(0);
    v_hash.resize(1000000 + 1);
    sum.resize(1000000 + 1);
    for (int i = 1; i <= 1000000; i++)
        v_hash[i] = randint(2, mod - 1);
    sum[1] = v_hash[1];
    for (int i = 2; i <= 1000000; i++)
    {
        sum[i] = v_hash[i] * sum[i - 1];
        sum[i] %= mod;
    }
    while (cin >> n >> m)
    {
        arr.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        seg.clear();
        seg.resize(n << 2);
        build(0, 0, n - 1);
        for (int i = 0; i < m; i++)
        {
            cin >> l >> r;
            tmp = 1;
            query(0, l-1, r-1,0,n-1);
            if(tmp==sum[r-l+1])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }

    return 0;
}
