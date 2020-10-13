#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	string s1;
	int time[2];
	int ans[4];
	int a,b;
	int flag[60*24];
	double table[5][3]={{0.1,0.06,0.02},{0.25,0.15,0.05},{0.53,0.33,0.13},{0.87,0.47,0.17},{1.44,0.8,0.3}};
	int dot[5]={0,8*60,18*60,22*60,24*60};
	char con;
	while(cin>>con)
	{
		if(con=='#')
			break;
		cin>>s1;
		memset(ans,0,sizeof(ans));
		memset(flag,0,sizeof(flag));
		for(int i=0;i<2;i++)
		{
				cin>>a>>b;
				time[i]=60*a+b;
		}

		//cout<<time[0]<<' '<<time[1]<<endl;

		if(time[0]<time[1])
			for(int i=time[0];i<time[1];i++)
				flag[i]=1;
		else
		{
			for(int i=time[0];i<24*60;i++)
				flag[i]=1;
			for(int i=0;i<time[1];i++)
				flag[i]=1;
		}

		for(int i=0;i<4;i++)
		{
			for(int j=dot[i];j<dot[i+1];j++)
				ans[i]+=flag[j];
		}
		
		//cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<endl;
		cout<<setw(10)<<s1;
		ans[0]+=ans[3];
		for(int i=1;i<3;i++)
			cout<<setw(6)<<ans[i];
		cout<<setw(6)<<ans[0];
		cout<<setw(3)<<con;
		cout<<setw(8)<<fixed<<setprecision(2)<<ans[1]*table[con-'A'][0]+ans[2]*table[con-'A'][1]+ans[0]*table[con-'A'][2]<<endl;
	}
	return 0;
}
