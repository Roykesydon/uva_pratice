#include<bits/stdc++.h>
using namespace std;
vector<vector<double>>c,p,dp,ddp;
vector<int>arr;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("trip.in","r",stdin);
    int t,n,m,k,q,z;
    double asum,bsum;
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>q>>z;
        c.clear();
        p.clear();
        c.resize(n);
        p.resize(n);
        arr.clear();
        arr.resize(k);
        for(int i=0;i<n;i++){
            c[i].resize(m);
            p[i].resize(n);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>p[i][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>c[i][j];
        for(int i=0;i<k;i++)
            cin>>arr[i];

        dp.clear();    
        dp.resize(k);
        for(int i=0;i<k;i++)
            dp[i].resize(n,0.0);

        ddp.clear();    
        ddp.resize(k);
        for(int i=0;i<k;i++)
            ddp[i].resize(n,0.0); 
        
        dp[0][0]=c[0][arr[0]];

        for(int i=1;i<k;i++){
            for(int j=0;j<n;j++)
                for(int g=0;g<n;g++){
                    dp[i][j]+=dp[i-1][g]*p[g][j]*c[j][arr[i]];
                    ddp[i][j]+=ddp[i-1][g]*p[g][j]*c[j][arr[i]];
                }
            if(i==q)
                ddp[i][z]=dp[i][z];
        }

        // cerr<<"//----------------\n";
        // for(int i=0;i<k;i++){
        //     for(int j=0;j<n;j++){
        //         cerr<<fixed<<setprecision(2)<<dp[i][j]<<' ';
        //     }
        //     cerr<<'\n';
        // }
        // cerr<<"//-----------------\n";

        asum=0,bsum=0;
        for(int i=0;i<n;i++){
            asum+=ddp[k-1][i];
            bsum+=dp[k-1][i];
        }

        cout<<fixed<<setprecision(3)<<asum/bsum<<'\n';

        
    }

    return 0;
}
