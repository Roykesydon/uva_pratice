#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> pt;
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};
int cross(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
}
int main()
{
    int n;
    pair<int, int> a, b, c;
    stack<pair<int, int>> st;
    while (cin >> n && n)
    {
        pt.resize(n);
        for (int i = 0; i < n; i++)
            cin >> pt[i].first >> pt[i].second;
        sort(pt.begin(), pt.end(), cmp());
        st.push(pt[0]);
        if (n >= 2)
            st.push(pt[1]);
        for (int i = 2; i < n; i++)
        {
            st.push(pt[i]);
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            c = st.top();
            st.pop();
            if (cross(c, b, a) > 0)
            {
                st.push(c);
                st.push(b);
                st.push(a);
            } //¶¶®ÉÄÁ
            else
            {
                if (st.empty())
                {
                    st.push(c);
                    st.push(a);
                }
                else
                {
                    st.push(c);
                    i--;
                }
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            st.push(pt[i]);
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            c = st.top();
            st.pop();
            if (cross(c, b, a) < 0)
            {
                st.push(c);
                st.push(b);
                st.push(a);
            } //¶¶®ÉÄÁ
            else
            {
                if (st.empty())
                {
                    st.push(c);
                    st.push(a);
                }
                else
                {
                    st.push(c);
                    i++;
                }
            }
        }
        // while (!st.empty())
        // {
        //     cout << st.top().first << ' ' << st.top().second << " || ";
        //     st.pop();
        // }
        cout << st.size() << '\n';
        while (!st.empty())
            st.pop();
        pt.clear();
    }

    return 0;
}
