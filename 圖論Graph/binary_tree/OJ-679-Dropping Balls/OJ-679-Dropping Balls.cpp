#include<iostream>
using namespace std;
int main()
{
	int count;
	int deg,num;
	int sum;
	cin>>count;
	while(count--)
	{
		cin>>deg>>num;
		sum=1;
		for(int i=1;i<deg;i++)
		{
			if(num%2==0)
			{
				sum=2*sum+1;
				num=num/2;
			}
			else
			{
				sum*=2;
				num=num/2+1;
			}
		} 
		cout<<sum<<'\n';
	}
	cin>>count;	
	return 0;
} 
