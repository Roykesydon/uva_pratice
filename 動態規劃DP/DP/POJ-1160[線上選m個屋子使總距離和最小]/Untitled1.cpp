#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long
vector<vector<ll> > dis, dp;//dp[i][j] = choose j+1 house from previous i+1 houses 
vector<ll> arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    dp.resize(n);
    for (int i = 0; i < n; i++)
        dp[i].resize(m, 1e18);
    dis.resize(n);
    for (int i = 0; i < n; i++)
        dis[i].resize(n, 1e18);
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        dis[i][i] = 0;
        for (int j = i + 1; j < n; j++)          
            dis[i][j] = dis[i][j - 1] + arr[j] - arr[(i + j) / 2];
        dp[i][0]=dis[0][i];
    }
    for (int j = 1; j < m; j++)
    {
        dp[j][j] = 0;
        for (int i = j+1; i < n; i++)
            for (int k = j; k < i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j-1] + dis[k+1][i]);
    }
    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}
