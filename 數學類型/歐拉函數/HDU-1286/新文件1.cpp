#include<bits/stdc++.h>
using namespace std;
int phi[32768+1];
void init(){
    for(int i=0;i<=32768;i++)
        phi[i]=i;
    phi[1]=1;
    for(int i=2;i<=32768;i++){
        if(phi[i]==i){
            phi[i]=phi[i]*(i-1)/i;
            for(int j=i+i;j<=32768;j+=i){
                phi[j]=phi[j]*(i-1)/i;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,x;
    init();
    cin>>t;
    while(t--){
        cin>>x;
        cout<<phi[x]<<'\n';
    }
    return 0;
}

