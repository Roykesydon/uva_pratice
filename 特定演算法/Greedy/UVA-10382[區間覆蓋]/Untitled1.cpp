#include<bits/stdc++.h>
using namespace std;
#define eps 1e-6
#define ll long long
vector<pair<double,double>>arr;
struct cmp{
    bool operator()(pair<double,double> a,pair<double,double> b){
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second<b.second;
    }
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,ans;
    long double l,w;
    long double p,r;
    while(cin>>n>>l>>w){
        priority_queue<long double>pq;
        long double cur=0.0;
        bool flag=0;
        ans=0;
        arr.clear();
        w/=2.0;
        for(ll i=0;i<n;i++){
            cin>>p>>r;
            if(r<w||abs(r-w)<eps)
                continue;
            long double tmp=sqrt(r*r-w*w);
            arr.push_back({p-tmp,p+tmp});
        }
        sort(arr.begin(),arr.end(),cmp());

        arr.push_back({1e18,-1e18});
        for(ll i=0;i<arr.size();i++){
            if(arr[i].first<cur||abs(arr[i].first-cur)<eps)
                pq.push(arr[i].second);
            else{
                if(pq.empty()||(pq.top()<arr[i].first&&i!=arr.size()-1))
                    break;
                auto u=pq.top();
                pq.pop();
                pq.push(arr[i].second);
                cur=u;
                ans++;
            }
            if(cur>l||abs(cur-l)<eps){
                flag=1;
                break;
            }
        }
        if(flag)
            cout<<ans<<'\n';
        else
            cout<<"-1\n";
    }

    return 0;
}
