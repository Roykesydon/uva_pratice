#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define FZ(n) memset(n, 0, sizeof(n))
#define MXN 50
struct Scc
{
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n)
    {
        n = _n;
        for (int i = 0; i < MXN; i++)
            E[i].clear(), rE[i].clear();
    }
    void addEdge(int u, int v)
    {
        E[u].PB(v);
        rE[v].PB(u);
    }
    void DFS(int u)
    {
        vst[u] = 1;
        for (auto v : E[u])
            if (!vst[v])
                DFS(v);
        vec.PB(u);
    }
    void rDFS(int u)
    {
        vst[u] = 1;
        bln[u] = nScc;
        for (auto v : rE[u])
            if (!vst[v])
                rDFS(v);
    }
    void solve()
    {
        nScc = 0;
        vec.clear();
        FZ(vst);
        for (int i = 0; i < n; i++)
            if (!vst[i])
                DFS(i);
        reverse(vec.begin(), vec.end());
        FZ(vst);
        for (auto v : vec)
            if (!vst[v])
            {
                rDFS(v);
                nScc++;
            }
    }
} scc;
map<string, int> mp;
map<int, string> name;
vector<vector<string>> ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int test_cnt = 1;
    int id;
    string s1, s2;
    while (cin >> n >> m && n && m)
    {
        id = 1;
        scc.init(n+1);
        ans.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> s1 >> s2;
            if (mp[s1] == 0)
            {
                mp[s1] = id;
                name[id++] = s1;
            }

            if (mp[s2] == 0)
            {
                mp[s2] = id;
                name[id++] = s2;
            }
            //cerr<<mp[s1]<< ' '<<mp[s2]<<'\n';
            scc.addEdge(mp[s1], mp[s2]);
        }
        scc.solve();
        for (int i = 1; i <= n; i++)
        {
            //cout<<i<<' '<<scc.bln[i]<<'\n';
            ans[scc.bln[i]].push_back(name[i]);
        }

        if (test_cnt > 1)
            cout << '\n';
        cout << "Calling circles for data set " << test_cnt++ << ":\n";
        for (int i = 0; i < n; i++)
        {
            if (ans[i].size() != 0)
            {
                cout << ans[i][0];
                for (int j = 1; j < ans[i].size(); j++)
                    cout << ", " << ans[i][j];
                cout << '\n';
            }
        }
        name.clear();
        mp.clear();
        ans.clear();
    }
    return 0;
}
