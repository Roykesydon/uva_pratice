#include<bits/stdc++.h>
using namespace std;
vector<int>f;
vector<int>sg;
int mex(vector<int>a){
	sort(a.begin(),a.end());
	a.resize(unique(a.begin(),a.end())-a.begin());
	for(int i=0;i<=a.size();i++){
		if(i==a.size())return i;
		if(a[i]!=i)return i;
	}
}
int sg_value(int x){
	vector<int>tmp;
	if(sg[x]!=-1)
		return sg[x];
	for(int i=1;f[i]<=x;i++){
		tmp.push_back(sg_value(x-f[i]));
	}
	return sg[x]=mex(tmp);
}
int main(){
	f.resize(20);
	int m,n,p;
	f[0]=0;
	f[1]=1;
	for(int i=2;i<20;i++)
		f[i]=f[i-1]+f[i-2];
	sg.resize(1000+1,-1);
	sg[0]=0;
	sg_value(1000);
	while(cin>>m>>n>>p&&(m||n||p))
		if(sg[m]^sg[n]^sg[p])cout<<"Fibo\n";
		else cout<<"Nacci\n";
	return 0;
}

