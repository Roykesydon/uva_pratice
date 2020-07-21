#include<iostream>
#include<string>
using namespace std;

int lowbit(int i)
{
	return i&(-i);
}
void update(int x,int*a,int num,int count)
{
	while(x<=count)
	{
		a[x]+=num;
		x+=lowbit(x);
	}
}
int sum(int x,int *a)
{
	int sum=0; //注意x可能為0
	while(x>=1)
	{
		sum+=a[x];
		x-=lowbit(x);
	} 
	return sum;
}
int main()
{
	int a[200000+1];
	int origin[200000+1];
	int ohm;
	int newohm;
	int turn=0;
	int tmp;
	int x,y;
	int count;
	string s1;
	while(cin>>count&&count!=0)
	{
		if(++turn>1)
			cout<<'\n';
		cout<<"Case "<<turn<<":\n";
			for(int i=1;i<=count;i++)
			{
				a[i]=0;
				origin[i]=0;				
			}
			for(int i=1;i<=count;i++)
			{
				cin>>ohm;
				origin[i]=ohm;
				update(i,a,ohm,count);
			}
			//cout<<a[1]<<a[2]<<a[3];
			while(cin>>s1)
			{
				if(s1[0]=='M')
				{
					cin>>x>>y;
					cout<<sum(y,a)-sum(x-1,a)<<'\n';
				}
				else if(s1[0]=='S')
				{
					cin>>x>>newohm;
					tmp=newohm-origin[x];
					origin[x]=newohm;
					update(x,a,tmp,count);
				}
				else
					break;				
			}

	}
	
	return 0;
}
