#include<bits/stdc++.h>
using namespace std;
class bun{
public:
    int bcost;
    int scost;
    int price;
};
vector<bun>item;
vector<pair<int,int>>arr;
vector<int>stuff;
vector<int>dp;
int main(){
    int n,m,dough,maxn;
    cin>>n>>m;
    item.resize(m+1);
    stuff.resize(m+1,0);
    item[0].scost=0;
    cin>>item[0].bcost>>item[0].price;
    stuff[0]=0;
    for(int i=1;i<=m;i++)
        cin>>stuff[i]>>item[i].scost>>item[i].bcost>>item[i].price;
    for(int i=0;i<=m;i++){
        for(int j=1;;j++){
            if(item[i].scost*j>stuff[i]||item[i].bcost*j>n){
                break;
            }
            arr.push_back({item[i].bcost,item[i].price});
        }
    }
    dp.resize(n+1,0);
    for(int i=0;i<arr.size();i++){
        for(int j=n;j>=arr[i].first;j--){
            dp[j]=max(dp[j],dp[j-arr[i].first]+arr[i].second);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
