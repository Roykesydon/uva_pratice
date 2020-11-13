#include <bits/stdc++.h>
using namespace std;
#define MAXN (100)
int failure[MAXN];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,y,tmp;
	x=0,y=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		x+=tmp;
		cin>>tmp;
		y+=tmp;
	}
	cout<<min(x,n-x)+min(y,n-y)<<'\n';

	return 0;
}
