#include<bits/stdc++.h>
using namespace std;
#define ld long double
int main()
{  
    int a,b;
    ld ans;
    while(cin>>a>>b&&a&&b){
        ans=0;
        for(int i=a;i<=b;i++)
            ans+=pow((ld)i,-2.0/3.0);
        ans*=1.0/3.0*1e-15;
        cout<<scientific<<setprecision(5)<<uppercase<<ans<<'\n';
    }
    return 0;   
}
/*
1 100
10000 20000
0 0
*/

