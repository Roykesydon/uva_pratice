#include<bits/stdc++.h>
using namespace std;
class query {
public:
	int ql;
	int qr;
	int id;
	int blk_id;
	friend bool operator<(query a, query b) {
		if (a.blk_id!=b.blk_id)
			return a.blk_id<b.blk_id;
		if (a.blk_id&1)
			return a.qr>b.qr;
		return a.qr<b.qr;
	}
};
map<int, int>mp;
vector<int>arr;
vector<query>que;
vector<int> ans;
int dif;
void add(int x) {
	//cerr<<"add "<<arr[x]<<"\n";
	if (++mp[arr[x]]==1)
		dif++;
}
void sub(int x) {
	//cerr<<"sub "<<arr[x]<<"\n";
	if (--mp[arr[x]]==0)
		dif--;
}
void mo() {
	dif=0;
	int l=0, r=-1;
	for (int i=0;i<que.size();i++) {
		//cerr<<"i= "<<i<<'\n';
		while (que[i].qr>r) {
			add(++r);
		}
		while (que[i].qr<r) {
			sub(r--);
		}
		while (que[i].ql>l) {
			sub(l++);
		}
		while (que[i].ql<l) {
			add(--l);
		}
		ans[que[i].id]=dif;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, l, r;
	int blk_size;
	cin>>n;
	blk_size=sqrt(n);
	arr.resize(n);
	for (int i=0;i<n;i++)
		cin>>arr[i];
	cin>>m;
	que.resize(m);
	ans.resize(m);
	for (int i=0;i<m;i++) {
		cin>>l>>r;
		l--;r--;
		que[i].ql=l;
		que[i].qr=r;
		que[i].id=i;
		que[i].blk_id=que[i].ql/blk_size;
	}
	sort(que.begin(), que.end());
	mo();
	for (auto i:ans) {
		cout<<i<<'\n';
	}
	return 0;
}
