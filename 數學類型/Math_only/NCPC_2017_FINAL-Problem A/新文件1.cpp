#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long ans;
bool prime[200000];
void build()
{
	for (int i = 0; i < 200000; i++)
		if (prime[i])
			for (int j = i + i; j < 200000; j += i)
				prime[j] = 0;
}
void DFS(long long n)
{
	//cerr << "DFS(" << n << ") \n";
	set<long long> myset;
	long long tmp = n;
	ll i = 1, cnt = 0;
	while (1)
	{
		if (tmp == 1)
			break;
		i++;
		if (i > (ll)sqrt(tmp) && tmp != 1)
		{
			myset.insert(tmp);
			break;
		}

		//cerr << "i= " << i << endl;

		if (prime[i] && tmp % i == 0)
		{
			myset.insert(i);
			tmp /= i;
			i--;
			// cerr << "trigger i=" << i + 1 << endl;
			// cerr << "now tmp=" << tmp << endl;
		}
	}
	// for (auto i : myset)
	// 	cerr << i << ' ';
	// cerr << endl;
	if (myset.size()==1)
	{
		ans = *myset.begin();
		return;
	}
	else
	{
		long long sum = 0;
		for (auto i : myset)
			sum += i;
		DFS(sum);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	long long n;
	for (int i = 0; i < 200000; i++)
		prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;
	build();
	// for(int i=0;i<200000;i++)
	// 	if(prime[i])cerr<<i<<' ';
	while (t--)
	{
		cin >> n;
		DFS(n);
		cout << ans << '\n';
	}

	return 0;
}
