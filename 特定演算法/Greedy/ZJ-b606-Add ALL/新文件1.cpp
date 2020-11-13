#include<bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(int a,int b){return a>b;}
};
priority_queue<int,vector<int>,cmp>pq;
int main()
{
    int n,tmp,ans,x,y;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            pq.push(tmp);
        }
        ans=0;
        while(pq.size()>=2)
        {
            x=pq.top();
            pq.pop();
            y=pq.top();
            pq.pop();
            x+=y;
            pq.push(x);
            ans+=x;
        }
        cout<<ans<<'\n';
        while(!pq.empty())
            pq.pop();
    }

    return 0;
}
