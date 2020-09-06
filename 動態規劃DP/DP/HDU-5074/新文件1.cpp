#include<bits/stdc++.h>
using namespace std;
vector<vector<int> >arr,dp;
vector<int>vec;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,n,m,maxn;
	cin>>t;
	while(t--){
		cin>>n>>m;
		
		arr.clear();
		arr.resize(m+1);
		for(int i=0;i<=m;i++)
			arr[i].resize(m+1);
			
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				cin>>arr[i][j];
				
		vec.clear();
		vec.resize(n+1);
		for(int i=1;i<=n;i++)
			cin>>vec[i];
			
		dp.clear();
		dp.resize(n+1);
		for(int i=0;i<=n;i++)
			dp[i].resize(m+1,-1);
		if(vec[1]==-1)
			for(int i=1;i<=m;i++)
				dp[1][i]=0;
		else{
			dp[1][vec[1]]=0;
				
		}
		for(int i=2;i<=n;i++){
			if(vec[i]==-1){
				for(int j=1;j<=m;j++){
					if(dp[i-1][j]!=-1)
						for(int k=1;k<=m;k++){
							dp[i][k]=max(dp[i][k],dp[i-1][j]+arr[j][k]);
						}
				}	
			}
			else{
				for(int j=1;j<=m;j++){
					if(dp[i-1][j]!=-1)
					dp[i][vec[i]]=max(dp[i][vec[i]],dp[i-1][j]+arr[j][vec[i]]);
				}	
			}
		}
		maxn=0;
		for(int i=1;i<=m;i++)
			maxn=max(maxn,dp[n][i]);
		cout<<maxn<<'\n';
	}
	
	return 0;
}
