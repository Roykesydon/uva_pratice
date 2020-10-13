#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) (x & -x)
class cmp
{
public:
	bool operator()(ll a, ll b)
	{
		return a > b;
	}
};
vector<ll> BIT;
vector<ll> vec;
vector<ll> cnt;
int n;
ll query(int index)
{
	ll ans = 0;
	while (index)
	{
		ans += BIT[index];
		index -= lowbit(index);
	}
	return ans;
}
void modify(int index, int value)
{
	while (index <= n)
	{
		BIT[index] += value;
		index += lowbit(index);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int m;
	int ql, qr;
	ll ans;
	while (cin >> n >> m)
	{
		vec.resize(n);
		BIT.resize(n + 1, 0);
		cnt.resize(n);
		for (int i = 0; i < n; i++)
			cin >> vec[i];
		for (int i = 0; i < m; i++)
		{
			cin >> ql >> qr;
			modify(ql, 1);
			if(qr!=n)
				modify(qr+ 1, -1);


		}

		for (int i = 1; i <= n; i++)
				cnt[i - 1] = query(i);

		sort(cnt.begin(), cnt.end(), cmp());
		sort(vec.begin(), vec.end(), cmp()); //其實沒必要由大到小，我不知道我在幹嘛
		ans = 0;
		for (int i = 0; i < n; i++)
			ans += cnt[i] * vec[i];
		cout << ans << '\n';

		cnt.clear();
		BIT.clear();
		vec.clear();
	}

	return 0;
}
