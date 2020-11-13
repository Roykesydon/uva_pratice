#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	char s1[1000+1];
	int sodd,seven;
	int flag;
	while(cin>>s1&&atoi(s1)!=0)
	{
		sodd=0;
		seven=0;
		for(int i=0;i<strlen(s1);i++)
		{
			if(i%2==1)
				seven+=(s1[i]-'0');
			else
				sodd+=(s1[i]-'0');		
		}
		flag=0;
		if(sodd>seven)
		{
			if((sodd-seven)%11==0)
				flag=1;			
		}
		else
			if((seven-sodd)%11==0)
				flag=1;
				
		if(flag)
			cout<<s1<<" is a multiple of 11.\n";
		else
			cout<<s1<<" is not a multiple of 11.\n";

		
	}
	
	return 0;
}
 
