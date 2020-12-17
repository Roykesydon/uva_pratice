#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>>arr,dp;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n;
    arr.resize(n);
    dp.resize(1<<n,{0,0});
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<n;j++)
            if((1<<j)&i)
                dp[i]={dp[i].first+arr[j].first,dp[i].second+arr[j].second};
    cin>>m;
    for(int cas=1;cas<=m;cas++){
        ll x,y;
        cin>>x>>y;
        cout<<"Case "<<cas<<": ";
        ll minn=1e18;
        for(int i=0;i<(1<<n);i++)
            if(dp[i].first*y>=x)
                minn=min(minn,dp[i].second);
        cout<<((minn==1e18)?"IMPOSSIBLE":to_string(minn))<<'\n';
    }

    return 0;
}
