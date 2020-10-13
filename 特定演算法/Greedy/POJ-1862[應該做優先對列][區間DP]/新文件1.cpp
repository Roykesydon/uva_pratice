#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
#define ll long long
#define eps (1e-6)
vector<double> arr;
vector<vector<double> > dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    dp.resize(n);
    for (int i = 0; i < n; i++)
        dp[i].resize(n,1e9);

    for(int i=0;i<n;i++)
        dp[i][i]=arr[i];
    for (int len = 2; len <= n; len++)
        for (int i = 0; i+len-1 < n; i++)
        {
            for (int j = i; j <i+len-1 ; j++)
            {
                dp[i][i+len-1]=min(dp[i][i+len-1],2*sqrt(dp[i][j]*dp[j+1][i+len-1]));
            }
        }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cout<<fixed<<setprecision(3)<<dp[i][j]<<' ';
    //     cout<<'\n';
    // }
    cout<<fixed<<setprecision(3)<<dp[0][n-1]<<'\n';
    return 0;
}
