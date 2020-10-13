#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a,b,c;
	ll tmp,ans;
	while(cin>>a>>b>>c){
		tmp=0;
		ans=0;
		if(a){
			ans+=tmp;
			tmp++;
			a--;
		}
		if(b){
			ans+=tmp;
			tmp++;
			b--;
		}
		if(c){
			ans+=tmp;
			tmp++;
			c--;
		}
		if(a){
			ans+=tmp;
			tmp++;
			a--;
		}
		if(b){
			ans+=tmp;
			tmp++;
			b--;
		}
		if(c){
			ans+=tmp;
			tmp++;
			c--;
		}
		ans+=a*tmp;
		ans+=b*tmp;
		ans+=c*tmp;
		cout<<ans<<'\n';
	}
	
	return 0;
}
