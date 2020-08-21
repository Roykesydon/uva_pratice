#include<bits/stdc++.h>
#define ll long long
#define MAXN 30
using namespace std;
ll cata[MAXN+1];
void init(){
    cata[0]=1;
    cata[1]=1;
    for(ll i=2;i<=MAXN;i++)
        for(ll j=0;j<=i-1;j++)
            cata[i]+=cata[i-1-j]*cata[j];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    init();
    while(cin>>n&&n)
        cout<<cata[n]<<'\n';
    return 0;
}//
