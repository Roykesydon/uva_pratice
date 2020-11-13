#include <bits/stdc++.h>
using namespace std;
vector<pair<string, string>> arr;
vector<string> ans;
class cmp
{
public:
	bool operator()(pair<string,string> a,pair<string,string> b)
	{
		if(a.first.size()!=b.first.size())
			return a.first.size()>b.first.size();
		else
			return a.first>b.first;
	}
	bool operator()(string a,string b)
	{
		if(a.size()!=b.size())
			return a.size()>b.size();
		else
			return a>b;
	}
};
string str_add(string a, string b)
{
	if (b.size() >= a.size())
		swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0;
	int carry = 0;
	for (int i = 0; i < b.size(); i++)
		a[i] += b[i] - '0';
	for (int i = 0; i < a.size(); i++)
	{
		a[i] += carry;
		carry = 0;
		if (a[i] > '9')
		{
			a[i] -= 10;
			carry = 1;
		}
	}
	if (carry > 0)
		a +='1';
		reverse(a.begin(),a.end());
	return a;
}
int main()
{
	int n;
	string tar;
	cin >> n >> tar;
	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;
	sort(arr.begin(), arr.end(),cmp());
	string now = "0";
	for (int i = 0; i <n; i++)
	{
		//cerr << "add " << now << " and " << arr[i].first << " = " << str_add(now, arr[i].first) << '\n';
		if (cmp()(str_add(now, arr[i].first),tar))
			continue;
		now = str_add(now, arr[i].first);
		ans.push_back(arr[i].second);
	}
	if (now == tar)
	{
		cout << ans.size()<<'\n';
		for (auto i : ans)
			cout << i << '\n';
	}
	else
		cout << "0\n";
	return 0;
}
