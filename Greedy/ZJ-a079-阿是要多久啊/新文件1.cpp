#include<bits/stdc++.h>
using namespace std;

vector<int>vec;

class cmp
{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
priority_queue<int,vector<int>,cmp>pq;
int main()
{
    int n,m,maxd;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m)
    {
        vec.resize(n);
        for(int i=0;i<n;i++)
            cin>>vec[i];
        //sort(vec.begin(),vec.end(),cmp());
        for(int i=0;i<m;i++)
            pq.push(0);
        for(int i=0;i<n;i++)
        {
            auto u=pq.top();
            pq.pop();
            u+=vec[i];
            pq.push(u);
        }
        maxd=pq.top();
        while(!pq.empty())
        {
            if(pq.top()>maxd)
                maxd=pq.top();
            pq.pop();
        }
        cout<<maxd<<'\n';
        vec.clear();
    }
    return 0;
}
