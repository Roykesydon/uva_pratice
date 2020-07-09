#include <bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, cmp> pq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, ans, cur;
    while (cin >> n)
    {
        vec.resize(n);
        for (int i = 0; i < n; i++)
            cin >> vec[i].first >> vec[i].second;
        sort(vec.begin(), vec.end(), cmp());

        // for(auto i:vec)
        //     cout<<i.first<<' '<<i.second<<" || ";
        // cout<<endl;
        cur = vec[0].first;
        t = vec[0].first;
        ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (vec[i].first > t)
            {
                cur = vec[i].first;
                while (!pq.empty() && t < cur)
                {
                    if (pq.top() < t)
                        pq.pop();
                    else
                    {
                        t++;
                        pq.pop();
                        ans++;
                    }
                }              
                if (pq.empty())
                    t = vec[i].first;
                pq.push(vec[i].second);
            }
            else if(vec[i].first <= t)
            {
                pq.push(vec[i].second);
            }
        }
        cur = 1e9 + 2;
        while (!pq.empty() && t < cur)
        {
            if (pq.top() < t)
                pq.pop();
            else
            {
                t++;
                pq.pop();
                ans++;
            }
        }
        cout << ans << '\n';

        while (!pq.empty())
            pq.pop();
        vec.clear();
    }

    return 0;
}
