#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> edge, ori;
vector<double> dis;
vector<bool> in_deq;
vector<int> len;
bool spfa(int n)
{
    dis.clear();
    dis.resize(n + 1, 1e9);
    in_deq.clear();
    in_deq.resize(n + 1, 0);
    len.clear();
    len.resize(n + 1, 1);
    deque<int> dq;
    dis[0] = 0;
    dq.push_back(0);
    in_deq[0] = 1;
    while (!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        in_deq[u] = 0;
        for (auto i : edge[u])
        {
            if (dis[i.first] > i.second + dis[u])
            {
                dis[i.first] = i.second + dis[u];
                len[i.first] = len[u] + 1;
                if (len[i.first] > n)
                    return true;
                if (in_deq[i.first])
                    continue;

                if (!dq.empty() && dis[dq.front()] > dis[i.first])
                    dq.push_front(i.first);
                else
                    dq.push_back(i.first);
                in_deq[i.first] = 1;
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v, w, l, r, mid;
    while (cin >> n >> m)
    {
        ori.clear(), ori.resize(n + 1);
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            ori[u].push_back({v, w});
        }
        for (int i = 1; i <= n; i++)
            ori[0].push_back({i, 0});
        l = 0, r = 1e9;
        while (l < r)
        {
            //cout<<"l= "<<l<<" r= "<<r<<" mid= "<<mid<<'\n';
            edge = ori;
            mid = (l + r + 1) / 2;
            for (int i = 1; i <= n; i++)
                for (auto &j : edge[i])
                    j.second -= mid;
            if (!spfa(n + 1))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(l==1e9)cout<<"Infinite\n";
        else if(l==0)cout<<"No Solution\n";
        else cout << l << '\n';

    }

    return 0;
}
/*
u to v
f(u,du):
w-du+dv>=x
w-x>=du-dv;
du-dv<=w-x;


*/
