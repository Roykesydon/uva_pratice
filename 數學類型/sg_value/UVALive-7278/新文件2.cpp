#include<bits/stdc++.h>
using namespace std;
vector<int>sg;
vector<int>arr;
int mex[1000+1];
int p, k, n;
int sg_value() {
	int tmp;
	sg.clear();sg.resize(n+1,0);
	for (int i=1;i<=n;i++) {
		memset(mex, 0, sizeof(mex));
		for (int j=0;j<=k;j++) {
			if (j>=i)continue;
			if ((i-j)-arr[i-j-1]>=0)
				mex[sg[(i-j)-arr[i-j-1]]]++;
		}
		tmp=0;
		while (mex[tmp])tmp++;
		sg[i]=tmp;
	}
	return sg[n];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans, x;
	while (cin>>p>>k) {
		ans=0;
		for (int i=0;i<p;i++) {
			cin>>n;
			arr.clear();arr.resize(n);
			for (int j=0;j<n;j++) 
				cin>>arr[j];
			ans^=sg_value();
		}
		if (ans)cout<<"Alice can win.\n";
		else cout<<"Bob will win.\n";
	}
	return 0;
}
