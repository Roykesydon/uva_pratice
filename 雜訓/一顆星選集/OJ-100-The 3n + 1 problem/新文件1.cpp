#include<iostream>
using namespace std;
int main()
{
	long long int a,b;
	int check;
	long long int tmp;
	long long int len,max;
	while(cin>>a>>b)
	{
		check=0;
		if(a>b)
		{
			a=a+b;
			b=a-b;
			a=a-b;
			check=1;
		}
		max=0;
		for(int i=a;i<=b;i++)
		{
			tmp=i;
			len=0;
			while(true)
			{
				len++;
				if(tmp==1)
					break;
				else if(tmp%2==1)
					tmp=3*tmp+1;
				else
					tmp/=2;
			}
			if(len>max)
				max=len;
		}
		if(check==0)
			cout<<a<<' '<<b<<' '<< max<<'\n';
		else
			cout<<b<<' '<<a<<' '<< max<<'\n';	
	}
	
	return 0;
 } 
