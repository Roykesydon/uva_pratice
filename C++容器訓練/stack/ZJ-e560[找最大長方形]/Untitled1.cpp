#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> pre, arr;
stack<pair<int, int>> st;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    int ans = 0;
    while (cin >> n >> m && (n || m))
    {
        arr.clear();
        arr.resize(n);
        for (int i = 0; i < n; i++)
            arr[i].resize(m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        pre.clear();
        pre.resize(n);
        for (int i = 0; i < n; i++)
            pre[i].resize(m);
        for (int i = 0; i < m; i++)
            pre[0][i] = ((arr[0][i] == 1) ? 0 : 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 1)
                    pre[i][j] = 0;
                else
                    pre[i][j] = pre[i - 1][j] + 1;
        ans=0;
        for (int i = 0; i < n; i++)
        {
            while(!st.empty())
                st.pop();
            for (int j = 0; j < m; j++)
            {
                // cerr<<"i= "<<i<<" j= "<<j<<'\n';
                if (st.empty())
                {
                    if (pre[i][j])
                        st.push({pre[i][j], j});
                    continue;
                }
                if (pre[i][j] > st.top().first)
                    st.push({pre[i][j], j});
                else if (pre[i][j] == st.top().first)
                    continue;
                else
                {
                    int tmp=j;
                    while (!st.empty() && pre[i][j] < st.top().first)
                    {
                        ans = max(ans, (j - st.top().second) * st.top().first);
                        tmp=st.top().second;
                        st.pop();
                    }
                    if(pre[i][j]==0)continue;
                    if (st.empty()||pre[i][j]>st.top().first)
                        st.push({pre[i][j], tmp});
                }
            }
            while (!st.empty())
            {
                ans = max(ans, (m - st.top().second) * st.top().first);
                st.pop();
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
