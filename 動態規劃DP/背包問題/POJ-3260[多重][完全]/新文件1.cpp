#include<iostream>
#include<cstring>
using namespace std;
int dp1[25000+1],dp2[25000+1];
int v[101],c[101];
int n,t,minn;
void mutbp(int i){
	//cout<<"mul_i = "<<i<<'\n';
	int sum=1;
	int k=1;
	while(sum<c[i]){
		for(int j=25000;j>=v[i]*k;j--)
			dp1[j]=min(dp1[j],dp1[j-v[i]*k]+k);
		//cout<<"sum= "<<sum<<'\n';
		k*=2;
		sum+=k;
	}
	sum-=k;
	//cout<<"(c[i]-sum)= "<<(c[i]-sum)<<'\n';
	for(int j=25000;j>=v[i]*(c[i]-sum);j--)
		dp1[j]=min(dp1[j],dp1[j-v[i]*(c[i]-sum)]+(c[i]-sum));
}
void combp(int i){
	for(int j=v[i];j<=25000;j++)
		dp2[j]=min(dp2[j],dp2[j-v[i]]+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>t;
	for(int i=0;i<n;i++)
		cin>>v[i];
	for(int i=0;i<n;i++)
		cin>>c[i];
	memset(dp1,0x3f,sizeof(dp1));
	memset(dp2,0x3f,sizeof(dp2));
	dp1[0]=0;dp2[0]=0;
	for(int i=0;i<n;i++){
		mutbp(i);
		combp(i);
	}
	// for(int i=0;i<=10;i++)
	// 	cout<<"dp1["<<i<<"]= "<<dp1[i]<<'\n';
	// for(int i=0;i<=5;i++)
	// 	cout<<"dp2["<<i<<"]= "<<dp2[i]<<'\n';
	minn=0x3f3f3f3f;
	for(int i=t;i<=25000;i++){
		//minn=min(minn,dp1[i]+dp2[i-t]);
		if(dp1[i]+dp2[i-t]<minn){
			minn=dp1[i]+dp2[i-t];
			//cout<<"dp1["<<i<<"]= "<<dp1[i]<<' '<<"dp2["<<i-t<<"]= "<<dp2[i-t]<<'\n';
		}
	}

	if(minn==0x3f3f3f3f)
		cout<<-1<<'\n';
	else
		cout<<minn<<'\n';
	return 0;
}
/*
4 10
1 2 3 4
10 10 10 10
*/
