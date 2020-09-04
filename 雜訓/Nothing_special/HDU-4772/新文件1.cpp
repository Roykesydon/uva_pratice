#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
int arr[3][MAXN+1][MAXN+1];
int n,ans;
void rotate(){
	int tmp=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			arr[2][j][n-i+1]=arr[0][i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			arr[0][i][j]=arr[2][i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(arr[0][i][j]==arr[1][i][j])
				tmp++;
	ans=max(ans,tmp);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n&&n){
		for(int i=0;i<2;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++)
					cin>>arr[i][j][k];
			}
		}
		ans=0;
		for(int i=0;i<4;i++)
			rotate();
		cout<<ans<<'\n';
	}

	return 0;
}
