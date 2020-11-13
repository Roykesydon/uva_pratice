#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	char s1[20],tmp[20];
	int len;
	int big;
	int j;
	int count=0;
	int state[5];
	while(cin>>s1)
	{
		for(int i=0;i<20;i++)
			tmp[i]=0;
		for(int i=0;i<5;i++)
			state[i]=0;
		big=0;
		
		
		printf("%4d.",++count);
		len=strlen(s1);
		if(len>9)
		{
			strncpy(tmp,s1,len-9);
			big=atoi(tmp);
			state[0]=big/100000;
			big=big-state[0]*100000;
			state[1]=big/1000;
			big=big-state[1]*1000;
			state[2]=big/10;
			big=big-state[2]*10;
			state[3]=big/1;
			big=big-state[3]*1;
			for(int i=0;i<4;i++)
			{
				if(state[i]!=0)
				{
					switch(i){
						
						case 0:
							cout<<' '<<state[i]<<' '<<"kuti";
							break;
						case 1:
							cout<<' '<<state[i]<<' '<<"lakh";
							break;
						case 2:
							cout<<' '<<state[i]<<' '<<"hajar";
							break;
						case 3:
							cout<<' '<<state[i]<<' '<<"shata";
							break;
					}				
				}
			}
			j=0;
			for(int i=len-9;i<len;i++)
				tmp[j++]=s1[i];
			tmp[10]='\0';
		}
		else
			strcpy(tmp,s1);
		
		big=atoi(tmp);
		if(big==0&&len<9)
			cout<<' '<<0;
		state[0]=big/10000000;
		big=big-state[0]*10000000;
		state[1]=big/100000;
		big=big-state[1]*100000;
		state[2]=big/1000;
		big=big-state[2]*1000;
		state[3]=big/100;
		big=big-state[3]*100;
		state[4]=big/1;
		if(len>9&&state[0]==0)
			cout<<' '<<"kuti";
		for(int i=0;i<5;i++)
		{
			if(state[i]!=0)
			{
				switch(i){
					
					case 0:
						cout<<' '<<state[i]<<' '<<"kuti";
						break;
					case 1:
						cout<<' '<<state[i]<<' '<<"lakh";
						break;
					case 2:
						cout<<' '<<state[i]<<' '<<"hajar";
						break;
					case 3:
						cout<<' '<<state[i]<<' '<<"shata";
						break;
					case 4:
						cout<<' '<<state[i];
						break;
				}				
			}				
		}
		puts("");
		
	}
	
	return 0;
}
