#include <bits/stdc++.h>
using namespace std;
#define eps 1e-6
vector<int>arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n,x;
    int lp,rp,sum;
    bool flag;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n;
        arr.clear();
        arr.resize(2*n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
            arr[i+n]=arr[i];
        }
        for(int i=0;i<n;i++){
            cin>>x;
            arr[i+n]=arr[i]=arr[i]-x;
        }
        lp=0,rp=0,sum=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                lp=i;
                rp=i;
                sum=arr[i];
                break;
            }
        }
        if(sum==-1)
            lp=n;

        flag=0;
        while(lp<n){
            if(rp-lp==n-1){
                flag=1;
                break;
            }
            rp++;
            sum+=arr[rp];
            while(sum<0){
                sum-=arr[lp++];
            }
        }
        cout<<"Case "<<cas<<": ";
        if(!flag)
            cout<<"Not possible\n";
        else
            cout<<"Possible from station "<<lp+1<<'\n';
    }
    
    return 0;
}
