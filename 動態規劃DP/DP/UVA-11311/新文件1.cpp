#include<bits/stdc++.h>
using namespace std;
int t, n, m, r, c;
int dp[50][50][50][50];//dp[n][m][r][c]
int mex(vector<int>&a) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end())-a.begin());
    for (int i=0;i<=a.size();i++) {
        if (i==a.size())return i;
        if (a[i]!=i)return i;
    }
}
int dfs(int n, int m, int r, int c) {
    vector<int>tmp;
    if (dp[n][m][r][c]!=-1)
        return  dp[n][m][r][c];
    if (n==1&&m==1)
        return 0;
    for (int i=0;i<m-1;i++) {
        if (r<i+1)
            tmp.push_back(dfs(n, i+1, r, c));
        else
            tmp.push_back(dfs(n, m-(i+1), r-(i+1), c));
    }
    for (int i=0;i<n-1;i++) {
        if (c<i+1)
            tmp.push_back(dfs(i+1, m, r, c));
        else
            tmp.push_back(dfs(n-(i+1), m, r, c-(i+1)));
    }
    return dp[n][m][r][c]=mex(tmp);
}
void sg_value() {
    vector<int>nth_game;
    int ans=0;
    for (int i=0;i<m-1;i++) {
        nth_game.clear();
        if (r<i+1)
            nth_game.push_back(dfs(n, i+1, r, c));
        else
            nth_game.push_back(dfs(n, m-(i+1), r-(i+1), c));
        if (nth_game[0]==0) {
            cout<<"Gretel\n";
            return;
        }
    }
    for (int i=0;i<n-1;i++) {
        nth_game.clear();
        if (c<i+1)
            nth_game.push_back(dfs(i+1, m, r, c));
        else
            nth_game.push_back(dfs(n-(i+1), m, r, c-(i+1)));
        if (nth_game[0]==0) {
            cout<<"Gretel\n";
            return;
        }
    }
    cout<<"Hansel\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    memset(dp, -1, sizeof(dp));
    while (t--) {
        cin>>m>>n>>r>>c;

        sg_value();
    }
    return 0;
}
