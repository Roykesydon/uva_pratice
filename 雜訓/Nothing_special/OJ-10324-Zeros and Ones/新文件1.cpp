#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int count=1;
	int tmp;
	int x;
	int a,b;
	bool ans;
	string s1;
	while(getline(cin,s1)&&s1.size()!=0)
	{
		
		//cout<<"s1 is "<<s1<<'\n';
		cout<<"Case "<<count++<<":\n";
		cin>>tmp;
		while(tmp--)
		{
			ans=false;
			cin>>a>>b;
			x=0;
			if(a>b)
				swap(a,b);
			for(int i=a;i<=b;i++)
			{
				if(s1[i]=='1')
					x++;
			}
			if(x==0||x==b-a+1)
				ans=true;
			//cout<<"x= "<<x<<endl;
			if(ans)
				cout<<"Yes\n";
			else
				cout<<"No\n";
		}
		getchar();
	}
	
	
	return 0;
 } 
