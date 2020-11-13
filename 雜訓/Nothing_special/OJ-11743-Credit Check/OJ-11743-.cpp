#include<iostream>
#include<string>
using namespace std;
int main()
{
	int num[8];
	int num2[8];
	int count;
	int j;
	int sum;
	cin>>count;
	string s;
	while(count--)
	{
		sum=0;
		j=0;
		for(int i=0;i<4;i++)
		{
			cin>>s;
			num2[j]=s[1]-'0';
			num[j++]=s[0]-'0';
			num2[j]=s[3]-'0';
			num[j++]=s[2]-'0';
		}
		/*
		for(int i=0;i<8;i++)
			cout<<num[i]<<' ';
		cout<<'\n';
		*/
		for(int i=0;i<8;i++)
		{
			num[i]*=2;
			sum+=num[i]/10;
			sum+=num[i]%10;	
			sum+=num2[i];		
		}
		/*
		for(int i=0;i<8;i++)
			cout<<num[i]<<' ';
		cout<<'\n';
		*/
	//	cout<<sum;
		if(sum%10!=0)
			cout<<"Invalid\n";
		else
			cout<<"Valid\n";

		
	}
	
	return 0;
}
