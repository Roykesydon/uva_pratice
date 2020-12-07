#include <iostream>
// #pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
#define ll long long
#define MOD 1000000007
// vector<vector<vector<vector<ll>>>>dp;
int dp[5005][61][61][2];
int arr[5005];
int ten[5005];
string l, r;
int mod;
int n;
int dfs(int pos, int s, int cur, bool limit)
{
    if (pos == 0)
        return cur == 0;
    if (dp[pos - 1][s][cur][limit] != -1)
        return dp[pos - 1][s][cur][limit];
    int v = ((limit) ? arr[n - pos] : 9);
    // cerr<<"please\n";
    ll ans = 0;
    for (int i = 0; i <= v; i++)
        ans += dfs(pos - 1, (s + i) % mod, ((cur + s * i - i * ten[pos - 1]) % mod + mod) % mod, limit && i == v);
    ans %= MOD;
    return dp[pos - 1][s][cur][limit] = ans;
}
int solve(string x)
{
    // cerr<<"x= "<<x<<'\n';
    // dp.clear();
    n = x.size();

    // dp.resize(n);
    // for(int i=0;i<n;i++)
    //     dp[i].resize(mod);
    // for(int i=0;i<n;i++)
    //     for(int j=0;j<mod;j++)
    //         dp[i][j].resize(mod);
    // for(int i=0;i<n;i++)
    //     for(int j=0;j<mod;j++)
    //         for(int k=0;k<mod;k++)
    //             dp[i][j][k].resize(2,-1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < mod; j++)
            for (int k = 0; k < mod; k++)
                dp[i][j][k][0] = dp[i][j][k][1] = -1;

    for (int i = 0; i < n; i++)
        arr[i] = x[i] - '0';
    // cerr<<"solve safe\n";
    return dfs(n, 0, 0, 1);
    // cerr<<"dfs safe\n";
    // cerr<<"dfs= "<<dfs(n,0,0,1)<<'\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> l >> r >> mod;
        ten[0] = 1 ;
        for (int i = 1; i < 5005; i++)
            ten[i] = (ten[i - 1] * 10) % mod;
        for (int i = l.size() - 1; i >= 0; i--)
        {
            if (l[i] > '0')
            {
                l[i]--;
                break;
            }
            else
                l[i] = '9';
        }
        cout << (((solve(r) - solve(l)) % MOD) + MOD) % MOD << '\n';
    }
    return 0;
}
