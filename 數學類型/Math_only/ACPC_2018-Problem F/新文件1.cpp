#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    double n,k;
    freopen("fetiera.in","r",stdin);
    cin>>t;
    while(t--){
        cin>>n>>k;
        double sum=0,flipped,cur,ans=0;
        for(double i=0;i<n;i++)
            for(double j=0;j<n;j++)
                sum+=(n-i)*(n-j);
        
        for(double i=0;i<n;i++)
            for(double j=0;j<n;j++){
                flipped=(double)(n-i)*(n-j)*(i+1.0)*(j+1.0)/(double)sum;
                cin>>cur;
                for(double q=0;q<k;q++)
                    cur=cur*(1.0-flipped)+(1.0-cur)*flipped;
                ans+=cur;
            }
        cout<<fixed<<setprecision(5)<<ans<<'\n';
    }


    return 0;
}
