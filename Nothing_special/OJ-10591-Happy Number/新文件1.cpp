#include<iostream>
using namespace std;

int tmp[1000000];
int sos(int aim)
{
	int sum=0;
	while(aim>0)
	{
		sum+=(aim%10)*(aim%10);
		aim=aim/10;
	}
	return sum;
}
int main()
{
	int aim;
	int origin;
	int testnum;
	int tmpcount;
	int count=0;
	bool check=true;
	cin>>testnum;
	while(count++<testnum)
	{
		for(int i=0;i<1000;i++)
			tmp[i]=0;
		check =true;
		cin>>aim;
		origin=aim;
		tmpcount=0;
		while(aim!=1)
		{
			if(aim!=origin)
				tmp[aim]=1;
			aim=sos(aim);
			//cout<<aim<<' ';
			if(origin==aim||tmp[aim]==1)
			{
				check=false;
				break;
			}
			
		}

		if(check)
			cout<<"Case #"<<count<<": "<<origin<<" is a Happy number.\n";
		else
			cout<<"Case #"<<count<<": "<<origin<<" is an Unhappy number.\n";
	}
	
	return 0;
}
