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
class cmp2
{
public:
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return a.first<b.first; 
    }
};
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp2 >pq;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t,n,ans,time;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vec.resize(n);
        for(int i=0;i<n;i++)
            cin>>vec[i].first>>vec[i].second;
        sort(vec.begin(),vec.end(),cmp());
        //ans=0;
        time=0;
        for(int i=0;i<n;i++)
        {
            pq.push(vec[i]);
            time+=vec[i].first;
            //ans++;
            if(time>vec[i].second)
            {
                auto u=pq.top();
                pq.pop();
                time-=u.first;
                // ans--;
            }
        }

        cout<<pq.size()<<'\n';

        
        // cout<<endl;
        // while(!pq.empty())
        // {
        //     cout<<pq.top().first<<','<<pq.top().second<<" || ";
        //     pq.pop();
        // }
        // cout<<endl;


        while(!pq.empty())
            pq.pop();
        vec.clear();
    }
    
    //system("PAUSE");
    return 0;
}
