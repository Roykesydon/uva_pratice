#include<iostream>
using namespace std;
int main()
{
	int count;
	int len[4002],train[4002];
	int n,tmp;
	int ans;
	cin>>count;
	while(count--)
	{
		cin>>n;
		for(int i=0;i<4002;i++)
		{
			len[i]=1;
			train[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			train[n-1-i]=tmp;
			train[n-1+i]=tmp;
		}

		
		for(int i=0;i<2*n-1;i++)
			for(int j=i+1;j<2*n-1;j++)
				if(train[j]>train[i])
					if(len[i]+1>len[j])
						len[j]=len[i]+1;
		
		ans=0;
		for(int i=0;i<2*n-1;i++)
			if(len[i]>ans)
				ans=len[i];
		
		cout<<ans<<endl;	
			
	} 
	return 0;	
} 
