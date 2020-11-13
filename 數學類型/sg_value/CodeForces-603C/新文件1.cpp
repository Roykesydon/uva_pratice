#include<bits/stdc++.h>
using namespace std;
int n, k, tmp;
int sg_value(int x) {
	if(x==0)return 0;
	if (k&1) {
		if (x==2)return 0;
		else if(x==1)return 1;
		else if (x==3)return 1;
		else if (x==4)return 2;
		else if(x==5)return 0;
		else if(x==7)return 0;
		else if(x==6)return 2;
		else if(x==8)return 1;
		else if ((x&1))return 0;
		else return (sg_value(x/2)==1)?2:1;
	}
	else {
		if (x==1)return 1;
		else if (x==2)return 2;
		else if (!(x&1))return 1;
		else return 0;
	}
}

int main() {
	cin>>n>>k;
	int ans=0;
	for (int i=0;i<n;i++) {
		cin>>tmp;
		ans^=sg_value(tmp);
	}
	if (!ans)
		cout<<"Nicky\n";
	else
		cout<<"Kevin\n";
	return 0;
}
