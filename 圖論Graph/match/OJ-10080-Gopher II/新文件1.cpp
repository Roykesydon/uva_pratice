//     ____              __                       __               
//    / __ \____  __  __/ /_____  _______  ______/ /___  ____  ___ 
//   / /_/ / __ \/ / / / //_/ _ \/ ___/ / / / __  / __ \/ __ \/ _ \
//  / _, _/ /_/ / /_/ / ,< /  __(__  ) /_/ / /_/ / /_/ / / / /  __/
// /_/ |_|\____/\__, /_/|_|\___/____/\__, /\__,_/\____/_/ /_/\___/ 
//             /____/               /____/                         
#include<bits/stdc++.h>
using namespace std;
vector<int>match;
vector<bool>check;
vector<vector<int> >edge;
vector<pair<double,double> >point;
double dis(pair<double,double>a,pair<double,double> b)
{
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
bool dfs(int u)
{
	for(auto j:edge[u])
	{
		if(!check[j])
		{
			check[j]=true;
			if(match[j]==-1||dfs(match[j]))
			{
				match[u]=j;
				match[j]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int ans=0;;
	int n,m;
	double s,v;
	while(cin>>n>>m>>s>>v)
	{
		edge.resize(n+m+1);
		point.resize(n+m+1);
		check.resize(m+n+1);
		match.resize(m+n+1,-1);
		for(int i=1;i<=n;i++)
			cin>>point[i].first>>point[i].second;
		for(int i=n+1;i<=n+m;i++)
			cin>>point[i].first>>point[i].second;//其實可以寫一起...
		for(int i=1;i<=n;i++)
		{
			for(int j=n+1;j<=n+m;j++)
			{
				if(dis(point[i],point[j])/v<=s)
				{
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		// for(int i=1;i<=n+m;i++)
		// {
		// 	cerr<<"i= "<<i<<" : ";
		// 	for(auto j:edge[i])
		// 		cerr<<j<<' ';
		// 	cerr<<'\n';
		// }
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(match[i]==-1)
			{
				check.assign(check.size(),false);
				if(dfs(i))
					ans++;
			}
		}
		cout<<n-ans<<'\n';

		match.clear();
		check.clear();
		edge.clear();
		point.clear();
	}
}
