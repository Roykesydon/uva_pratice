#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps (1e-6)
struct cmp{
    bool operator()(pair<int,int>a,pair<int,int>b){
        if(a.second!=b.second)
            return a.second<b.second;
        return a.first<b.first;
    }
};
vector<pair<int,int> > arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,ans=0,t;
    while(cin>>n&&n){
        arr.clear();
        arr.resize(n);
        ans=0;t=-1;
        for(int i=0;i<n;i++)
            cin>>arr[i].first>>arr[i].second;
        sort(arr.begin(),arr.end(),cmp());

        // cout<<'\n';
        // for(int i=0;i<n;i++)
        //     cout<<arr[i].first<<' '<<arr[i].second<<'\n';
        // cout<<'\n';

        for(int i=0;i<n;i++){
            if(arr[i].first>=t){
                ans++;
                t=arr[i].second;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}
             
