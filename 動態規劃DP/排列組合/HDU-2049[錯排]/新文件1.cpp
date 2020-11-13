#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[21];
ll C(int n,int m){
    if(n==m||m==0)
        return 1;
    return C(n-1,m)+C(n-1,m-1);
}
void init(){
    dp[1]=0;
    dp[2]=1;
    for(ll i=3;i<21;i++)
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,m,n;
    init();
    cin>>c;
    while(c--){
        cin>>n>>m;
        cout<<C(n,m)*dp[m]<<'\n';   
    }
    return 0;
}
