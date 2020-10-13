#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
ll C[2000+1][2000+1],stir[2000+1][2000+1];
void init(){
	for(ll i=0;i<=2000;i++){
		C[i][0]=1;
		stir[i][0]=0;
	}
	stir[0][0]=1;
	//stir[i][j]=(i-1)*stir[i-1][j]+stir[i-1][j-1]
	for(ll i=1;i<=2000;i++){
		for(ll j=1;j<=i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
			stir[i][j]=((i-1)*stir[i-1][j]+stir[i-1][j-1])%mod;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t,n,f,b;
	init();
	cin>>t;
	while(t--){
		cin>>n>>f>>b;
		if(f+b<=2001)
			cout<<(stir[n-1][f-1+b-1]*C[f-1+b-1][f-1])%mod<<'\n';
		else
			cout<<0<<'\n';
	}
	return 0;
}
