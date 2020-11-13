#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 2001
#define mod 1000;
ll int stir[MAXN][MAXN],bell[MAXN];
void init(){
	for(int i=0;i<MAXN;i++)
		stir[i][i]=1;
	for(int i=1;i<MAXN;i++)
		for(int j=1;j<i;j++)
			stir[i][j]=(j*stir[i-1][j]+stir[i-1][j-1])%mod;
	bell[0]=1;
	for(int i=1;i<MAXN;i++)
		for(int j=0;j<=i;j++)
			bell[i]=(bell[i]+stir[i][j])%mod;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	ll t, x;
	cin >> t;
	while (t--)
	{
		cin>>x;
		cout<<bell[x] <<'\n';
	}
	return 0;
}
