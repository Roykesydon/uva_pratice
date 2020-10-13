#include <bits/stdc++.h>
using namespace std;
#define MAXN (1120)
vector<vector<int>> dp;
vector<bool> prime;
vector<int> item;
void init()
{
    for (int i = 2; i <= MAXN; i++)
        if (prime[i])
            for (int j = i + i; j <= MAXN; j += i)
                prime[j] = 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    prime.resize(MAXN + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    init();
    for (int i = 0; i <= MAXN; i++)
        if (prime[i])
            item.push_back(i);

    dp.resize(MAXN + 1);
    for (int i = 0; i <= MAXN; i++)
        dp[i].resize(15, 0);

    dp[0][0] = 1;
    for (int g = 0; g < item.size(); g++) //first g item
        for (int i = MAXN; i >= item[g]; i--)
            for (int j = 1; j <= 14; j++)
                dp[i][j] += dp[i - item[g]][j - 1];

    while (cin >> n >> k && (n || k))
        cout << dp[n][k] << '\n';

    return 0;
}
