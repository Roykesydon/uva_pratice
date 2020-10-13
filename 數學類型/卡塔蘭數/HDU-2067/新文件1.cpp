#include<bits/stdc++.h>
using namespace std;
#define MAXN 35
#define ll long long
ll cata[MAXN+1];
inline void init(){
    cata[0]=1;
    cata[1]=1;
    for(ll i=2;i<=MAXN;i++)
        for(ll j=0;j<=i-1;j++)
            cata[i]+=cata[j]*cata[i-1-j];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,cas=1;
    init();
    while(cin>>n&&n!=-1)
        cout<<cas++<<' '<<n<<' '<<cata[n]*2<<'\n';
    return 0;
}//
