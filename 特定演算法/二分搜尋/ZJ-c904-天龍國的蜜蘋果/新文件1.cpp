#include<bits/stdc++.h>
using namespace std;
class cmp
{
public:
    bool operator()(double a,double b)
    {
        return a>b;
    }
};
vector<pair<int,int> >apple;
vector<double>tmp;
bool check(double mid,int k)
{
    //w v打反了 自己注意一下
    //(w1+w2+w3)/(v1+v2+v3)>=mid;
    //(w1+w2+w3)-mid*(v1+v2+v3)>=0;
    for(int i=0;i<tmp.size();i++)
        tmp[i]=apple[i].second-apple[i].first*mid;
    sort(tmp.begin(),tmp.end(),cmp());
    double sum=0.0;
    for(int i=0;i<k;i++)
    {
        sum+=tmp[i];
    }
    return sum>=0.0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    double l,r;
    while(cin>>n>>m)
    {
        apple.resize(n);
        tmp.resize(n);
        for(int i=0;i<n;i++)
            cin>>apple[i].first>>apple[i].second;
        for(int i=0;i<m;i++)
        {
            l=0;
            r=1e18;
            cin>>k;
            double mid;
            while(l<r)
            {
                mid=(l+r)/2;
                //cout<<"mid= "<<mid<<endl;
                if(check(mid,k))
                {
                    l=mid;
                }
                else
                {
                    r=mid;
                }
                if(l-r>-0.000001&&l-r<0.000001)
                    break;
            }
            cout<<fixed<<setprecision(2)<<mid<<'\n';
        }
        apple.clear();
    }

    return 0;
}
