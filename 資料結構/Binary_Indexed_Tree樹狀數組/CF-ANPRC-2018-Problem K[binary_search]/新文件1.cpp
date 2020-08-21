#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
class que
{
public:
    int time;
    int kth;
    int id;
};
vector<que> q;
vector<pair<int, int>> mytime;
vector<int> ans;
int BIT[1000000 + 1];
class cmp1
{
public:
    bool operator()(que a, que b)
    {
        return a.time < b.time;
    }
};
class cmp2
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (abs(a.first) != abs(b.first))
            return abs(a.first) < abs(b.first);
        return a.first > b.first;
    }
};
void modify(int index, int value)
{
    while (index <= 1000000)
    {
        BIT[index] += value;
        index += lowbit(index);
    }
}
int query(int index)
{
    int tmp = 0;
    while (index)
    {
        tmp += BIT[index];
        index -= lowbit(index);
    }
    return tmp;
}
bool check(int x, int kth)
{
    if (query(x - 1) <= kth - 1)
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    char ch;
    int t, e, a, b, c, q_cnt, cur, cas_cnt;
    cin >> t;
    for (cas_cnt = 1; cas_cnt <= t; cas_cnt++)
    {
        cout << "Case " << cas_cnt << ":\n";
        mytime.clear();
        q.clear();
        ans.clear();
        memset(BIT, 0, sizeof(BIT));
        q_cnt = 0;
        cin >> e;
        for (int i = 0; i < e; i++)
        {
            cin >> ch;
            if (ch == '1')
            {
                cin >> a >> b >> c;
                mytime.push_back({a, b});
                mytime.push_back({-c - 1, b});
            }
            else
            {
                cin >> a >> b;
                q.push_back({a, b, q_cnt++});
            }
        }
        //cerr<<mytime.size()<<' '<<q.size()<<'\n';
        sort(mytime.begin(), mytime.end(), cmp2());
        sort(q.begin(), q.end(), cmp1());
        // for(auto i:mytime)
        //     cerr<<i.first<<' '<<i.second<<'\n';

        // for (auto i : q)
        //     cerr << i.time << ' ' << i.kth << '\n';
        ans.resize(q.size());
        cur = 0;
        for (int i = 0; i < q.size(); i++)
        {
            //cerr<<"q[i].time= "<<q[i].time<<' '<<"q[i].kth= "<<q[i].kth<<' '<<"q[i].id= "<<q[i].id<<'\n';
            while (cur < mytime.size() && abs(mytime[cur].first) <= q[i].time)
            {
                modify(mytime[cur].second, ((mytime[cur].first > 0) ? 1 : -1));
                cur++;
            }
            int l = 1, r = 1000000, mid;
            if (query(1000000) < q[i].kth)
                l = -1;
            else
                while (l < r)
                {
                    mid = (l + r + 1) / 2;
                    //cerr<<"l= "<<l<<" r= "<<r<<" mid= "<<mid<<'\n';
                    if (check(mid, q[i].kth))
                        l = mid;
                    else
                        r = mid - 1;
                }
            // cerr<<"test query(10)= "<<query(10)<<'\n';
            // if(l!=-1)
            //     cerr<<" query(l-1)= "<<query(l-1);
            // cerr<<'\n';
            ans[q[i].id] = l;
        }
        for (auto i : ans)
            cout << i << '\n';
    }

    return 0;
}
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
/*
  10         -10
    9  -9
          2-2
                2                                 -2
                  1                -1
                    3        -3
*/
