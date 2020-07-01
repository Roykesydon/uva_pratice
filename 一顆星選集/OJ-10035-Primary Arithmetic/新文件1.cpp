#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int carry;
	int s1n,s2n;
	int sum;
	int num1,num2;
	int i1[10],i2[10];
	string s1,s2;
	while(cin>>s1>>s2)
	{
		if(*s1.c_str()=='0'&&*s2.c_str()=='0')
			break;
		s1n=strlen(s1.c_str())-1;
		s2n=strlen(s2.c_str())-1;
		for(int i=0;i<10;i++)
		{
			if(s1n>=0)
			{
				i1[i]=*(s1.c_str()+s1n)-'0';
				s1n--;			
			}
			else
				i1[i]=0;
				
			if(s2n>=0)
			{
				i2[i]=*(s2.c_str()+s2n)-'0';
				s2n--;			
			}
			else
				i2[i]=0;
			
		}
		sum=0;
		carry=0;
		for(int i=0;i<10;i++)
		{
			if(i1[i]+i2[i]+carry>=10)
			{
				sum+=1;
				carry=1;
			}
			else
			{
				carry=0;
			}
		}
		
		if(sum==0)
			cout<<"No carry operation.\n";
		else if(sum==1)
			cout<<sum<<" carry operation.\n";
		else
			cout<<sum<<" carry operations.\n";

		//------------------------
		/*
		for(int i=0;i<10;i++)
			cout<<i1[i]<<' ';
		puts("");
		for(int i=0;i<10;i++)
			cout<<i2[i]<<' ';
		*/
		//--------------------------
			
	}
	
	return 0;
 } 
