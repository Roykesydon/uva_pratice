#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int t;
int m;
int ans2;
vector<vector<int>> anc;
vector<vector<int>> edge;
vector<bool> vis;
vector<int> depth;
vector<pair<int, int>> in_out;
void build(int x, int f)
{
    for (int i = 0; i < m; i++)
    {
        anc[x][i] = f;
        f = anc[f][i];
    }
}
void DFS(int x, int f)
{
    build(x, f);
    for (auto i : edge[x])
    {
        if (i == f)
            continue;
        DFS(i, x);
    }
}
void pre_DFS(int x, int f)
{
    in_out[x].first = t++;
    for (auto i : edge[x])
    {
        if (i == f)
            continue;
        pre_DFS(i, x);
    }
    in_out[x].second = t++;
}
bool isFather(int a, int b)
{
    //cout << "isFarther " << a + 1 << " , " << b + 1 << endl;
    return in_out[a].first <= in_out[b].first && in_out[a].second >= in_out[b].second;
}
int lca(int a, int b)
{
    for (int i = m - 1; i >= 0; i--)
    {
        if (!isFather(anc[a][i], b))
        {
            a = anc[a][i];
        }
    }
    return anc[a][0];
}
void DFS_find(int from, int a, int value)
{
    depth[a] = value;
    for (auto i : edge[a])
    {
        if (i == from)
            continue;
        DFS_find(a, i, value + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, tmp;
    int a, b, root;
    while (cin >> n >> q)
    {
        anc.resize(n);
        depth.resize(n);
        edge.resize(n);
        in_out.resize(n);
        vis.resize(n);
        m = __lg(n) + 1;
        for (int i = 0; i < n; i++)
            vis[i] = false;
        for (int i = 0; i < n; i++)
        {
            anc[i].resize(m);
            while (cin >> tmp && tmp)
            {
                vis[tmp - 1] = true;
                edge[i].push_back(tmp - 1);
                edge[tmp - 1].push_back(i);
            }
        }
        for (int i = 0; i < n; i++)
            if (!vis[i])
                root = i;
        DFS_find(-1, root, 0);
        //cout << "root= " << root << endl;
        for (int i = 0; i < m; i++)
        {
            anc[root][i] = root;
        }
        t = 0;
        pre_DFS(root, root);
        DFS(root, root);
        //cout << "anc: " << anc[5][0] << " " << anc[5][1] << endl;
        for (int i = 0; i < q; i++)
        {
            cin >> a >> b;
            if (isFather(a - 1, b - 1))
            {
                cout << a << ' ';
                cout << depth[b - 1] - depth[a - 1] << '\n';
            }

            else if (isFather(b - 1, a - 1))
            {
                cout << b << ' ';
                cout << depth[a - 1] - depth[b - 1] << '\n';
            }

            else
            {
                int x = lca(a - 1, b - 1) + 1;
                cout << x << ' ';
                cout << depth[a - 1] - depth[x - 1] + depth[b - 1] - depth[x - 1] << '\n';
            }

            //cout << ans2 << '\n';
        }
        vis.clear();
        anc.clear();
        edge.clear();
        in_out.clear();
        depth.clear();
    }
    return 0;
}
