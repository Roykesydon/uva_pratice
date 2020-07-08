#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >vec;
class cmp
{
public:
    bool operator()(pair<int,int> a,pair<int,int>b)
    {
        if(a.second!=b.second)
            return a.second<b.second;
        return a.first<b.first;
    }
};
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,ans,time;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        vec.resize(n);
        for(int i=0;i<n;i++)
            cin>>vec[i].first>>vec[i].second;
        sort(vec.begin(),vec.end(),cmp());
        time=0;
        for(int i=0;i<n;i++)
        {
            if(vec[i].first>=time)
            {
                time=vec[i].second;
                ans++;
            }
        }
        cout<<ans<<'\n';



        vec.clear();
    }
    
    //system("PAUSE");
    return 0;
}
