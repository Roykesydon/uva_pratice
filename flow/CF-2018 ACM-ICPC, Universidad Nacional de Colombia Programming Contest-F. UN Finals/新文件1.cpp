#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(x) (int)x.size()
struct Dinic
{
    static const int MXN = 10000;
    struct Edge
    {
        int v, f, re;
    };
    int n, s, t, level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i < n; i++)
            E[i].clear();
    }
    void add_edge(int u, int v, int f)
    {
        E[u].PB({v, f, SZ(E[v])});
        E[v].PB({u, 0, SZ(E[u]) - 1});
    }
    bool BFS()
    {
        for (int i = 0; i < n; i++)
            level[i] = -1;
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            for (auto it : E[u])
            {
                if (it.f > 0 && level[it.v] == -1)
                {
                    level[it.v] = level[u] + 1;
                    que.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf)
    {
        if (u == t)
            return nf;
        int res = 0;
        for (auto &it : E[u])
        {
            if (it.f > 0 && level[it.v] == level[u] + 1)
            {
                int tf = DFS(it.v, min(nf, it.f));
                res += tf;
                nf -= tf;
                it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0)
                    return res;
            }
        }
        if (!res)
            level[u] = -1;
        return res;
    }
    int flow(int res = 0)
    {
        while (BFS())
            res += DFS(s, 2147483647);
        return res;
    }
} flow;
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    }
};
/*
class string3
{
public:
    string a;
    string b;
    string c;
};
*/
vector<vector<char>> vec;
vector<vector<int>> arr;
vector<pair<int, int>> letter;
vector<char> id;
int main()
{
    int n, k;
    string a, b, c;
    while (cin >> n)
    {
        vec.resize(n + 1);
        letter.resize(26);
        for (int i = 1; i <= n; i++)
        {
            for (int i = 0; i < 26; i++)
                letter[i] = {0, i};

            cin >> a >> b >> c;
            while (a.size() > 1)
            {
                letter[a[0] - 'A'].first++;
                a.erase(0, 1);
            }
            letter[a[0] - 'A'].first++;
            while (b.size() > 1)
            {
                letter[b[0] - 'A'].first++;
                b.erase(0, 1);
            }
            letter[b[0] - 'A'].first++;
            while (c.size() > 1)
            {
                letter[c[0] - 'A'].first++;
                c.erase(0, 1);
            }
            letter[c[0] - 'A'].first++;

            sort(letter.begin(), letter.end(), cmp());
            /*
            for (int i = 0; i < n; i++)
            {
                if (letter[i].first == 0)
                    break;
                cout << letter[i].first << ' ' << letter[i].second << " || ";
            }
            cout << '\n';
            */
            int maxn = letter[0].first;
            for (int k = 0; k < 26; k++)
                if (letter[k].first == maxn)
                {
                    //cout << " letter[" << i << "].first= " << letter[i].first << '\n';
                    vec[i].push_back((char)(letter[k].second + 'A'));
                    id.push_back((char)(letter[k].second + 'A'));
                }
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            cout << "i= " << i << '\n';
            for (auto j : vec[i])
                cout << j << ' ';
            cout << '\n';
        }
        */
        cin >> k;
        sort(id.begin(), id.end());
        id.resize(unique(id.begin(), id.end()) - id.begin());
        arr.resize(n + id.size() + 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                vec[i][j] = lower_bound(id.begin(), id.end(), vec[i][j]) - id.begin() + 1 + n;
            }
        }
        /*
        for (int i = 1; i <= n; i++)
        {
            cout << "i= " << i << '\n';
            for (auto j : vec[i])
                cout << (int)j << ' ';
            cout << '\n';
        }
        */
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                //cout << (int)j << endl;
                if (lower_bound(arr[vec[i][j]].begin(), arr[vec[i][j]].end(), i) == arr[vec[i][j]].end())
                    arr[vec[i][j]].push_back(i);
            }
        }

        //煩欸 題目看反了
        /*
        for (int i = n + 1; i <= n + id.size(); i++)
        {
            cout << "arr[" << i << "]= ";
            for (auto j : arr[i])
                cout << j << ' ';
            cout << '\n';
        }
        */
        flow.init(n + id.size() + 2 + 1, n + id.size() + 1, n + id.size() + 2);
        for (int i = n + 1; i <= n + id.size(); i++)
        {
            //cout << "add " << n + id.size() + 1 << " to " << i << '\n';
            flow.add_edge(n + id.size() + 1, i, k);
            for (auto j : arr[i])
            {
                flow.add_edge(i, j, 1);
                //cout << "add " << i << " to " << j << '\n';

                //cout << "add " << j << " to " << n + id.size() + 2 << '\n';
            }
        }
        for (int i = 1; i <= n; i++)
            flow.add_edge(i, n + id.size() + 2, 1);
        cout << flow.flow() << '\n';

        arr.clear();
        id.clear();
        vec.clear();
    }
    return 0;
}

