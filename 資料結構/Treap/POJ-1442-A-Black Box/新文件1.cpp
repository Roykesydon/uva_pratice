#include <iostream>
#include <vector>
#include <cstdlib>
#include<deque>
using namespace std;
vector<int>arr;
deque<int>deq;
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
void split(Treap *cur,int k,Treap *&a,Treap *&b)
{
	if(!cur)
	{
		a=b=NULL;
		return ;
	}
	//push(cur);
	if(k<=cur->val)
	{
		b=cur;
		split(cur->l,k,a,b->l);
		pull(b);
	}
	else
	{
		a=cur;
		split(cur->r,k,a->r,b);
		pull(a);
	}
	
}
void insert(int k,Treap *&root)
{
	Treap *mid= new Treap(k);
	Treap*l,*r;
	split(root,k,l,r);
	//cerr<<"Size(l)= "<<Size(l)<<"Size(r)= "<<Size(r)<<'\n';
	root = merge(merge(l,mid),r);
	//cerr<<"Size(root)= "<<Size(root)<<'\n';
	//root=merge(l,merge(mid,r));
}
int getValue(int kth,Treap*&root)
{
	Treap *l,*r,*mid,*ans;
	kth_split(root,kth-1,l,mid);
	kth_split(mid,1,ans,r);
	// if(l!=NULL)cerr<<"l->val = "<<l->val<<'\n';
	// if(r!=NULL)cerr<<"r->val = "<<r->val<<'\n';
	root=merge(l,merge(ans,r));
	return ans->val;
}

int main()
{
	int m,n,tmp,cnt=1;
	Treap*root=NULL;
	cin>>m>>n;
	arr.resize(m+1);
	for(int i=1;i<=m;i++)
		cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		if(tmp>m)
			tmp=m;
		deq.push_back(tmp);
	}
	for(int i=1;i<=m;i++)
	{
		insert(arr[i],root);
		//cerr<<"Size(root)= "<<Size(root)<<'\n';
		while(deq.front()==i)
		{
			cout<<getValue(cnt++,root)<<'\n';
			deq.pop_front();
		}
	}
	
	return 0;
}
