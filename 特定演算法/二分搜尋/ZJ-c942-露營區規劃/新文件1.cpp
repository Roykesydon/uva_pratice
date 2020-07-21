#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1);

vector<double>cir;
bool check(double mid,int m)
{
    int sum=0;
    for(int i=0;i<cir.size();i++)
        sum+=int(cir[i]/mid);
    return sum>=m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    double tmp;
    double l,r,mid,mind;
    while(cin>>n>>m&&n&&m)
    {
        cir.resize(n);
        mind=1e18;
        for(int i=0;i<n;i++)
        {
            cin>>tmp;
            cir[i]=tmp*2*PI;
            mind=min(mind,cir[i]);
        }
        l=0;
        r=mind;
        while(!(l-r<0.000001&&l-r>-0.000001))
        {
            mid=(l+r)/2;
            //cout<<"mid= "<<mid<<endl;
            if(check(mid,m))
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        mid=(l+r)/2;
        cout<<(int)(cir[0]/mid);
        for(int i=1;i<n;i++)
            cout<<" "<<(int)(cir[i]/mid+0.000001);
        cout<<'\n';

        cir.clear();
    }

    return 0;
}
