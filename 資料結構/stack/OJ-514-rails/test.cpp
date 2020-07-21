#include <iostream>
#include <stack>
#include <algorithm>
int a[1001];
using namespace std;
int main()
{
	int n;
	int count=0;
	int i,j;
	stack<int>st;
	while(cin>>n)
	{
		if(count++)
			cout<<endl;
		while(cin>>a[0]&&a[0])
		{
			for(int i=1;i<n;i++)
				cin>>a[i];
			/*
			for(int i=0;i<n;i++)
				cout<<a[i]<<' ';
			*/
			
			j=0;
			i=0;
			st.push(++j);
			//cout<<st.top();
			while(1)
			{				
				if(st.empty()&&j<n)
					st.push(++j);
				while(st.top()!=a[i]&&j<n)
					st.push(++j);

				if(st.top()==a[i])
				{
					st.pop();
					i++;
				}
				else
					break;
				if(st.empty()&&j>=n)
					break;
			}
			if(i==n)
				cout<<"Yes\n";
			else
				cout<<"No\n";
			while(!st.empty())
				st.pop();
		}

		
	}
	return 0;
}