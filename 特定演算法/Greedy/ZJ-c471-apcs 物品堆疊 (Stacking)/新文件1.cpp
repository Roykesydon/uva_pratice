#include<bits/stdc++.h>
using namespace std;

class cmp
{
public:
    bool operator()(pair<long long,long long>a,pair<long long,long long>b)
    {
       return a.first*b.second<b.first*a.second;
    }
};
vector<pair<long long,long long> >vec;
int main()
{
    long long n,tmp,sum;
    while(cin>>n)
    {
        vec.resize(n);
        for(int i=0;i<n;i++)
            cin>>vec[i].first;
        for(int i=0;i<n;i++)
            cin>>vec[i].second;
        sort(vec.begin(),vec.end(),cmp());
        // for(auto i:vec)
        //     cout<<i.first<<' ';
        tmp=0;
        sum=0;
        for(int i=1;i<n;i++)
        {
            tmp+=vec[i-1].first;
            sum+=tmp*vec[i].second;
        }
        cout<<sum<<'\n';
        vec.clear();
    }

    return 0;
}
