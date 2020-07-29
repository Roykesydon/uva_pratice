#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x & -x)
vector<int> arr;
int minn,maxn;
struct Treap
{
	int sz, val, pri, tag;
	Treap *l, *r;
	Treap(int _val)
	{
		val = _val;
		sz = 1;
		pri = rand();
		l = r = NULL;
		tag = 0;
	}
};
Treap *root = NULL;
vector<Treap *> bit;
void push(Treap *a)
{
	if (a->tag)
	{
		Treap *swp = a->l;
		a->l = a->r;
		a->r = swp;
		int swp2;
		if (a->l)
			a->l->tag ^= 1;
		if (a->r)
			a->r->tag ^= 1;
		a->tag = 0;
	}
}
int Size(Treap *a) { return a ? a->sz : 0; }
void pull(Treap *a)
{
	a->sz = Size(a->l) + Size(a->r) + 1;
}
Treap *merge(Treap *a, Treap *b)
{
	if (!a || !b)
		return a ? a : b;
	if (a->pri > b->pri)
	{
		push(a);
		a->r = merge(a->r, b);
		pull(a);
		return a;
	}
	else
	{
		push(b);
		b->l = merge(a, b->l);
		pull(b);
		return b;
	}
}
void kth_split(Treap *t, int k, Treap *&a, Treap *&b)
{
	if (!t)
	{
		a = b = NULL;
		return;
	}
	push(t);
	if (Size(t->l) + 1 <= k)
	{
		a = t;
		kth_split(t->r, k - Size(t->l) - 1, a->r, b);
		pull(a);
	}
	else
	{
		b = t;
		kth_split(t->l, k, a, b->l);
		pull(b);
	}
}
void split(Treap *cur, int k, Treap *&a, Treap *&b)
{
	if (!cur)
	{
		a = b = NULL;
		return;
	}
	//push(cur);
	if (k <= cur->val)
	{
		b = cur;
		split(cur->l, k, a, b->l);
		pull(b);
	}
	else
	{
		a = cur;
		split(cur->r, k, a->r, b);
		pull(a);
	}
}
void insert(int k, Treap *&root)
{
	Treap *mid = new Treap(k);
	Treap *l, *r;
	split(root, k, l, r);
	//cerr<<"Size(l)= "<<Size(l)<<"Size(r)= "<<Size(r)<<'\n';
	root = merge(merge(l, mid), r);
	//cerr<<"Size(root)= "<<Size(root)<<'\n';
	//root=merge(l,merge(mid,r));
}
int getValue(int kth, Treap *&root)
{
	Treap *l, *r, *mid, *ans;
	kth_split(root, kth - 1, l, mid);
	kth_split(mid, 1, ans, r);
	// if(l!=NULL)cerr<<"l->val = "<<l->val<<'\n';
	// if(r!=NULL)cerr<<"r->val = "<<r->val<<'\n';
	root = merge(l, merge(ans, r));
	return ans->val;
}
void modify(int index, int value)
{
	while (index < arr.size())
	{
		insert(value, bit[index]);
		index += lowbit(index);
	}
}
int query(int index, int search_value)
{
	int small_size = 0;
	//cerr<<"query...\n";
	while (index)
	{
		Treap *l, *r;
		split(bit[index], search_value, l, r);
		small_size += Size(l);
		//cerr<<"small_size= "<<small_size<<'\n';
		bit[index] = merge(l, r);
		index-=lowbit(index);
	}
	return small_size;
}
bool check(int mid, int kth, int ql, int qr)
{
	// cerr<<" ql= "<<ql<<" qr= "<<qr<<'\n';
	// cerr<<"query(qr, mid)= "<<query(qr, mid);
	if (ql != 1)
	{
		// cerr<<" query(ql-1,mid) = "<<query(ql-1,mid);
		// cerr<<'\n';
		if (query(qr, mid)-query(ql-1,mid)<=kth-1)
			return true;
		return false;
	}
	else
	{
		// cerr<<'\n';
		if(query(qr,mid)<=kth-1)
			return true;
		return false;
	}
}
void search(int ql, int qr, int k)
{
	int l = minn;
	int r = maxn;
	int mid;
	while (l < r)
	{
		mid = (l + r+1) / 2;
		//if(l<0&&r<0)mid=(l+r-1)/2;
		//cerr<<" l= "<<l<<" r = "<<r<<" mid= "<<mid<<'\n';
		if (check(mid, k, ql, qr))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout<<l<<'\n';
}
int main()
{
	int n, m;
	int l, r, k;
	minn=1e9+1;
	maxn=-1e9-1;
	while (cin >> n >> m)
	{
		arr.resize(n + 1);
		bit.resize(n + 1, NULL);
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			minn=min(minn,arr[i]);
			maxn=max(maxn,arr[i]);
			modify(i, arr[i]);
		}
		for (int i = 0; i < m; i++)
		{
			cin >> l >> r >> k;
			search(l, r, k);
		}

		bit.clear();
		arr.clear();
	}

	return 0;
}
