#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> arr1, arr2;
ll dp[2];
int main()
{
    ll n;
    cin >> n;
    arr1.resize(n);
    arr2.resize(n);
    dp[0]=0;
    dp[1]=0;
    for (ll i = 0; i < n; i++)
        cin >> arr1[i];
    for (ll i = 0; i < n; i++)
        cin >> arr2[i];
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    for (ll i = 0; i < n; i++)
    {
        ll tmp0=dp[0],tmp1=dp[1];
        if (i >= 1)
        {
            dp[0]=max(tmp0,arr1[i]+tmp1);
            dp[1]=max(tmp1,arr2[i]+tmp0);
        }
        else
        {
            dp[0] = arr1[i];
            dp[1] = arr2[i];
        }
    }
    cout << max(dp[0],dp[1]) << '\n';
    return 0;
}
