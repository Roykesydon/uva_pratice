#include<iostream>
#include<iomanip> 
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n,r,tmp;
	int count;
	int num=1;
	int flag,s1p,s2p;
	string s1,s2;
	int DP[205][205];
	string start,end;
	string city[205];
	while(cin>>n>>r)
	{
		if(n==0&&r==0)
			break;
		if(n==0||r==0)
			continue;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				DP[i][j]=1e5;
		count=0;
		
		for(int i=0;i<r;i++)
		{
			cin>>s1>>s2>>tmp;
			//cout<<s1<<s2<<tmp;
			flag=0;
			for(int j=0;j<count;j++)
			{
				if(s1==city[j]&&s1.size()==city[j].size())
				{
					s1p=j;
					flag=1;
				}

			}
			if(!flag)
			{
				city[count++]=s1;
				s1p=count-1;				
			}
			
			flag=0;
			for(int j=0;j<count;j++)
			{
				if(s2==city[j]&&s2.size()==city[j].size())
				{
					s2p=j;
					flag=1;
				}
					
			}
			if(!flag)
			{
				city[count++]=s2;
				s2p=count-1;			
			}
			if(DP[s1p][s2p]<1e5&&DP[s1p][s2p]<tmp)
			{
				DP[s1p][s2p]=tmp;
				DP[s2p][s1p]=tmp;							
			}
			else if(DP[s1p][s2p]==1e5)
			{
				DP[s1p][s2p]=tmp;
				DP[s2p][s1p]=tmp;	
			}
	
		}		
		cin>>start>>end;
		for(int i=0;i<count;i++)
		{
			if(start==city[i]&&start.size()==city[i].size())
				s1p=i;
			if(end==city[i]&&end.size()==city[i].size())
				s2p=i;		
		}
		
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<DP[i][j]<<' ';
			cout<<endl;			
		}
		*/
		//------------------------- 
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<setw(6)<<DP[i][j]<<' ';
			cout<<endl;			
		}
		puts(""); 
		*/
		//------------------------ 
		
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(i!=j)
						if(DP[i][k]<1e5&&DP[k][j]<1e5&&DP[i][j]<1e5)
							DP[i][j]=max(min(DP[i][k],DP[k][j]),DP[i][j]);
						else if(DP[i][k]<1e5&&DP[k][j]<1e5&&DP[i][j]==1e5)
							DP[i][j]=min(DP[i][k],DP[k][j]);
						
						
		//------------------------- 
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<setw(4)<<DP[i][j]<<' ';
			cout<<endl;			
		}
		*/
		//------------------------ 

		cout<<"Scenario #"<<num++<<'\n';
		cout<<DP[s1p][s2p]<<" tons\n";
		cout<<'\n';		
	}
	
	return 0;
 } 
