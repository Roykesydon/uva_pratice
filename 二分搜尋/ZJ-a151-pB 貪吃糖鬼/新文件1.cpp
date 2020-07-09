#include<bits/stdc++.h>
using namespace std;
bool check(long long mid,long long &n)
{
    long long tmp=n,k=0;
    while(tmp>0)
    {
        if(tmp<mid)
        {
            k+=tmp;
            break;
        }
        tmp-=mid;
        k+=mid;
        if(tmp<=tmp/10)
        {
            break;
        }
        tmp-=tmp/10;
    }
    if(k>n/2)
        return true;
    return false;
}
int main()
{
    long long  n,k,l,r,mid;
    while(cin>>n)
    {
        l=1;
        r=n;
        while(l<=r)
        {
            mid =(l+r)/2;
            //cout<<"mid= "<<mid<<endl;
            if(l==r)
                break;
            if(check(mid,n))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<mid<<'\n';
    }


    return 0;
}
