#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector<int>arr;
ull dp[65][2][2][2];
int n;
ull dfs(int pos,bool pre_four,bool limit,bool state){
    if(pos==0)
        return state;
    if(dp[pos][pre_four][limit][state]!=-1)return dp[pos][pre_four][limit][state];
    int v=((limit)?arr[n-pos]:9);
    ull ans=0;
    for(int i=0;i<=v;i++)
        ans+=dfs(pos-1,i==4,limit&&i==v,state||(pre_four&&i==9));
    return dp[pos][pre_four][limit][state]=ans;
}
ull solve(string str){
    memset(dp,-1,sizeof(dp));
    arr.clear();
    n=str.size();
    arr.resize(n);
    for(int i=0;i<n;i++)
        arr[i]=str[i]-'0';
    dfs(n,0,1,0);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    string str;
    while(t--){
        cin>>str;
        cout<<solve(str)<<'\n';
    }


    return 0;
}
