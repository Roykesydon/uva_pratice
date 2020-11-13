#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
vector<ll>f;
inline ll qpow(ll a,ll b)
{
	ll tmp=1;
	while(b)
	{
		if(b&1)
			tmp*=a;
		a*=a;
		a%=mod;
		tmp%=mod;
		b>>=1;
	}
	return tmp%mod;
}
inline ll combination(ll a,ll b)
{
	return ((f[a]*qpow(f[b],mod-2)%mod)*(qpow(f[a-b],mod-2)%mod))%mod;
}
int main()
{
	int n,k,whatever;
	bool flag=1;
	ll ans=0;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
		cin>>whatever;
	f.resize(n+1);
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]*i%mod;
	for(int i=k;i>=2;i--,flag=!flag)
	{
		if(flag)ans+=combination(k,i)*i%mod*qpow(i-1,n-1)%mod;
		else ans=ans-combination(k,i)*i%mod*qpow(i-1,n-1)%mod+mod;
		ans%=mod;
	}
	cout<<ans<<'\n';
	return 0;
}
