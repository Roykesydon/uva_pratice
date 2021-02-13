#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>>arr;
int n,m;
struct node{
    bool flag;
    int ind1;
    int ind2;
    node(){
        flag=false;
        ind1=-1;
        ind2=-1;
    }
};
void print_mask(int x){
    string str="";
    for(int i=0;i<m;i++)
    {
        if(x&1)str="1"+str;
        else str="0"+str;
    }
    cout<<str<<'\n';
}
node check(int mid){
    node tmp;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int mask=0;
        for(int j=0;j<m;j++){
            mask<<=1;
            if(arr[i][j]>=mid)
                mask|=1;
        }
        mp[mask]=i;
        for(int j=0;j<1<<m;j++)
            if(((j|mask)==(1<<m)-1)&&mp.count(j)){
                tmp.flag=true;
                tmp.ind1=i;
                tmp.ind2=mp[j];
                return tmp;
            }
    }
    return tmp; 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans1,ans2;
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<n;i++)
        arr[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    int l=0,r=1e9;
    while(l<=r){
        int mid=(l+r+1)/2;
        node result=check(mid);
        // cout<<"l= "<<l<<" mid= "<<mid<<" r= "<<r<<'\n';
        if(result.flag)
            l=mid,ans1=result.ind1,ans2=result.ind2;
        else{
            r=mid-1;
            continue;
        }
        if(l==r)
            break;
    }
    // cout<<l<<'\n';
    cout<<ans1+1<<" "<<ans2+1<<'\n';
    return 0;
}

