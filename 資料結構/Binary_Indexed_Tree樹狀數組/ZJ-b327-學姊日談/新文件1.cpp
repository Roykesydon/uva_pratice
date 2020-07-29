#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x);
vector<vector<int>> edge;
vector<int> sz;
vector<int> top;
vector<int> heavy_chain;
vector<vector<int>> BIT;
vector<int> myindex;
vector<int> dep;
vector<int> father;
int cnt;
//vector<int> len;
//ºâ²`«× ¤÷¿Ë
int sz_dep_father_dfs(int from, int cur, int depth)
{
    sz[cur] = 1;
    father[cur] = from;
    dep[cur] = depth;
    for (auto i : edge[cur])
    {
        if (i == from)
            continue;
        sz[cur] += sz_dep_father_dfs(cur, i, depth + 1);
    }
    return sz[cur];
}
void hc_dfs(int from, int cur)
{
    int tmp = -1;
    int tmpp = -1;
    for (auto i : edge[cur])
    {
        if (i == from)
            continue;
        hc_dfs(cur, i);
        if (sz[i] > tmp)
        {
            tmp = sz[i];
            tmpp = i;
        }
    }
    heavy_chain[cur] = tmpp;
}
void tp_dfs(int from, int cur)
{
    for (auto i : edge[cur])
    {
        if (i == from)
            continue;
        if (i == heavy_chain[cur])
        {
            top[i] = top[cur];
            tp_dfs(cur, i);
        }
        else
        {
            cnt++;
            top[i] = i;
            tp_dfs(cur, i);
        }
    }
}
void bit_dfs(int from, int cur)
{
    BIT[myindex[top[cur]]].push_back(0);
    for (auto j : edge[cur])
    {
        if (j == from)
            continue;
        bit_dfs(cur, j);
    }
}
int query(int x)
{
    int _index_x = myindex[top[x]];
    int ans = 0;
    int in_index = dep[x] - dep[top[x]] + 1;
    while (in_index)
    {
        ans += BIT[_index_x][in_index - 1];
        in_index -= lowbit(in_index);
    }
    if (father[top[x]] != -1)
    {
        ans += query(father[top[x]]);
    }
    return ans;
}
void modify(int x, int value)
{
    int _index_x = myindex[top[x]];
    int in_index = dep[x] - dep[top[x]] + 1;
    while (in_index <= BIT[_index_x].size())
    {
        BIT[_index_x][in_index - 1] += value;
        in_index += lowbit(in_index);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    int u, v, tmp;
    while (cin >> n)
    {
        edge.resize(n);
        sz.resize(n);
        top.resize(n);
        myindex.resize(n);
        dep.resize(n);
        father.resize(n);
        heavy_chain.resize(n);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        sz_dep_father_dfs(-1, 0, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << "i= " << i << ' ';
        //     cerr << sz[i] << '\n';
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << "i= " << i << ' ';
        //     cerr << father[i] << '\n';
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << "i= " << i << ' ';
        //     cerr << dep[i] << '\n';
        // }
        hc_dfs(-1, 0);
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << "i= " << i << ' ';
        //     cerr << heavy_chain[i] << '\n';
        // }
        top[0] = 0;
        cnt = 1;
        tp_dfs(0, 0);
        BIT.resize(cnt);
        tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if (top[i] == i)
                myindex[top[i]] = tmp++;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << "i= " << i << " => ";
        //     cerr << top[i];
        //     cerr << '\n';
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     cerr << "i= " << i << " => ";
        //     cerr << father[i];
        //     cerr << '\n';
        // }
        bit_dfs(0, 0);
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            modify(u, v);
            cout << query(u) << '\n';
        }
        // for (int i = 0; i < cnt; i++)
        // {
        //     cerr << "i= " << i << " => ";
        //     for (auto j : BIT[i])
        //     {
        //         cerr << j << ' ';
        //     }
        //     cerr << '\n';
        // }
        dep.clear();
        father.clear();
        myindex.clear();
        BIT.clear();
        heavy_chain.clear();
        top.clear();
        sz.clear();
        edge.clear();
    }

    return 0;
}
