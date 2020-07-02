#include<iostream>
#include<vector>
using namespace std;
vector<int>vec[801];
bool vis[801];
int flag;
int y;

void DFS(int x)
{
	vis[x]=true;
	for(vector<int>::iterator i=vec[x].begin();i!=vec[x].end();i++)
	{
		if(*i==y)
		{
			flag=1;
			return;			
		}
		if(!vis[*i])
			DFS(*i);		
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	int x;
	while(cin>>n>>m)
	{
		flag=0;
		for(int i=0;i<=n;i++)
			vec[i].clear();
		for(int i=0;i<=n;i++)
			vis[i]=false;
		for(int i=0;i<m;i++)
		{
			cin>>x>>y;	
			vec[x].push_back(y);
		}
		cin>>x>>y;
		DFS(x);
		/*
		for(vector<int>::iterator i=vec[x].begin();i!=vec[x].end();i++)
			if(y==*i)
				flag=1;
		*/
		if(flag)
			cout<<"Yes!!!\n";
		else
			cout<<"No!!!\n";
			
	}	
	return 0;
}
