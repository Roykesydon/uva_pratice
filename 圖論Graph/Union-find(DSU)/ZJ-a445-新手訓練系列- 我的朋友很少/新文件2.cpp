#include<iostream>
#include<vector>
using namespace std;

int f[10001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
int merge(int x,int y)
{
	f[x]=find(y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m,q;
	int x,y;
	while(cin>>n>>m>>q)
	{
		//cout<<n<<' '<<m<<' '<<q<<endl;
		for(int i=1;i<=n;i++)
			f[i]=i;
			
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			//cout<<x<<y;
			x=find(x);
			y=find(y);
			if(x!=y)
			{
				merge(x,y);
			}
			/*
			for(int i=1;i<=n;i++)
				cout<<f[i]<<' ';
			cout<<endl;
			*/
		}
		//cout<<"yes\n";
		for(int i=0;i<q;i++)
		{
			cin>>x>>y;
			
			if(find(x)==find(y))
				cout<<":)\n";
			else
				cout<<":(\n";
		}

	}
	
	
	return 0;
}
