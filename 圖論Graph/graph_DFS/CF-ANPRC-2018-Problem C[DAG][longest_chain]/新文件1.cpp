#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<bool>vis;
vector<int>dis;
vector<vector<int>>edge;
int dfs(int x){
    if(vis[x])return dis[x];
    vis[x]=1;
    for(auto i:edge[x]){
        dis[x]=max(dis[x],dfs(i)+1);
    }
    return dis[x];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w, maxn,tmpmax,tmpmaxp;
    cin >> n >> w;
    arr.resize(n);
    edge.resize(n);
    dis.resize(n,0);
    vis.resize(n,0);
    tmpmax=0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i=0;i<n;i++){
        for(int j=i-w;j<=i+w;j++)
        {
            if(j==i||j<0||j>=n) continue;
            if(arr[j]<arr[i]){
                edge[i].push_back(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(vis[i])continue;
            dfs(i);
    }
    maxn = 0;
    for (int i = 0; i < n; i++)
        maxn = max(maxn, dis[i]);
    cout << maxn << '\n';
    return 0;
}
