#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    { //if money
        if (a.second != b.second)
            return a.second < b.second;
        return a.second > b.second;
    }
};
vector<int> fa;
vector<pair<int, int>> arr; //time,gold
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq[2];
int find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int a, int b)
{
    fa[find(a)] = find(b);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, t, x, ans;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> n >> m;
        fa.clear();
        fa.resize(n + 1);
        arr.clear();
        arr.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].first >> arr[i].second >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> x;
                merge(i, x);
            }
        }
        ans = INF;
        for (int i = 1; i <= n; i++)
        {
            if (fa[i] == i)
            {
                while (!pq[0].empty())
                    pq[0].pop();
                while (!pq[1].empty())
                    pq[1].pop();
                pq[0].push({0, 0});
                for (int j = 1; j <= n; j++)
                {
                    if (find(j) == i)
                    {
                        while (!pq[0].empty())
                        {
                            auto u = pq[0].top();
                            pq[0].pop();
                            pq[1].push(u);
                            u.first += arr[j].first;
                            u.second += arr[j].second;
                            if (u.second >= m)
                            {
                                ans = min(ans, u.first);
                                continue;
                            }
                            if (u.first >= ans)
                                continue;
                            pq[1].push(u);
                        }
                        int x = INF;
                        while (!pq[1].empty())
                        {
                            auto u = pq[1].top();
                            pq[1].pop();
                            if (u.first < x)
                            {
                                x = u.first;
                                pq[0].push(u);
                            }
                            if (u.second >= m)
                                ans = min(ans, u.first);
                        }
                    }
                }
            }
        }
        cout << "Case " << cas << ": ";
        if (ans == INF)
            cout << "Poor Magina, you can't save the world all the time!\n";
        else
            cout << ans << '\n';
    }

    return 0;
}
