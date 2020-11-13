#include<iostream>
using namespace std;
int main()
{
	int s,a,b,c,sum;
	while(cin>>s>>a>>b>>c)
	{
		sum=360/3;
		if(s+a+b+c==0)
			break;
		sum+=((s-a)+40)%40;
		sum+=((b-a)+40)%40;
		sum+=((b-c)+40)%40;
		cout<<sum*9<<endl;
	}

	return 0;
}