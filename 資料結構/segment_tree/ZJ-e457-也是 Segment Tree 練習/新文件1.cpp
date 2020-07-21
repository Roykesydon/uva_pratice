#include <bits/stdc++.h>
using namespace std;
#define pl(x) (x * 2 + 1)
#define pr(x) (x * 2 + 2)
vector<int> arr;
vector<int> tree;
void build(int index, int l, int r)
{
    if (l == r)
    {
        tree[index] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(pl(index), l, mid);
    build(pr(index), mid + 1, r);
    tree[index] = tree[pl(index)] * tree[pr(index)];
}
void change(int index, int ql, int qr, int l, int r, int &value)
{
    if (l >= ql && r <= qr)
    {
        tree[index]=value;
        return ;
    }
    int mid=(l+r)/2;
    if(mid>=ql)
        change(pl(index),ql,qr,l,mid,value);
    if(mid<qr)
        change(pr(index),ql,qr,mid+1,r,value);
    tree[index]=tree[pl(index)]*tree[pr(index)];
}
void query(int index,int ql,int qr,int l,int r,int &ans)
{
    if(ql<=l&&r<=qr)
    {
        ans*=tree[index];
        return ;
    }
    int mid=(l+r)/2;
    if(ql<=mid)
        query(pl(index),ql,qr,l,mid,ans);
    if(mid<qr)
        query(pr(index),ql,qr,mid+1,r,ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    char ch;
    int x, y;
    int ans;
    while (cin >> n >> q)
    {
        arr.resize(n);
        tree.resize(4*n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                arr[i]=1;
            if(arr[i]<0)
                arr[i]=-1;
        }
        build(0, 0, n - 1);
        for (int i = 0; i < q; i++)
        {
            cin >> ch >> x >> y;
            if (ch == 'C')
            {
                if(y>0)y=1;
                if(y<0)y=-1;
                change(0, x - 1, x - 1, 0, n - 1, y);
            }
            else
            {
                ans=1;
                query(0,x-1,y-1,0,n-1,ans);
                if(ans>0)cout<<'+';
                else if(ans<0)cout<<'-';
                else cout<<0;
            }
        }
        cout<<'\n';

        tree.clear();
        arr.clear();
    }

    return 0;
}
