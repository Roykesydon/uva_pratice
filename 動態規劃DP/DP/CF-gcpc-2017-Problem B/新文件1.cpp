#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll q_pow(ll c,ll n)
{
	ll tmp=1;
	while(n)
	{
		if(n&1)
			tmp*=c;
		n>>=1;
		c*=c;
		c%=mod;
		tmp%=mod;
	}
	return tmp;
}
vector<ll>dp;
int main()
{
	ll n,m,c;
	ll w,ans=0;
	cin>>n>>m>>c;
	dp.resize(m+1);
	dp[0]=1;
	w = q_pow(c,n*n);
	//cerr<<"w= "<<w<<'\n';
	for(int i=1;i<=m;i++)
		dp[i]=(dp[i-1]*w)%mod;
	for(int i=1;i<=m;i++)
		for(int j=i*2;j<=m;j+=i)
			if(m%i==0)
			dp[j]=(dp[j]-dp[i]+mod)%mod;

	for(int i=1;i<=m;i++)
		if(m%i==0)
		{
			//cout<<"i= "<<i<<" q_pow(i,mod-2) % mod = "<<q_pow(i,mod-2)%mod<<'\n';
			ans=(ans+dp[i]*q_pow(i,mod-2))%mod;
		}

	cout<<ans<<'\n';	
	return 0;
}
