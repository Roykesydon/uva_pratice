#include <bits/stdc++.h>
using namespace std;
class query
{
public:
    int ql;
    int qr;
    int index;
    int sec_id;
};
class cmp
{
public:
    bool operator()(query a, query b)
    {
        if (a.sec_id != b.sec_id)
            return a.sec_id < b.sec_id;
        else
        {
            return a.qr < b.qr;
        }
    }
};
int k;
vector<int> arr;
vector<int> cnt;
vector<int> sum_cnt;
vector<pair<int, int>> ans;
pair<int, int> maxn;
vector<query> que;
void add(int i)
{
    sum_cnt[cnt[i]]--;
    cnt[i]++;
    sum_cnt[cnt[i]]++;
    if (cnt[i] > maxn.first) //�񲳼Ƥj
    {
        maxn = {cnt[i], 1};
    }
    else if (cnt[i] == maxn.first) //�O����
    {
        maxn.second++;
    }
}
void sub(int i)
{
    sum_cnt[cnt[i]]--; //cnt[i]�Oi���X��
    cnt[i]--;
    sum_cnt[cnt[i]]++;
    if (!sum_cnt[maxn.first] && maxn.first == cnt[i] + 1) //i�O���ƥB�O�̫�@��
    {
        maxn.first = cnt[i];
        maxn.second = sum_cnt[cnt[i]];
    }
    else if (maxn.first == cnt[i] + 1) //�O���Ʀ����O�̫�@��
        maxn.second--;
}
void mo()
{
    for (int i = 0, l = 1, r = 0; i < que.size(); i++) //�����B�z
    {
        while (que[i].qr > r)
        {
            r++;
            add(arr[r]);
        }
        while (que[i].qr < r)
        {
            r--;
            sub(arr[r + 1]);
        }
        while (que[i].ql > l)
        {
            l++;
            sub(arr[l - 1]);
        }
        while (que[i].ql < l)
        {
            l--;
            add(arr[l]);
        }

        ans[que[i].index] = maxn;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m)
    {
        k = sqrt(n);

        arr.resize(n + 1, 0);
        que.resize(m);
        cnt.resize(n + 1, 0);
        ans.resize(m);
        sum_cnt.resize(n + 1, 0);

        sum_cnt[0] = n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 0; i < m; i++)
        {
            cin >> que[i].ql >> que[i].qr;
            que[i].index = i;
            que[i].sec_id = que[i].ql / k;
        }
        sort(que.begin(), que.end(), cmp());
        maxn = {0, 0};
        //cerr << "pre is ok\n";
        mo();
        //cerr << "after mo() is ok\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << ' ' << ans[i].second << '\n';

        cnt.clear();
        sum_cnt.clear();
        arr.clear();
        que.clear();
        ans.clear();
    }

    return 0;
}
