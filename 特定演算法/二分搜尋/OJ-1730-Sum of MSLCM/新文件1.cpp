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
		while(L<=a)	//�O�H�L�H�`��A����b���ഫMSLCM����W�ݤp��ؼЪ��C�Ӽƪ��X�{���ơA�åB�o��������ΡA�i�H���k�ɡA�ε��t�żƤ����ֳt�p�� 
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
