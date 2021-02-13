#include<bits/stdc++.h>
using namespace std;
#define c8763 ios::sync_with_stdio(0);cin.tie(0);
vector<int>arr;
vector<vector<int>>dp;
int dfs(int x,int y){
    if(x==y-1)
        return 0;
    if(dp[x][y])
        return dp[x][y];
    int ans=1e9;
    for(int i=x+1;i<y;i++)
        ans=min(ans,dfs(x,i)+dfs(i,y));
    return dp[x][y]=ans+arr[y]-arr[x];
}
int main(){
    c8763
    int l,n;
    while(cin>>l&&l){
        cin>>n;
        if(n==0){
            cout<<"The minimum cutting is 0.\n";
            continue;
        }

        arr.clear();
        dp.clear();

        arr.resize(n+2);
        dp.resize(n+2);
        for(int i=0;i<dp.size();i++)
            dp[i].resize(n+2,0);
        for(int i=1;i<=n;i++)
            cin>>arr[i];
        arr[0]=0;
        arr[n+1]=l;
        cout<<"The minimum cutting is "<<dfs(0,n+1)<<"."<<'\n';
    }


    return 0;
}
