#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)
class node {
public:
	int l;
	int r;
	int id;
	int blk_id;
	friend bool operator<(node a, node b) {
		if (a.blk_id!=b.blk_id)
			return a.blk_id<b.blk_id;
		if (a.blk_id&1)
			return a.r>b.r;
		return a.r<b.r;
	}
};
vector<int>arr;
vector<int>arr2;
vector<node>que;
vector<int>id;
vector<int>bit;
vector<int>bit2;
int tmp;
int tmp_ans;
vector<int>ans;
void modify(int index, int value, int id) {
	if (id==1)
		while (index<=bit.size()) {
			bit[index]+=value;
			index+=lowbit(index);
		}
	else
		while (index<=bit.size()) {
			bit2[index]+=value;
			index+=lowbit(index);
		}
}
int query(int index, int id) {
	int tmp=0;
	if (id==1)
		while (index) {
			tmp+=bit[index];
			index-=lowbit(index);
		}
	else
		while (index) {
			tmp+=bit2[index];
			index-=lowbit(index);
		}
	return tmp;
}
void add(int x, int id) {
	if (id==2) 
		tmp_ans+=query(arr[x]-1, 1);
	else 
		tmp_ans+=query(arr2[x]-1, 2);
	modify(arr[x], 1, 1);
	modify(arr2[x], 1, 2);
}
void sub(int x, int id) {
	if (id==2) 
		tmp_ans-=query(arr[x]-1, 1);
	else 
		tmp_ans-=query(arr2[x]-1, 2);
	modify(arr[x], -1, 1);
	modify(arr2[x], -1, 2);
}
void mo() {
	int l=0, r=-1;
	tmp_ans=0;
	for (int i=0;i<que.size();i++) {
		while (que[i].r>r)
			add(++r, 2);
		while (que[i].r<r)
			sub(r--, 2);
		while (que[i].l<l)
			add(--l, 1);
		while (que[i].l>l)
			sub(l++, 1);
		ans[que[i].id]=tmp_ans;
	}
}
int main() {
	int q, n, blk_size;
	cin>>n;
	blk_size=sqrt(n);
	arr.resize(n);
	for (int i=0;i<n;i++)
		cin>>arr[i];
	id=arr;
	arr2=arr;
	sort(id.begin(), id.end());
	id.resize(unique(id.begin(), id.end())-id.begin());
	for (int i=0;i<n;i++)
		arr2[i]=lower_bound(id.begin(), id.end(), arr[i])-id.begin()+1;
	for (int i=0;i<n;i++)
		arr[i]=id.size()-(lower_bound(id.begin(), id.end(), arr[i])-id.begin());
	bit.resize(id.size()+1, 0);
	bit2.resize(id.size()+1, 0);

	cin>>q;
	ans.resize(q);
	que.resize(q);
	for (int i=0;i<q;i++) {
		cin>>que[i].l>>que[i].r;
		que[i].l--;que[i].r--;
		que[i].id=i;
		que[i].blk_id=que[i].l/blk_size;
	}
	sort(que.begin(), que.end());
	mo();
	for (int i=0;i<ans.size();i++)
		cout<<ans[i]<<'\n';
	return 0;
}
