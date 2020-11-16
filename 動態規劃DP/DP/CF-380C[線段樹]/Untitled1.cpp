#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define pl(x) (2 * x + 1)
#define pr(x) (2 * x + 2)
int seq[MAXN << 2], r[MAXN], l[MAXN], n;//l[x] invalid,r[x] :valid
string str;
void build(int index, int L, int r)
{
    if (L == r)
    {
        seq[index] = l[L];
        return;
    }
    int mid = (L + r) / 2;
    build(pl(index), L, mid);
    build(pr(index), mid + 1, r);
    seq[index] = min(seq[pl(index)], seq[pr(index)]);
}
void query(int index, int ql, int qr, int L, int r, int &tmp)
{
    if (L >= ql && r <= qr)
    {
        tmp = min(tmp, seq[index]);
        return;
    }
    int mid = (L + r) / 2;
    if (ql <= mid)
        query(pl(index), ql, qr, L, mid, tmp);
    if (qr > mid)
        query(pr(index), ql, qr, mid + 1, r, tmp);
}
void init()
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {   
        if(i)r[i]=r[i-1];
        if (str[i] == '(')
            tmp++;
        else if(tmp)
            r[i]++,tmp--;
        l[i] = tmp;
    }
    build(0, 0, n - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, x, y;
    
    cin >> str;
    n = str.size();

    init();
    // cout<<"s= ";
    // for(int i=0;i<n;i++)
    //     cout<<setw(3)<<str[i]<<' ';
    // cout<<endl;
    // cout<<"l= ";
    // for(int i=0;i<n;i++)
    //     cout<<setw(3)<<l[i]<<' ';
    // cout<<endl;
    // cout<<"r= ";
    // for(int i=0;i<n;i++)
    //     cout<<setw(3)<<r[i]<<' ';
    // cout<<endl;

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--, y--;
        int tmp = 1e9, ffff, kkkk;
        query(0, x, y, 0, n - 1, tmp);

        if (x - 1 < 0)
            ffff = 0, kkkk = 0;
        else
            ffff = r[x - 1], kkkk = l[x - 1];
        // cout<<"r[y]= "<<r[y]<<'\n';
        // cout<<"ffff= "<<ffff<<'\n';
        // cout<<"kkkk= "<<kkkk<<'\n';
        // cout<<"tmp= "<<tmp<<'\n';
        cout << (r[y] - ffff - max(kkkk-tmp,0)) * 2 << '\n';
    }

    return 0;
}
