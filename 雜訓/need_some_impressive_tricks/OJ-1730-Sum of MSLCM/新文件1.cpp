#include<iostream>
using namespace std;
int main()
{
	long long int a;
	long long int L,R,times;
	long long int ans;
	while(cin>>a&&a!=0)
	{
		ans=0;
		L=1;
		while(L<=a)	//令人印象深刻，關鍵在於轉換MSLCM成單獨看小於目標的每個數的出現次數，並且這有遞減的情形，可以找到右界，用等差級數公式快速計算 
		{
			times=a/L;
			R=a/times;
			ans+=(times*((L+R)*(R-L+1)/2));
			L=R+1;
		}
		cout<<ans-1<<endl;
	}
	return 0;
} 
