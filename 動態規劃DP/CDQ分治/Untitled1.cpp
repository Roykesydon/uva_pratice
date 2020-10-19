#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>arr;
ll tmp[1000000+1];
ll ans,t,n;
void cdq(ll l,ll r){
    if(l==r)
        return ;
    ll mid=(l+r)/2;
    // cout<<"l= "<<l<<" r= "<<r<<'\n';
    cdq(l,mid);
    cdq(mid+1,r);

    ll t1=l,t2=mid+1;
    // cout<<"left:\n";
    // for(int i=l;i<=mid;i++)
    //     cout<<arr[i]<<' ';
    // cout<<"\n";
    // cout<<"right:\n";
    // for(int i=mid+1;i<=r;i++)
    //     cout<<arr[i]<<' ';
    // cout<<"\n";
    for(int i=l;i<=r;i++){
        if(t2<=r&&arr[t1]>arr[t2]||t1>mid){
            tmp[i]=arr[t2++];
            if(t1<=mid){
                ans+=mid-t1+1;
                // cout<<"ans= "<<ans<<'\n';
            }
        }
        else{
            tmp[i]=arr[t1++];
        }
    }
    for(int i=l;i<=r;i++)
        arr[i]=tmp[i];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);   
    cin>>t;
    while(t--){
        cin>>n;
        arr.clear();
        arr.resize(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ans=0;
        cdq(0,n-1);
        cout<<ans<<'\n';
        // cout<<"//-------------\n";
    }
    return 0;
}
//g++ -std=c++14 test.cpp
