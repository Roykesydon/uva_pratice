#include <bits/stdc++.h>
using namespace std;
#define ll long long
class mood
{
public:
    int a;
    int b;
    int c;
};
vector<vector<ll>> dp;
vector<mood> arr;
int main()
{
    int n;
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i].a;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].b;
    for (int i = 1; i <= n; i++)
        cin >> arr[i].c;
    dp.resize(n + 1 + 1);
    for (int i = 0; i <= n + 1; i++)
        dp[i].resize(2);
    if (n == 1)
    {
        cout << arr[1].a << '\n';
    }
    else
    {
        dp[2][0] = arr[1].b;
        dp[2][1] = arr[1].a;
        for (int i = 3; i <= n + 1; i++)
        {
            dp[i][0] = max(dp[i - 1][0] + arr[i - 1].b, dp[i - 1][1] + arr[i - 1].c);
            dp[i][1] = max(dp[i - 1][0] + arr[i - 1].a, dp[i - 1][1] + arr[i - 1].b);
        }
        cout << dp[n + 1][1] << '\n';
    }

    return 0;
}
