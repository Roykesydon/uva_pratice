#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x&-x)

bool cmp(pair<int,int> a,pair<int,int>b){
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second;
}

vector<pair<int,int>>arr;
map<pair<int,int>,ll>mp,mp2;
vector<ll>id,bit;

ll query(int index){
    ll tmp=0;
    while(index){
        tmp=max(tmp,bit[index]);
        index-=lowbit(index);
    }
    return tmp;
}
void update(int index,ll val){
    while(index<bit.size()){
        bit[index] = max(bit[index],val);
        index+=lowbit(index);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int a,b,c;

    cin>>n;
    arr.push_back({-1,-1});
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(!mp.count({a,b})){
            mp[{a,b}]=c;
            arr.push_back({a,b});
            id.push_back(a);
            id.push_back(b);
        }
        else{
            mp[{a,b}]+=c;
        }
    }
    sort(id.begin(),id.end());
    id.resize(unique(id.begin(),id.end())-id.begin());
    n=arr.size()-1;
    bit.resize(id.size()+1,0);
    for(int i=1;i<=n;i++){
        int tmpa=arr[i].first;
        int tmpb=arr[i].second;
        arr[i].first=lower_bound(id.begin(),id.end(),arr[i].first)-id.begin()+1;
        arr[i].second=lower_bound(id.begin(),id.end(),arr[i].second)-id.begin()+1;
        mp2[{arr[i].first,arr[i].second}]=mp[{tmpa,tmpb}];
    }
    sort(arr.begin(),arr.end(),cmp);
    // for(auto i:arr){
    //     cerr<<i.first<<" "<<i.second<<" | "<<mp2[{i.first,i.second}]<<'\n';
    // }
    for(int i=1;i<=n;i++){
        ll tmp=0;
        // cerr<<"i= "<<i<<'\n';
        if(arr[i].second-1>0)
            tmp=query(arr[i].second-1);
        // cerr<<"query complete\n";
        update(arr[i].second,tmp+mp2[{arr[i].first,arr[i].second}]);
        // cerr<<"update complete\n";
        // cerr<<"query("<<arr[i].second<<")= "<<query(arr[i].second)<<'\n';
    }
    cout<<query(bit.size()-1)<<'\n';
    return 0;
}
