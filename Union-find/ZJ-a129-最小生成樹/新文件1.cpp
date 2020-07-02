#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int f[100001];
class node
{
	public:
		int u,v,w;
		friend bool operator<(node a,node b)
		{
			return a.w<b.w;	
		}	
};
vector <node>edge;
//node edge[200001];
int find(int x)
{
	if(f[x]==x)
		return x;
	else
		return f[x]=find(f[x]);
}
void merge(int x,int y)
{
	f[x]=find(y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	int flag;
	long long ans;
	int x,y,z,tmp;
	while(cin>>n>>m)
	{
		ans=0;
		edge.resize(m);
		for(int i=0;i<n;i++)
			f[i]=i;
		/*
			cout<<endl;
			for(int i=0;i<n;i++)
				cout<<f[i]<<' ';
			cout<<endl;
			cout<<"------------------------\n";
		*/	
			
		for(int i=0;i<m;i++)
		{
			cin>>x>>y>>z;
			edge[i].u=x;
			edge[i].v=y;
			edge[i].w=z;
		}
		sort(edge.begin(),edge.end());
			
			for(int i=0;i<m;i++)
			{
					if(find(edge[i].u)!=find(edge[i].v))
					{
						merge(find(edge[i].u),find(edge[i].v));
						ans+=edge[i].w;
					}
					
		
				/*
				cout<<endl;
				for(int j=0;j<n;j++)
					cout<<f[j]<<' ';
				cout<<endl;
			*/
			}
			/*
			cout<<endl;
			for(int i=0;i<n;i++)
				cout<<f[i]<<' ';
			cout<<endl;
			*/
			
		flag=0;
		tmp=find(0);
		for(int i=1;i<n;i++)
			if(find(i)!=tmp)
				flag=1;
		if(!flag)
			cout<<ans<<'\n';
		else
			cout<<-1<<'\n';
		edge.clear();

	}
	
	
	return 0;
}
