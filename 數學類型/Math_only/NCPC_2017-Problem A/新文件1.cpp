#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll maxn;
void DFS(long long n,ll cnt)
{
	if(n==1)
	{
		cout<<cnt<<' '<<maxn<<'\n';
	}
	else
	{
		if(n&1)
		{
			if(3*n+1>maxn)
				maxn=3*n+1;
			DFS(3*n+1,cnt+1);
		}
		else
		{
			DFS(n/2,cnt+1);
		}	
		
	}
	
}
int main()
{
	ll n;
	while(cin>>n&&n)
	{
		cout<<n<<" ";
		maxn=n;
		if(n==1)maxn=4;
		if(n!=1)
			DFS(n,0);
		else
			DFS(4,1);
	}


	return 0;
}
