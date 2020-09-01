#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<char> arr;
vector<vector<ll>> dp;
int main()
{
    ll n, cur, sum,ans;
    bool flag;
    cin >> n;
    arr.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    dp.resize(n + 1);
    for (ll i = 0; i <= n; i++)
        dp[i].resize(n,0);

    cur = 0;
    flag = 0;
    dp[1][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        sum = 0;
        if (arr[i] == 'f')
        {
            if (flag)
            {
                for (ll j = cur; j >= 1; j--)
                {
                    dp[i][j] =dp[i-1][j-1]%mod;
                }
            }
            else
            {
                for (ll j = cur; j >= 0; j--)
                {
                    sum += dp[i - 1][j];
                    sum%=mod;
                    dp[i][j] += sum;
                    dp[i][j]%=mod;
                }
            }
            cur++;
            flag = 1;
        }
        else
        {
            if (flag)
            {
                for(ll j=cur;j>=1;j--)
                    dp[i][j]=dp[i-1][j-1]%mod;
                flag = 0;
            }
            else
            {
                for (ll j = cur; j >= 0; j--)
                {
                    sum += dp[i - 1][j];
                    sum%=mod;
                    dp[i][j] += sum;
                    dp[i][j]%=mod;
                }
            }
        }
    }
    ans=0;
    for(ll i=0;i<n;i++){
        ans+=dp[n][i];
        ans%=mod;
    }
    cout<<ans<<'\n';
    return 0;
}
/*
f
    f
        s
    s
        s(wrong)
s
//------------
4
s
f
f
s
dp[0][0]=1
flag=0;
cur=0;
dp[1][0]=1;
cur++;flag=1;
    d[2][1]=1;
    cur++;flag=1;
        dp[3][2]=1;
        cur=2;flag=0;
//--------------
4
f
s
f
s
dp[0][0]=1;
cur++;flag=1;
           dp[1][1]=1;
           cur=1;flag=0;
dp[2][0]=1;dp[2][1]=1;
           dp[3][1]=1;dp[3][2]=1;
*/

// f
//  f
//   f
//    f
//     s
//     s

//     dp[6][5]=dp[5][5]

//     dp[6][4]=dp[5][5]+dp[5][4]
