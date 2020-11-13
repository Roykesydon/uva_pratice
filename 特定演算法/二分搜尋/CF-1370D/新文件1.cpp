#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
int n,m;
bool check(int x){
	int cnt=0;
	for(int i=0;i<n;i++)
		if(cnt&1){
			if(arr[i]<=x)
				cnt++;
		}
		else
			cnt++;
	if(cnt>=m)return 1;
	cnt=0;
	for(int i=0;i<n;i++)
		if(!(cnt&1)){
			if(arr[i]<=x)
				cnt++;
		}
		else
			cnt++;
	if(cnt>=m)return 1;
	return 0;
}
int main(){
	int l=0,r=1e9+1;
	cin>>n>>m;
	arr.resize(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<r<<'\n';
	return 0;
}
