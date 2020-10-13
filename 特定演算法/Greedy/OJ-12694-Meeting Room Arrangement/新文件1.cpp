#include<iostream>
using namespace std;
struct event
{
	int start;
	int end;
};
int main()
{
	event e[20];
	int casecount;
	int tmp;
	int time;
	int ans;
	int min;
	int minp;
	int find;
	int i,j;
	cin>>casecount;
	while(casecount--)
	{
		tmp=0;
		while(cin>>i>>j&&(i!=0||j!=0))
		{
			e[tmp].start=i;
			e[tmp++].end=j;
		}
		ans=0;
		time=0;
		while(1)
		{
			find=0;
			min=10;
			for(int i=0;i<tmp;i++)		
			{
				if(e[i].start>=time&&e[i].end<=min)		//在可選的選項中找最早結束的 
				{
					minp=i;
					min=e[i].end;
					find=1;
				}
			}
			if(find==1)
			{
				time=min;
				ans++;
			}
			
			
			if(find==0)
				break;
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
 } 
