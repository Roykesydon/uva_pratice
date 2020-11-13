#include<bits/stdc++.h>
using namespace std;

class book
{
public:
    int time1;
    int time2;
    int x;
};
class cmp
{
public:
    bool operator()(book a,book b)
    {
        /*
        if(a.x!=b.x)
            return a.x<b.x;
        else
        {
            if(!a.x)
            {
                return a.time1<b.time1;
            }
            else
            {
                return a.time2>b.time2;
            }
            
        }
        */
       return a.time2>b.time2;
    }
};
vector<book >vec;
int main()
{
    int n,x,y,ans,t1;
    while(cin>>n)
    {
        vec.resize(n);
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            vec[i].time1=x;
            vec[i].time2=y;
            if(x<y)
                vec[i].x=0;
            else
                vec[i].x=1; 
        }
        sort(vec.begin(),vec.end(),cmp());
        t1=0;
        ans=0;
        for(auto i:vec)
        {
            t1+=i.time1;
            ans=max(ans,t1+i.time2);
        }
        cout<<ans<<'\n';
        vec.clear();
    }       
   
    return 0;
}
