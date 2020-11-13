#include<iostream>
using namespace std;
int main()
{
	int prime[50000];
	int tmp[33000];
	for(int i=0;i<50000;i++)
		prime[i]=2;
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i<50000;i++)
	{
		if(prime[i]==2)
		{
			prime[i]=1;
			for(int j=2;j*i<50000;j++)
				prime[i*j]=0;				
		}
	}
	/*
	for(int i=0;i<50000;i++)
		if(prime[i]==1)
			cout<<i<<' ';
	*/
	
	int aim;
	int count;
	while(cin>>aim&&aim!=0)
	{
		count=0;
		for(int i=0;i<33000;i++)
			tmp[i]=0;
		for(int i=2;i<aim;i++)
		{
			if(prime[i]==1&&prime[aim-i]==1&&tmp[i]!=1&&tmp[aim-i]!=1)
			{
				count++;
				tmp[i]=1;
				tmp[aim-i]=1;
			}
		}
		cout<<count<<'\n';
	}
	return 0;
} 
