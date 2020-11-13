#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x&-x)
bool vis[100000+1];
ll bit[100000+1];
void update(ll ind,ll x){
    while(ind<=100000){
        bit[ind]+=x;
        ind+=lowbit(ind);
    }
}
ll query(ll ind){
    ll tmp=0;
    while(ind){
        tmp+=bit[ind];
        ind-=lowbit(ind);
    }
    return tmp;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);   
    ll n,x,ans=0;
    cin>>n;
    for(ll i=0;i<2*n;i++)
    {
        cin>>x;
        if(vis[x])
            ans+=query(x-1);
        else 
            ans-=query(x-1);
        update(x,1);
        vis[x]=1;
    }
    cout<<ans<<'\n';

    return 0;
}
