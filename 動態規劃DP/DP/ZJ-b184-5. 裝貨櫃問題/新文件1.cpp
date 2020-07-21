#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> item;
vector<int> dp;
int main()
{
    int n;
    while (cin >> n)
    {
        dp.resize(101);
        for (int i = 0; i < 101; i++)
            dp[i] = 0;
        item.resize(n);
        for (int i = 0; i < n; i++)
            cin >> item[i].first >> item[i].second;
        for (int i = 0; i < n; i++)
        {

            // for (int i = 0; i < 101; i++)
            // cout<<"dp["<<i<<"]= "<<dp[i]<< ' ';
            // cout << endl;

            for (int j=100;j >= item[i].first; j--)
                dp[j] = max(dp[j], dp[j - item[i].first] + item[i].second);
        }

        cout << dp[100] << '\n';

        dp.clear();
        item.clear();
    }

    return 0;
}
