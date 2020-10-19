#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
vector<vector<ll>> arr;
vector<vector<vector<ll>>> dp;
void init(ll n, ll m)
{
    arr.clear();
    arr.resize(n + 1);
    for (ll i = 0; i <= n; i++)
        arr[i].resize(m + 1);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            cin>>arr[i][j];

    dp.clear();
    dp.resize(n + 1);
    for (ll i = 0; i <= n; i++)
        dp[i].resize(m + 1);
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j <= m; j++)
            dp[i][j].resize(1 << (m + 1),0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    ll n, m;
    cin >> t;
    for (ll cas = 1; cas <= t; cas++)
    {
        cin >> n >> m;
        init(n, m);
        dp[1][0][0]=1;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                ll plug1=1<<(j-1),plug2=(1<<j);
                for(ll k=0;k<1<<(m+1);k++){
                    if(arr[i][j]){
                        dp[i][j][k]+=dp[i][j-1][k^plug1^plug2];
                        if(((k&plug1)!=0)^((k&plug2)!=0))
                            dp[i][j][k]+=dp[i][j-1][k];
                        dp[i][j][k]%=mod;
                    }
                    else{
                        if((k&plug1)==0&&(k&plug2)==0)
                            dp[i][j][k]=dp[i][j-1][k];
                        else
                            dp[i][j][k]=0;
                    }
                }
            }
            if(i!=n)for(ll j=0;j<(1<<m);j++)
                dp[i+1][0][j<<1]=dp[i][m][j];
        }


        cout << "Case " << cas << ": " <<dp[n][m][0]%mod<<'\n';
    }

    return 0;
}
