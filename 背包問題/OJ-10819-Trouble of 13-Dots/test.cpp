#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int w[101];
int v[101];
int dp[101][10201];
int main()
{
	int origin,tmp_weight;
	int weight,num;
	int i,j;
	int ans;
	while(cin>>weight>>num)
	{
		if(weight>1800)
			weight+=200;
		//--------------
		for(int i=1;i<=num;i++)
			cin>>w[i]>>v[i];	
		for(int j=0;j<=weight;j++)
			dp[0][j]=0;	
		//---------------------
		/*有夠麻煩，簡單來說就是只考慮塞滿的情況，我就可以直接指定花費查詢範圍
		這dp定義比較特別，最後再從所有可能花費的價格中撈最大值(其他的保持0)*/


		for(int i=1;i<=num;i++)		
			for(int j=0;j<=weight;j++)
				if(w[i]<=j)
				{
					if(w[i]==j||dp[i-1][j-w[i]]>0)
						dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
					else
						dp[i][j]=dp[i-1][j];
				}
				else
					dp[i][j]=dp[i-1][j];

		
		//-----------
		/*
		for(int i=0;i<=num;i++)
		{
			for(int j=0;j<=weight;j++)
				cout<<dp[i][j]<<' ';
			cout<<endl;
		}
		*/
		//--------

		if(weight<=1800) //0~1800
			origin=weight;
		else if(weight>2200)	//2001~
			origin=2000;		//1. <=1800，不用考慮
		else if(weight>2000)	//1801~2000
			origin=weight-200;	//2.	>2000，不考慮
								//3.1801~2000==origin 0~origin 2001~origin+200  
		ans=0;
		for(int i=0;i<=origin;i++)
			ans=max(ans,dp[num][i]);
		for(int i=2001;i<=weight;i++)
			ans=max(ans,dp[num][i]);
		cout<<ans<<endl;
	
	}			

	return 0;
}