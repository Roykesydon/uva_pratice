#include<bits/stdc++.h>
using namespace std;
#define MXN 505
int dp[MXN][MXN];
    string str;
int DP(int l,int r){
    if(dp[l][r]!=0x3f3f3f3f)
        return dp[l][r];
    if(l>r)
        return 0;
    if(l==r)
        return 1;
    int ans=DP(l,r-1)+1;
    for(int k=l;k<r;k++){
        if(str[k]==str[r])
            ans=min(ans,DP(k+1,r-1)+DP(l,k));
    }
    return dp[l][r]=ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    cin>>str;
    memset(dp,0x3f,sizeof(dp));
    cout<<DP(0,n-1)<<'\n';;

    return 0;
}
