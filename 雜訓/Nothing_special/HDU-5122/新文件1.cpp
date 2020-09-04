#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,n,ans;
	cin>>t;
	for(int cas=1;cas<=t;cas++){
		cin>>n; 
		arr.clear();
		arr.resize(n);
		for(int i=0;i<n;i++)
			cin>>arr[i];
		ans=0;
		for(int i=n-1;i>=1;i--){
			if(arr[i-1]>arr[i]){
				ans++;
				arr[i-1]=arr[i];
			}
		}
		cout<<"Case #"<<cas<<": "<<ans<<'\n';
	}
	return 0;
}
